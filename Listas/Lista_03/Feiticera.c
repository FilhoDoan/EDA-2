#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_ITEMS 262144  // 2^18 for size of hash table, chosen as a power of two for better hash distribution

typedef unsigned long long ULL;
typedef long long LL;

typedef struct bag {
  LL data;
  ULL code;
  struct bag *next;
} bag;

typedef struct hash {
  bag *data;
} hash;

hash* hashTable;
ULL RANDOM;

// MurmurHash3 adapted for simplicity (replace with any strong hash function if necessary)
ULL murmurHash3_x86_32(ULL key) {
  key ^= key >> 33;
  key *= 0xff51afd7ed558ccdULL;
  key ^= key >> 33;
  key *= 0xc4ceb9fe1a85ec53ULL;
  key ^= key >> 33;
  return key;
}

// Custom hash function using MurmurHash3 with a random seed
ULL custom_hash(ULL key) {
  return murmurHash3_x86_32(key + RANDOM);
}

hash* initHashTable(LL size) {
  hashTable = (hash*)calloc(size, sizeof(hash));
  if (hashTable == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  return hashTable;
}

ULL computeHashIndex(ULL key, LL size) {
  return custom_hash(key) % size;
}

void insertIntoHashTable(ULL key, LL data) {
  ULL index = computeHashIndex(key, MAX_ITEMS);
  bag* current = hashTable[index].data;

  while (current != NULL) {
    if (current->code == key) {
      current->data += data;
      if (current->data <= 0) {
        // Remove item if data is zero or negative
        bag* to_free = current;
        if (hashTable[index].data == current) {
          hashTable[index].data = current->next;
        } else {
          bag* prev = hashTable[index].data;
          while (prev->next != current) {
            prev = prev->next;
          }
          prev->next = current->next;
        }
        free(to_free);
      }
      return;
    }
    current = current->next;
  }

  // If the item is not found, create a new entry
  if (data > 0) {
    bag* new_bag = (bag*)malloc(sizeof(bag));
    if (new_bag == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(1);
    }
    new_bag->data = data;
    new_bag->code = key;
    new_bag->next = hashTable[index].data;
    hashTable[index].data = new_bag;
  }
}

LL countTotalItems() {
  LL total = 0;
  for (LL i = 0; i < MAX_ITEMS; i++) {
    bag* current = hashTable[i].data;
    while (current != NULL) {
      if (current->data > 0) {
        total += current->data;
      }
      current = current->next;
    }
  }
  return total;
}

void solve() {
  LL n;
  scanf("%lld", &n);
  initHashTable(MAX_ITEMS);
  RANDOM = (ULL)time(NULL);

  for (LL i = 0; i < n; i++) {
    LL data;
    ULL code;
    scanf("%llu %lld", &code, &data);
    insertIntoHashTable(code, data);
  }

  LL items = countTotalItems();
  printf("%lld\n", items);

  for (LL i = 0; i < MAX_ITEMS; i++) {
    bag* current = hashTable[i].data;
    while (current != NULL) {
      bag* temp = current;
      current = current->next;
      free(temp);
    }
  }
  free(hashTable);
}

int main() {
  solve();
  return 0; 
}
