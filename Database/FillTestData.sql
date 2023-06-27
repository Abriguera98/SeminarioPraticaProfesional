INSERT INTO Usuarios (Usuario, Clave) VALUES
  ('admin', 'admin'),
  ('test', 'test');

INSERT INTO Voluntarios (DNI, Nombre, Apellido) VALUES
  ('1234567', 'Juan', 'Gómez'),
  ('2345678', 'María', 'Rodríguez'),
  ('3456789', 'Carlos', 'López'),
  ('4567890', 'Laura', 'Fernández'),
  ('5678901', 'Javier', 'González'),
  ('6789012', 'Ana', 'Martínez'),
  ('7890123', 'Pedro', 'Sánchez'),
  ('8901234', 'Sofía', 'Pérez'),
  ('9012345', 'Miguel', 'Torres'),
  ('0123456', 'Isabel', 'Ortega'),
  ('1192334', 'Alejandro', 'Navarro'),
  ('1233445', 'Carmen', 'Vargas'),
  ('3347556', 'Daniel', 'Ruiz'),
  ('4455767', 'Elena', 'Herrera'),
  ('5562778', 'José', 'Silva'),
  ('66778689', 'Lucía', 'Morales'),
  ('7798990', 'Diego', 'Ramírez'),
  ('8894001', 'Marina', 'Delgado'),
  ('9910112', 'Gabriel', 'Castillo'),
  ('0041123', 'Paula', 'Guerrero'),
  ('1122334', 'Fernando', 'Molina'),
  ('2233445', 'Valentina', 'Vega'),
  ('3344556', 'Andrés', 'Rojas'),
  ('4455667', 'Julia', 'Acosta'),
  ('5566778', 'Manuel', 'Peña'),
  ('6677889', 'Camila', 'Cabrera'),
  ('7788990', 'Luis', 'Soto'),
  ('8899001', 'Valeria', 'León'),
  ('9900112', 'Juan Pablo', 'Mendoza'),
  ('0001123', 'Daniela', 'Cruz');

INSERT INTO PerfilesPsicologicos (VoluntarioDNI, Activa) VALUES
  ('1234567', 1),
  ('2345678', 1),
  ('3456789', 0),
  ('4567890', 1),
  ('5678901', 0),
  ('6789012', 1),
  ('7890123', 0),
  ('8901234', 1),
  ('9012345', 0),
  ('0123456', 1),
  ('1122334', 1),
  ('2233445', 0),
  ('3344556', 1),
  ('4455667', 0),
  ('5566778', 1),
  ('6677889', 0),
  ('7788990', 1),
  ('8899001', 1),
  ('9900112', 0),
  ('0001123', 1);

