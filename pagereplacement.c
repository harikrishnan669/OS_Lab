#include<stdio.h>

typedef struct {
    int PageN;
    int lastUsed;
    int freq;
} Frame;
void FIFS(Frame Frames[], int Frame_Size, int Pages[], int n) {
    printf("\n\tFIFS\n");
    int pageFault = 0, index = -1;
    for (int i = 0; i < Frame_Size; i++) Frames[i].PageN = -1;
    for (int i = 0; i < n; i++) {
        int pageFound = 0;
        for (int j = 0; j < Frame_Size; j++) {
            if (Frames[j].PageN == Pages[i]) {
                pageFound = 1;
                break;
            }
        }
        if (!pageFound) {
            pageFault++;
            index = (index + 1) % Frame_Size;
            Frames[index].PageN = Pages[i];
        }
    }
    printf("\nNo of PageFaults = %3d ", pageFault);
    printf("\nNo of PageHits = %3d ", n - pageFault);
}

void LRU(Frame Frames[], int Frame_Size, int Pages[], int n) {
    printf("\n\tLRU\n");
    int pageFault = 0;
    for (int i = 0; i < Frame_Size; i++) {
        Frames[i].PageN = -1;
        Frames[i].lastUsed = 0;
    }
    int z = 1;
    for (int i = 0; i < n; i++) {
        int pageFound = 0;
        for (int j = 0; j < Frame_Size; j++) {
            if (Frames[j].PageN == Pages[i]) {
                pageFound = 1;
                Frames[j].lastUsed = z++;
                break;
            }
        }
        if (!pageFound) {
            pageFault++;
            int min = 0;
            for (int j = 1; j < Frame_Size; j++) {
                if (Frames[j].lastUsed < Frames[min].lastUsed) {
                    min = j;
                }
            }
            Frames[min].PageN = Pages[i];
            Frames[min].lastUsed = z++;
        }
    }
    printf("\nNo of PageFaults = %3d ", pageFault);
    printf("\nNo of PageHits = %3d ", n - pageFault);
}

void LFU(Frame Frames[], int Frame_Size, int Pages[], int n) {
    printf("\n\tLFU\n");
    int pageFault = 0;
    for (int i = 0; i < Frame_Size; i++) {
        Frames[i].PageN = -1;
        Frames[i].freq = 0;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        int pageFound = 0;
        for (int j = 0; j < Frame_Size; j++) {
            if (Frames[j].PageN == Pages[i]) {
                pageFound = 1;
                Frames[j].freq++;
                break;
            }
        }
        if (!pageFound) {
            pageFault++;
            int min = index;
            for (int j = 0; j < Frame_Size; j++) {
                if (Frames[index].freq < Frames[min].freq) {
                    min = index;
                }
                index = (index + 1) % Frame_Size;
            }
            Frames[min].PageN = Pages[i];
            Frames[min].freq = 1;
            index = (min + 1) % Frame_Size;
        }
    }
    printf("\nNo of PageFaults = %3d ", pageFault);
    printf("\nNo of PageHits = %3d ", n - pageFault);
}

int main() {
    int Frame_Size, n;
    printf("Enter the size of Frame: ");
    scanf("%d", &Frame_Size);
    Frame Frames[Frame_Size];
    printf("Enter the Number of pages: ");
    scanf("%d", &n);
    int Pages[n];
    printf("Enter the Page Numbers: ");
    for (int i = 0; i < n; i++) 
    scanf("%d", &Pages[i]);
    FIFS(Frames, Frame_Size, Pages, n);
    LRU(Frames, Frame_Size, Pages, n);
    LFU(Frames, Frame_Size, Pages, n);
    return 0;
}
