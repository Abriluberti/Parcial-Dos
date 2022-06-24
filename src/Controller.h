/*
 * Controller.h
 *
 *
 *Author: Abril uberti, div d
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "string.h"
#include "eServicio.h"
#include "input.h"

int controller_loadFromText(char *path, LinkedList *pArrayeServicio);
int controller_ListServicio(LinkedList *pArrayeServicio);
int controller_sorteServicio(LinkedList *pArrayeServicio);
int controller_saveAsText(char *path, LinkedList *pArrayeServicio);
int controllerFiltrado(LinkedList *pArrayeServicio);
int controllerAddServicio(LinkedList *pArrayeServicio);

