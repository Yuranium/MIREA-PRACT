INSERT INTO current.tea_party(date_of_collection, tea_quantity, batch_price, id_delivery)
VALUES(current_date, 100, 2500.00, 12),
('24-03-2023'::date, 1000, 20000.25, 1),
('24-01-2023'::date, 1000, 20000.25, 11),
('25-03-2023'::date, 800, 18000.50, 9),
('26-03-2023'::date, 1200, 22000.75, 3),
('27-04-2023'::date, 900, 19000.00, 11),
('28-03-2023'::date, 1100, 21000.50, 14),
('29-03-2023'::date, 950, 19500.25, 1),
('30-07-2023'::date, 1050, 20500.75, 8),
('31-03-2023'::date, 1000, 20000.00, 8),
(current_date, 100, 2500, 12);

SELECT * FROM current.tea_party;