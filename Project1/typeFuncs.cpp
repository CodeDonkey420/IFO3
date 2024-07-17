#include "DBTypes.h"
#include <string.h>
#include <stdio.h>
#include <corecrt_malloc.h>

// Definition aller m�glichen Felder f�r Quellen
Field author = { "author", NULL };
Field authororeditor = { "author or editor", NULL };
Field title = { "title", NULL };
Field journal = { "journal", NULL };
Field year = { "year", NULL };
Field volume = { "volume", NULL };
Field number = { "number", NULL };
Field pages = { "pages", NULL };
Field month = { "month", NULL };
Field note = { "note", NULL };
Field publisher = { "publisher", NULL };
Field editor = { "editor", NULL };
Field series = { "series", NULL };
Field address = { "address", NULL };
Field edition = { "edition", NULL };
Field booktitle = { "booktitle", NULL };
Field chapter = { "chapter", NULL };
Field chapterandorpages = { "chapter / pages", NULL };
Field organization = { "organization", NULL };
Field school = { "school", NULL };
Field howpublished = { "howpublished", NULL };
Field institution = { "institution", NULL };
Field type = { "type", NULL };
Field nullField = NULL;  // Leeres Feld, um Reihung klar definiert aufzuf�llen

// Reihungen leerer Felder um leere Quellen klar definieren zu k�nnen
Field nullFields[6] = { nullField, nullField, nullField, nullField, nullField, nullField };
Field nullOptFields[8] = { nullField, nullField, nullField, nullField, nullField, nullField, nullField, nullField };

int initSource(Source* DBEntry, Sourcetype variant, char* key) {

	// Start der Definitionen der Quellentypen
	if (variant == article) {
		static Field reqFields[] = {author, title, journal, year, nullField, nullField };  // Festlegen notwendiger Felder
		static Field optFields[] = { volume, number, pages, month, note, nullField, nullField, nullField };  // Festlegen optionaler Felder

		// �bertragen in die Quellenstruktur
		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		// Variane der Quelle setzen
		DBEntry->variant = article;
	}
	// Und alles ganz oft wiederholen...
	else if (variant == book) {
		Field reqFields[] = {authororeditor, title, publisher, year, nullField, nullField };
		Field optFields[] = { volume, series, address, edition, month, note, nullField, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = book;
	}
	else if (variant == booklet) {
		Field reqFields[] = { title, nullField, nullField, nullField, nullField, nullField };
		Field optFields[] = { author, howpublished, address, month, year, note, nullField, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = booklet;
	}
	else if (variant == conference) {
		Field reqFields[] = { author, title, booktitle, year, nullField, nullField };
		Field optFields[] = { editor, pages, organization, publisher, address, month, note, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = conference;
	}
	else if (variant == inbook) {
		Field reqFields[] = { authororeditor, title, chapterandorpages, publisher, year, nullField };
		Field optFields[] = { volume, series, address, edition, month, note, nullField, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = inbook;
	}
	else if (variant == incollection) {
		Field reqFields[] = { author, title, booktitle, publisher, year, nullField };
		Field optFields[] = { editor, chapter, pages, address, month, note, nullField, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = incollection;
	}
	else if (variant == manual) {
		Field reqFields[] = { title, nullField, nullField, nullField, nullField, nullField };
		Field optFields[] = { author, organization, address, edition, month, year, note, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = manual;
	}
	else if (variant == masterthesis) {
		Field reqFields[] = { author, title, school, year, nullField, nullField };
		Field optFields[] = { address, month, note, nullField, nullField, nullField, nullField, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = masterthesis;
	}
	else if (variant == misc) {
		Field reqFields[] = { nullField, nullField, nullField, nullField, nullField, nullField };
		Field optFields[] = { author, title, howpublished, month, year, note, nullField, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = misc;
	}
	else if (variant == phdthesis) {
		Field reqFields[] = { author, title, school, year, nullField, nullField };
		Field optFields[] = { address, month, note, nullField, nullField, nullField, nullField, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = phdthesis;
		strcpy(DBEntry->key, key);
	}
	else if (variant == proceedings) {
		Field reqFields[] = { title, year, nullField, nullField, nullField, nullField };
		Field optFields[] = { editor, publisher, organization, address, month, note, nullField, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = proceedings;
	}
	else if (variant == techreport) {
		Field reqFields[] = { author, title, institution, year, nullField, nullField };
		Field optFields[] = { type, number, address, month, note, nullField, nullField, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = techreport;
	}
	else if (variant == unpublished) {
		Field reqFields[] = { author, title, note, nullField, nullField, nullField };
		Field optFields[] = { month, year, nullField, nullField, nullField, nullField, nullField, nullField };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = unpublished;
	}
	else {
		printf("Ung\x81ltige Auswahl...");
		DBEntry = NULL;
		return 0;
	}

	// Zuweisen des Schl�ssels
	strcpy(DBEntry->key, key);

	return 1;
}

bool sourceExists(Source* source) {  // standart�berpr�fung, ob Quelle schon angelegt
	return (source->fields != NULL && source->key != NULL && source->optFields != NULL && source->variant != empty);
}

bool fieldValid(Field* field) {  // standart�berpr�fung, ob Feld angelegt
	return (field->fieldName != NULL && strcmp(field->fieldName, "") != 0);
}

bool fieldHasContent(Field* field) {  // standart�berpr�fung, ob Feld inhalt hat
	return (field->content != NULL && strlen(field->content) > 0);
}

void setNullSource(Source* source) {  // klares Setzen der "leeren" Quellen
	memcpy(source->fields, nullFields, sizeof(nullFields));
	memcpy(source->optFields, nullOptFields, sizeof(nullOptFields));
	source->variant = empty;  // Einfach auszulesende ID f�r undefinierte Quellenstruktur
	source->key[0] = EOF;
}

// Neues Element an Datenbank anh�ngen
int appendDB(DataBank *db, Source newSource) {
	db->sources[db->entries] = newSource;  // neue Quelle einf�gen
	db->entries ++;  // Zahl der Eintr�ge erh�hen
	return 1; 
}