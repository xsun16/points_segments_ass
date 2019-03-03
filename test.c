#include "points_segments.h"
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

void print_array_2D(int **arr, int rows, int cols){
	for (int i=0; i<rows; i++){
		printf("[");
		for (int j=0; j<cols; j++)
			printf("%d ",arr[i][j]);
		printf("] ");
	}
	printf("\n");
}


int * naive_func(int rows, int size, int **arr, int *p_arr){
	int * res = malloc(sizeof(int) * size);
	int count = 0;
	for (int i = 0; i < size; ++i) {
		count = 0;
		for (int j = 0; j < rows; ++j) {
			if(arr[j][0] <= p_arr[i] && arr[j][1] >= p_arr[i]) {
				count ++;
			}
		}
		res[i] = count;
	}
	print_array(res, size);
	return res;
}


int cmp_int(const void* _a , const void* _b){
	int* a = (int*)_a;
	int* b = (int*)_b;
	return *a - *b;
}

void gen_seg(int ** arr, int rows, int start, int end, int ** new_seg) {
	for (int i = start; i < end; ++i) {
		new_seg[i - start][0] = arr[i][0];
		new_seg[i - start][1] = arr[i][1];
	}
}


int cmp_seg_start(const void *a,const void *b){
	int * ap = *(int **)a;
	int * bp = *(int **)b;
	return ap[0] - bp[0];
}


int cmp_seg_end(const void * a, const void * b){
	int * ap = *(int **)a;
	int * bp = *(int **)b;
	return ap[1] - bp[1];
}


int get_start_pos(int value, int ** arr, int rows){
	int i = 0;
	for (i = 0; i < rows; ++i) {
		if(value < arr[i][0]) {
			return i;
		}
	}
	return i;
}


int get_end_pos(int value, int ** arr, int rows){
	int i = 0;
	for (i = 0; i < rows; ++i) {
		if(value <= arr[i][1]){
			return i;
		}
	}
	return i;
}


int * quick_func(int rows, int size, int **arr, int *p_arr){
	int * res = malloc(sizeof(int) * size);
	qsort(arr, rows, sizeof(arr[0]), cmp_seg_start);
	for (int i = 0; i < size; ++i) {
		int pos = get_start_pos(p_arr[i], arr, rows);
		int ** new_arr = (int **)malloc(pos * sizeof(int *));
		for (int j = 0; j < pos; ++j) {
			new_arr[j] = (int *)malloc(2 * sizeof(int));
		}
		gen_seg(arr, rows, 0, pos, new_arr);
		qsort(new_arr, pos, sizeof(arr[0]), cmp_seg_end);
		int val = get_end_pos(p_arr[i], new_arr, pos);
		res[i] = pos - val;
		for (int k = 0; k < pos; ++k) {
			free(new_arr[k]);
		}
		free(new_arr);
	}
	print_array(res, size);
	return res;
}


void compare_res(int * naive_res, int *quick_res , int p){
    for (int j = 0; j < p; ++j) {
        if(naive_res[j] != quick_res[j]){
            printf("Error");
            exit(0);
        }
    }
}

int main() {	
	const char * files[] = {"input1.txt", "input2.txt", "input3.txt"};   

	for (int f=0; f < 3; f++){
		FILE *pfile = fopen(files[f], "r");
		if(pfile == NULL)  {
			printf("Error opening file %s\n", files[f]);
			return 1;
		}
		
		int s, p;
		while(fscanf(pfile, "%d %d", &s, &p)!=EOF){		
		
			//allocate 2D array to hold s segments
			int ** segments = malloc(s*sizeof(int *));
			for (int i=0; i < s; i++){
				segments[i] = malloc(2*sizeof(int));
			}
		
			//scan all segment lines and populate the segments
			for (int i=0; i < s; i++){
				fscanf(pfile, "%d %d", &segments[i][0], &segments[i][1]);
			}		
		
			//allocate a single array to hold p points
			int * points = malloc(p*sizeof(int));
		
			//scan all point coordinates into points array
			for (int i=0; i < p; i++){
				fscanf(pfile, "%d", &points[i]);
			}
			
			printf("There are total %d segments, and %d points\n", s, p);
			
			print_array_2D(segments, s, 2);
			print_array(points, p);
			//TODO: pass s, p, segments, and points to your two algorithms
			printf("the result is:\n");
			int * naive_res = naive_func(s, p, segments, points);
			int * quick_res = quick_func(s, p, segments, points);
			printf("*****************\n");
			//the output should be an array of size p containing 
			//-for each point- the number of covering segments 
			
			//TODO: implement - compare these outputs from 2 algorithms
			for (int j = 0; j < p; ++j) {
				if(naive_res[j] != quick_res[j]){
					printf("Error");
					fclose(pfile);
					exit(0);
				}
			}
            compare_res(naive_res, quick_res, p);
			free(naive_res);
			free(quick_res);
		}
		fclose(pfile);
	}
	return 0;
}
