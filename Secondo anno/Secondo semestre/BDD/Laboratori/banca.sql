create schema banca;
set search_path to banca;


CREATE TABLE contoCorrente(
	numero integer PRIMARY KEY DEFERRABLE INITIALLY IMMEDIATE,
	saldo integer not null
);