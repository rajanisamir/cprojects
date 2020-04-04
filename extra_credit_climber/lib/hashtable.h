#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct node {
	int x;
	int y;
} node;

typedef node keyType;
typedef int valType;

typedef struct entry {
	keyType key;
	valType value;
	struct entry *next;
} entry;

typedef struct hashtable {
	int size;
	entry **table;
} hashtable;

hashtable* allocate(int size);
int put(hashtable* ht, keyType key, valType value);
int get(hashtable* ht, keyType key);
int update(hashtable* ht, keyType key, int limb);
int limb_visited(hashtable* ht, node hold, int limb);
int erase(hashtable* ht, keyType key);
int deallocate(hashtable* ht);
int hash(keyType key, int m);

#endif