INSERT INTO Entradas (Fecha, Descripcion, UsuarioID, PerfilID)
VALUES
('2020-01-02', 'Sesión de terapia para manejo del estrés', 1, 11),
('2020-02-15', 'Consulta inicial sobre ansiedad y estrés', 1, 8),
('2020-04-03', 'Seguimiento de tratamiento para depresión', 1, 2),
('2020-06-18', 'Terapia de pareja para mejorar la comunicación', 1, 11),
('2020-09-05', 'Sesión de relajación y manejo del estrés', 2, 19),
('2020-11-21', 'Tratamiento para superar fobias específicas', 2, 7),
('2021-01-10', 'Evaluación psicológica para orientación vocacional', 1, 16),
('2021-03-27', 'Terapia individual para mejorar la autoestima', 1, 14),
('2021-06-12', 'Seguimiento de tratamiento para trastorno de ansiedad', 2, 10),
('2021-08-29', 'Terapia familiar para resolver conflictos', 1, 4),
('2021-11-14', 'Consulta sobre técnicas de manejo del estrés', 2, 18),
('2022-01-23', 'Terapia de pareja para superar crisis', 1, 15),
('2022-04-09', 'Seguimiento de tratamiento para trastorno de sueño', 1, 6),
('2022-06-24', 'Sesión de relajación y mindfulness', 2, 3),
('2022-09-10', 'Terapia individual para manejo de la ira', 1, 9),
('2022-11-26', 'Consulta sobre técnicas de comunicación asertiva', 2, 12),
('2023-01-15', 'Terapia de pareja para mejorar la intimidad', 2, 17),
('2023-03-04', 'Seguimiento de tratamiento para trastorno de ansiedad', 1, 13),
('2023-05-20', 'Terapia familiar para resolver conflictos', 1, 20),
('2023-06-10', 'Consulta sobre técnicas de relajación', 2, 1),
('2023-06-15', 'Terapia individual para superar miedos y fobias', 1, 5),
('2020-02-05', 'Terapia individual para manejo de la ansiedad', 1, 7),
('2020-03-15', 'Consulta sobre técnicas de relajación', 2, 16),
('2020-04-25', 'Seguimiento de tratamiento para trastorno de sueño', 1, 3),
('2020-06-05', 'Terapia de pareja para mejorar la comunicación', 2, 14),
('2020-07-15', 'Consulta inicial sobre depresión', 1, 9),
('2020-08-25', 'Terapia familiar para resolver conflictos', 2, 17),
('2020-10-05', 'Sesión de relajación y manejo del estrés', 1, 10),
('2020-11-15', 'Seguimiento de tratamiento para trastorno de ansiedad', 2, 5),
('2020-12-25', 'Terapia individual para superar miedos y fobias', 1, 13),
('2021-02-05', 'Consulta sobre técnicas de comunicación asertiva', 2, 15),
('2021-03-15', 'Terapia de pareja para mejorar la intimidad', 1, 11),
('2021-04-25', 'Seguimiento de tratamiento para trastorno de sueño', 2, 19),
('2021-06-05', 'Terapia familiar para resolver conflictos', 1, 2),
('2021-07-15', 'Consulta inicial sobre ansiedad y estrés', 2, 8),
('2021-08-25', 'Terapia individual para manejo de la ira', 1, 20),
('2021-10-05', 'Seguimiento de tratamiento para depresión', 2, 4),
('2021-11-15', 'Terapia de pareja para superar crisis', 1, 12),
('2021-12-25', 'Consulta sobre técnicas de manejo del estrés', 2, 1),
('2022-02-05', 'Terapia individual para mejorar la autoestima', 1, 18),
('2022-03-15', 'Sesión de relajación y mindfulness', 2, 7),
('2020-02-05', 'Terapia individual para manejo de la ansiedad', 1, 5),
('2020-03-15', 'Consulta sobre técnicas de relajación', 2, 13),
('2020-04-25', 'Seguimiento de tratamiento para trastorno de sueño', 1, 10),
('2020-06-05', 'Terapia de pareja para mejorar la comunicación', 2, 1),
('2020-07-15', 'Consulta inicial sobre depresión', 1, 16),
('2020-08-25', 'Terapia familiar para resolver conflictos', 2, 8),
('2020-10-05', 'Sesión de relajación y manejo del estrés', 1, 6),
('2020-11-15', 'Seguimiento de tratamiento para trastorno de ansiedad', 2, 14),
('2020-12-25', 'Terapia individual para superar miedos y fobias', 1, 4),
('2021-02-05', 'Consulta sobre técnicas de comunicación asertiva', 2, 17),
('2021-03-15', 'Terapia de pareja para mejorar la intimidad', 1, 3),
('2021-04-25', 'Seguimiento de tratamiento para trastorno de sueño', 2, 11),
('2021-06-05', 'Terapia familiar para resolver conflictos', 1, 19),
('2021-07-15', 'Consulta inicial sobre ansiedad y estrés', 2, 2),
('2021-08-25', 'Terapia individual para manejo de la ira', 1, 12),
('2021-10-05', 'Seguimiento de tratamiento para depresión', 2, 9),
('2021-11-15', 'Terapia de pareja para superar crisis', 1, 20),
('2021-12-25', 'Consulta sobre técnicas de manejo del estrés', 2, 6),
('2022-02-05', 'Terapia individual para mejorar la autoestima', 1, 15),
('2022-03-15', 'Sesión de relajación y mindfulness', 2, 18),
('2022-04-25', 'Seguimiento de tratamiento para trastorno de ansiedad', 1, 7),
('2022-06-05', 'Terapia de pareja para mejorar la comunicación', 2, 16),
('2022-07-15', 'Consulta inicial sobre depresión', 1, 14),
('2022-08-25', 'Terapia familiar para resolver conflictos', 2, 3),
('2022-10-05', 'Sesión de relajación y manejo del estrés', 1, 8),
('2022-11-15', 'Seguimiento de tratamiento para trastorno de sueño', 2, 2),
('2022-12-25', 'Terapia individual para superar miedos y fobias', 1, 11),
('2023-02-05', 'Consulta sobre técnicas de comunicación asertiva', 2, 18),
('2023-03-15', 'Terapia de pareja para mejorar la intimidad', 1, 7),
('2023-04-25', 'Seguimiento de tratamiento para trastorno de sueño', 2, 11),
('2023-06-05', 'Terapia familiar para resolver conflictos', 1, 2),
('2023-07-15', 'Consulta inicial sobre ansiedad y estrés', 2, 5),
('2023-08-25', 'Terapia individual para manejo de la ira', 1, 16),
('2023-10-05', 'Seguimiento de tratamiento para depresión', 2, 14),
('2023-11-15', 'Terapia de pareja para superar crisis', 1, 13),
('2023-12-25', 'Consulta sobre técnicas de manejo del estrés', 2, 8),
('2024-02-05', 'Terapia individual para mejorar la autoestima', 1, 19),
('2024-03-15', 'Sesión de relajación y mindfulness', 2, 1),
('2024-04-25', 'Seguimiento de tratamiento para trastorno de ansiedad', 1, 4),
('2024-06-05', 'Terapia de pareja para mejorar la comunicación', 2, 10),
('2024-07-15', 'Consulta inicial sobre depresión', 1, 15),
('2024-08-25', 'Terapia familiar para resolver conflictos', 2, 9),
('2024-10-05', 'Sesión de relajación y manejo del estrés', 1, 6),
('2024-11-15', 'Seguimiento de tratamiento para trastorno de sueño', 2, 12),
('2024-12-25', 'Terapia individual para superar miedos y fobias', 1, 3),
('2025-02-05', 'Consulta sobre técnicas de comunicación asertiva', 2, 14),
('2025-03-15', 'Terapia de pareja para mejorar la intimidad', 1, 10),
('2025-04-25', 'Seguimiento de tratamiento para trastorno de sueño', 2, 16),
('2025-06-05', 'Terapia familiar para resolver conflictos', 1, 19),
('2025-07-15', 'Consulta inicial sobre ansiedad y estrés', 2, 7),
('2025-08-25', 'Terapia individual para manejo de la ira', 1, 12),
('2025-10-05', 'Seguimiento de tratamiento para depresión', 2, 6),
('2025-11-15', 'Terapia de pareja para superar crisis', 1, 3),
('2025-12-25', 'Consulta sobre técnicas de manejo del estrés', 2, 5),
('2020-01-02', 'Sesión de terapia para manejo del estrés', 1, 17),
('2020-02-10', 'Consulta sobre técnicas de comunicación asertiva', 2, 2),
('2020-03-18', 'Terapia individual para mejorar la autoestima', 1, 5),
('2020-04-26', 'Sesión de relajación y mindfulness', 2, 16),
('2020-06-03', 'Seguimiento de tratamiento para ansiedad', 1, 19),
('2020-07-11', 'Terapia de pareja para mejorar la intimidad', 2, 4),
('2020-08-19', 'Consulta inicial sobre trastornos del sueño', 1, 7),
('2020-09-27', 'Terapia familiar para resolver conflictos', 2, 13),
('2020-11-04', 'Sesión de relajación y manejo del estrés', 1, 3),
('2020-12-12', 'Seguimiento de tratamiento para depresión', 2, 9),
('2021-01-19', 'Terapia individual para superar miedos y fobias', 1, 14),
('2021-02-27', 'Consulta sobre técnicas de manejo de la ira', 2, 10),
('2021-04-06', 'Terapia de pareja para superar crisis', 1, 18),
('2021-05-14', 'Sesión de relajación y mindfulness', 2, 15),
('2021-06-21', 'Seguimiento de tratamiento para trastornos del sueño', 1, 12),
('2021-07-29', 'Consulta inicial sobre ansiedad y estrés', 2, 6),
('2021-09-06', 'Terapia individual para mejorar la autoestima', 1, 1),
('2021-10-14', 'Terapia de pareja para mejorar la comunicación', 2, 20),
('2021-11-21', 'Seguimiento de tratamiento para depresión', 1, 8),
('2021-12-29', 'Consulta sobre técnicas de comunicación asertiva', 2, 17),
('2022-02-05', 'Terapia familiar para resolver conflictos', 1, 4),
('2022-03-15', 'Sesión de relajación y manejo del estrés', 2, 13),
('2022-04-23', 'Terapia individual para superar miedos y fobias', 1, 10),
('2022-06-01', 'Consulta sobre técnicas de manejo de la ira', 2, 5),
('2022-07-09', 'Terapia de pareja para superar crisis', 1, 16),
('2022-08-17', 'Sesión de relajación y mindfulness', 2, 9),
('2022-09-24', 'Seguimiento de tratamiento para trastornos del sueño', 1, 20),
('2022-11-02', 'Consulta inicial sobre ansiedad y estrés', 2, 8),
('2022-12-10', 'Terapia individual para mejorar la autoestima', 1, 7),
('2023-01-17', 'Terapia de pareja para mejorar la comunicación', 2, 3),
('2023-02-25', 'Seguimiento de tratamiento para depresión', 1, 14),
('2023-04-05', 'Consulta sobre técnicas de comunicación asertiva', 2, 15),
('2023-05-13', 'Terapia familiar para resolver conflictos', 1, 11),
('2023-06-20', 'Sesión de relajación y manejo del estrés', 2, 6),
('2023-07-28', 'Terapia individual para superar miedos y fobias', 1, 2),
('2023-09-05', 'Consulta sobre técnicas de manejo de la ira', 2, 17),
('2023-10-13', 'Terapia de pareja para superar crisis', 1, 20),
('2023-11-20', 'Sesión de relajación y mindfulness', 2, 12),
('2023-12-28', 'Seguimiento de tratamiento para trastornos del sueño', 1, 19),
('2024-02-04', 'Consulta inicial sobre ansiedad y estrés', 2, 5),
('2024-03-13', 'Terapia individual para mejorar la autoestima', 1, 8),
('2024-04-20', 'Terapia de pareja para mejorar la comunicación', 2, 18),
('2024-05-28', 'Seguimiento de tratamiento para depresión', 1, 4),
('2024-07-05', 'Consulta sobre técnicas de comunicación asertiva', 2, 3),
('2024-08-12', 'Terapia familiar para resolver conflictos', 1, 7),
('2024-09-20', 'Sesión de relajación y manejo del estrés', 2, 9),
('2024-10-27', 'Terapia individual para superar miedos y fobias', 1, 16),
('2024-12-04', 'Consulta sobre técnicas de manejo de la ira', 2, 10),
('2025-01-11', 'Terapia de pareja para superar crisis', 1, 13),
('2025-02-18', 'Sesión de relajación y mindfulness', 2, 15),
('2025-03-27', 'Seguimiento de tratamiento para trastornos del sueño', 1, 6),
('2025-05-04', 'Consulta inicial sobre ansiedad y estrés', 2, 1),
('2025-06-11', 'Terapia individual para superar la pérdida', 2, 4),
('2025-07-18', 'Sesión de relajación y manejo del estrés', 1, 19),
('2025-08-25', 'Seguimiento de tratamiento para trastornos de ansiedad', 2, 2);