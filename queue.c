#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* TODO: What if malloc returned NULL? */
    if (!q)
        return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (!q)
        return false;
    list_ele_t *new;
    new = malloc(sizeof(list_ele_t));
    if (!new)
        return false;
    /* Allocate space for the string and copy it */
    new->value = malloc(sizeof(char) * (strlen(s) + 1));
    if (new->value == NULL) {
        free(new);
        return false;
    }
    memset(new->value, '\0', strlen(s) + 1);
    strncpy(new->value, s, strlen(s));
    /* Insert element to head */
    new->next = q->head;
    q->head = new;
    if (q->tail == NULL)
        q->tail = new;

    q->size += 1;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    if (!q)
        return false;
    list_ele_t *new;
    new = malloc(sizeof(list_ele_t));
    if (!new)
        return false;
    /* Allocate space for the string and copy it */
    new->value = malloc(sizeof(char) * (strlen(s) + 1));
    if (new->value == NULL) {
        free(new);
        return false;
    }
    memset(new->value, '\0', strlen(s) + 1);
    strncpy(new->value, s, strlen(s));
    new->next = NULL;
    /* Insert element to tail */
    if (q->tail == NULL) {
        q->tail = new;
        q->head = new;
    } else {
        q->tail->next = new;
        q->tail = new;
    }

    q->size += 1;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if (!q || q->size == 0)
        return false;

    /* Copy the removed string to *sp */
    if (sp) {
        size_t head_size = strlen(q->head->value);
        size_t size = head_size > bufsize - 1 ? bufsize - 1 : head_size;
        strncpy(sp, q->head->value, size);
        sp[size] = '\0';
    }

    /* Remove head element */
    list_ele_t *tmp = q->head;
    q->head = tmp->next;
    if (q->head == NULL) {
        /* Queue is empty after removing */
        q->tail = NULL;
    }
    free(tmp->value);
    free(tmp);

    q->size -= 1;
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
