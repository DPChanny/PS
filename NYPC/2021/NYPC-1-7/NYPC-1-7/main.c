#include<stdio.h>
#include<stdlib.h>

typedef struct NodeInfo {
	int isVertical;
	int colorCode;
	int lineCode;
} NodeInfo;

int main(void) {
	//n 행 m 열
	int n = 0;
	int m = 0;
	if (scanf("%d %d", &n, &m)) {
		// n * m 크기의 2차원 배열 동적 할당
		int** arr = (int**)malloc(sizeof(int*) * m);
		for (size_t i = 0; i < m; i++)
		{
			arr[i] = (int*)malloc(sizeof(int) * n);
		}

		//입력
		for (size_t j = 0; j < m; j++)
		{
			for (size_t i = 0; i < n; i++) {
				scanf("%d", &arr[j][i]);
			}
		}

		NodeInfo* node = (NodeInfo*)malloc(sizeof(NodeInfo) * (m + n));
		int node_count = 0;

		//처리
		while (1) {
			int is_found = 1;
			//가로 모두 일치 검색
			for (size_t i = 0; i < m; i++) {
				int first_color_code = arr[i][0];
				for (size_t j = 1; j < n; j++)
				{
					if (arr[i][j] != first_color_code) {
						if (first_color_code == 0) {
							first_color_code = arr[i][j];
						}
						else if (arr[i][j] != 0) {
							is_found = 0;
							break;
						}
					}
				}
				if (is_found) {
					if (first_color_code != 0) {
						is_found = 1;
						for (size_t j = 0; j < n; j++)
						{
							arr[i][j] = 0;
						}
						NodeInfo new_node = { 0, first_color_code, i };
						node[node_count++] = new_node;
						break;
					}
				}
			}
			if (is_found)
			{
				continue;
			}
			//세로 모두 일치 검색
			for (size_t i = 0; i < n; i++) {
				int first_color_code = arr[0][i];
				for (size_t j = 1; j < m; j++)
				{
					if (first_color_code == 0) {
						first_color_code = arr[j][i];
					}
					else if (arr[j][i] != 0) {
						is_found = 0;
						break;
					}
				}
				if (is_found) {
					if (first_color_code != 0) {
						is_found = 1;
						for (size_t j = 0; j < m; j++)
						{
							arr[j][i] = 0;
						}
						NodeInfo new_node = { 1, first_color_code, i };
						node[node_count++] = new_node;
						break;
					}
				}
			}
			if (!is_found) {
				break;
			}
		}

		//출력
		printf("%d\n", node_count);
		for (size_t i = 0; i < node_count; i++)
		{
			if (node[node_count - i - 1].isVertical) {
				printf("V %d %d", node[node_count - i - 1].lineCode + 1, node[node_count - i - 1].colorCode);
			}
			else {
				printf("H %d %d", node[node_count - i - 1].lineCode + 1, node[node_count - i - 1].colorCode);
			}
			printf("\n");
		}
		
		//동적 할당 해제
		for (size_t i = 0; i < m; i++)
		{
			free(arr[i]);
		}
		free(arr);
	}

	return 0;
}