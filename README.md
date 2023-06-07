# Seminario de Pratica Profesional
Sistema de Gestion de Historias Psicologicas para Voluntarios de la Fundacion Soles


# Architecture
This is a windows based application. This consists on a State Machine that communicates with a GUIManaged and lets it know how to update the windows.
All the data processing is handled through a DataProcessor class that will communicate with the DatabaseWrapper (TBI).
The DatabaseWrapper class is an abstraction of the Database that allows to run stored procedures and run SQL querys.

