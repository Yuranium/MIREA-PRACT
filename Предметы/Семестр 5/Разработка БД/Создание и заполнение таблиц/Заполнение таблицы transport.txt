INSERT INTO current.transport(transport_name, is_active, average_speed, id_type)
VALUES('Mercedes Sprinter', 'yes'::boolean, 85.20, 1),
('Talgo 250', 'yes'::boolean, 145.50, 4),
('Fiat Ducato', 'no'::boolean, 62.21, 20),
('Siemens ES64U', 'yes'::boolean, 230.00, 8),
('MAN TGX', 'yes'::boolean, 90.00, 13),
('Maersk Triple-E', 'yes'::boolean, 22.50, 14),
('Boeing 747-400', 'no'::boolean, 915.00, 11),
('Renault Trafic', 'yes'::boolean, 75.00, 13),
('Bombardier Zefiro', 'yes'::boolean, 320.00, 16),
('Scania R730', 'yes'::boolean, 95.00, 19),
('Emma Maersk', 'yes'::boolean, 31.00, 14),
('Airbus A380', 'yes'::boolean, 915.00, 11),
('Volkswagen Crafter', 'yes'::boolean, 80.00, 5),
('Shinkansen N700', 'yes'::boolean, 320.00, 12),
('Seawise Giant', 'no'::boolean, 16.00, 2),
('Boeing 787 Dreamliner', 'yes'::boolean, 915.00, 3),
('Mercedes Actros', 'yes'::boolean, 90.00, 1),
('Frecciarossa 1000', 'yes'::boolean, 320.00, 16),
('Queen Mary 2', 'yes'::boolean, 30.00, 18),
('Airbus A350 XWB', 'yes'::boolean, 915.00, 11);

SELECT * FROM current.transport;