CREATE OR REPLACE FUNCTION current.average_salary()
RETURNS TRIGGER AS
$$
BEGIN
    INSERT INTO current.average_salaries(average_salary, last_updated)
	VALUES((SELECT AVG(salary) FROM current.employee), current_timestamp);
	RETURN NEW;
END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER update_average_salary
AFTER INSERT ON current.employee
FOR EACH ROW
EXECUTE FUNCTION current.average_salary()


CREATE OR REPLACE FUNCTION current.saving_deleted_customers()
RETURNS TRIGGER AS
$$
DECLARE
    schema_exists boolean;
    table_exists boolean;
BEGIN
    SELECT EXISTS ( -- проверка существования схемы с конкретным именем
        SELECT 1 
        FROM pg_catalog.pg_namespace 
        WHERE nspname = 'temp'
    ) INTO schema_exists;

    IF NOT schema_exists THEN
        CREATE SCHEMA temp;
    END IF;

    SELECT EXISTS ( -- проверка существования таблицы в схеме
        SELECT 1
        FROM pg_catalog.pg_class c
        INNER JOIN pg_namespace n ON n.oid = c.relnamespace
        WHERE n.nspname = 'temp'
        AND c.relname = 'customer_delete'
        AND c.relkind = 'r'
    ) INTO table_exists;

    IF NOT table_exists THEN
	CREATE TABLE temp.customer_delete (
		id_customer bigint PRIMARY KEY,
    	phone varchar(15) NOT NULL,
    	name varchar(50) NOT NULL,
    	surname varchar(50) NOT NULL,
    	middle_name varchar,
    	gender varchar(5) CHECK(gender IN('Man', 'Woman')) NOT NULL,
		date_remove_customer timestamp with time zone DEFAULT current_timestamp
	);
    END IF;
	INSERT INTO temp.customer_delete
	(id_customer, phone, name, surname, middle_name, gender, date_remove_customer)
	VALUES(OLD.id_customer, OLD.phone, OLD.name, OLD.surname, OLD.middle_name,
		   OLD.gender, current_timestamp);
	RETURN OLD;
END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER save_delete_customer
BEFORE DELETE ON current.customer
FOR EACH ROW
EXECUTE FUNCTION current.saving_deleted_customers()


CREATE OR REPLACE FUNCTION current.saving_deleted_tea_parties()
RETURNS TRIGGER AS
$$
DECLARE
    schema_exists boolean;
    table_exists boolean;
BEGIN
    SELECT EXISTS ( -- проверка существования схемы с конкретным именем
        SELECT 1 
        FROM pg_catalog.pg_namespace 
        WHERE nspname = 'temp'
    ) INTO schema_exists;

    IF NOT schema_exists THEN
        CREATE SCHEMA temp;
    END IF;

    SELECT EXISTS ( -- проверка существования таблицы в схеме
        SELECT 1
        FROM pg_catalog.pg_class c
        INNER JOIN pg_namespace n ON n.oid = c.relnamespace
        WHERE n.nspname = 'temp'
        AND c.relname = 'tea_party_delete'
        AND c.relkind = 'r'
    ) INTO table_exists;

    IF NOT table_exists THEN
	CREATE TABLE temp.tea_party_delete (
		id_party bigint PRIMARY KEY,
		date_of_collection date DEFAULT current_date NOT NULL,
		tea_quantity integer CHECK(tea_quantity > 0) NOT NULL,
		batch_price numeric(10, 3) CHECK(batch_price > 0) NOT NULL,
		id_delivery bigint,
		date_remove_tea_party timestamp with time zone DEFAULT current_timestamp
	);
    END IF;
	INSERT INTO temp.tea_party_delete
	(id_party, date_of_collection, tea_quantity, batch_price,
	 id_delivery, date_remove_tea_party)
	VALUES(OLD.id_party, OLD.date_of_collection, OLD.tea_quantity,
		   OLD.batch_price,OLD.id_delivery, OLD.date_remove_tea_party,
		   current_timestamp);
	RETURN OLD;
END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER save_delete_tea_party
BEFORE DELETE ON current.tea_party
FOR EACH ROW
EXECUTE FUNCTION current.saving_deleted_tea_parties()


CREATE OR REPLACE FUNCTION current.limit_10_rows()
RETURNS TRIGGER AS
$$
BEGIN
	IF (SELECT COUNT(*) FROM temp.customer_delete) > 10 THEN
		DELETE FROM current.customer
		WHERE date_remove_customer =
		(SELECT MIN(date_remove_customer) FROM temp.customer_delete);
	END IF;
	RETURN NEW;
END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER limit_rows
BEFORE INSERT OR UPDATE ON temp.customer_delete
FOR EACH ROW
EXECUTE FUNCTION current.limit_10_rows()


CREATE OR REPLACE FUNCTION current.check_data_employee()
RETURNS TRIGGER AS
$$
BEGIN
	IF (OLD.name <> NEW.name OR OLD.surname <> NEW.surname
	OR OLD.middle_name <> NEW.middle_name OR
	OLD.post <> NEW.post OR OLD.salary <> NEW.salary) THEN
		RAISE NOTICE 'Данные успешно были обновлены!';

	ELSE RAISE EXCEPTION 'Введённые данные никак не изменились!';
	END IF;
	RETURN NEW;
END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER check_employee
BEFORE UPDATE ON current.employee
FOR EACH ROW
EXECUTE FUNCTION current.check_data_employee()