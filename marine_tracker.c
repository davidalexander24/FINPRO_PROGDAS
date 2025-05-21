#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Types ---
typedef enum { FISH, MAMMAL, CRUSTACEAN, MOLLUSK } SpeciesType;

typedef union {
    float averageWeight;
    int typicalCount;
} ExtraInfo;

typedef struct {
    char name[50];
    SpeciesType type;
    float length;
    ExtraInfo info;
} MarineRecord;

// --- Globals & Array Management ---
int capacity = 10;
int count = 0;
MarineRecord *records;

void init_array() {
    records = malloc(sizeof(MarineRecord) * capacity);
    if (!records) { perror("malloc"); exit(EXIT_FAILURE); }
}

void display_record(const MarineRecord *r, int idx) {
    const char *names[] = {"Fish","Mammal","Crustacean","Mollusk"};
    printf("[%d] %s (%s), %.1f cm, ", idx+1, r->name, names[r->type], r->length);
    if (r->type == MAMMAL)
        printf("Avg Wt: %.2f kg\n", r->info.averageWeight);
    else
        printf("School: %d\n", r->info.typicalCount);
}

void list_all() {
    if (count == 0) { printf("No records.\n"); return; }
    for (int i = 0; i < count; i++) display_record(&records[i], i);
}


void ensure_capacity() {
    if (count >= capacity) {
        capacity *= 2;
        records = realloc(records, sizeof(MarineRecord) * capacity);
        if (!records) { perror("realloc"); exit(EXIT_FAILURE); }
    }
}

void search_by_species() {
    printf("Select species:\n0 = Fish\n1 = Mammal\n2 = Crustacean\n3 = Mollusk\n");
    int t = get_choice(0,3), found = 0;
    for (int i = 0; i < count; i++)
        if (records[i].type == t) {
            display_record(&records[i], i);
            found++;
        }
    if (!found) printf("No matches.\n");
}

void delete_record() {
    list_all();
    if (count == 0) return;
    printf("Delete record #: ");
    int idx = get_choice(1, count) - 1;
    for (int i = idx; i < count - 1; i++)
        records[i] = records[i + 1];
    count--;
    printf("Deleted.\n");
}

//tambahin function baru di atas main
int main() {
    
}