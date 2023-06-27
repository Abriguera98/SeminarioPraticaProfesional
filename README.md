# Seminario de Pratica Profesional
Sistema de Gestion de Historias Psicologicas para Voluntarios de la Fundacion Soles


# Architecture
This is a windows based application. This consists on a State Machine that communicates with a GUIManaged and lets it know how to update the windows.
All the data processing is handled through a DataProcessor class that will communicate with the DatabaseWrapper.

The DatabaseWrapper class is an interface with the database to be able to run stored procedures and get data. 

Added a different screens, constants for the sql querys and calls to make the Login, MainWindow and VisualizationWindow work. Also added classes used
for data abstraction with the database information.

