package main

import "fmt"

func uniqueLetterString(S string) int {
	n := len(S)
	dict := make(map[byte][]int)
	for i := 0; i < n; i++ {
		dict[S[i]] = append(dict[S[i]], i);
	}
	var ans int64 = 0
	for i, _ := range dict {
		res := int64(0)
		lastApp := -1

		for j, app := range dict[i] {
			if j == len(dict[i]) - 1 {
				res += int64(app - lastApp) * int64(n - 1 - app + 1);
				break
			}
			res += int64(app - lastApp) * int64(dict[i][j + 1] - 1 - app + 1);
			lastApp = app
		}
		ans += res
	}
	return int(ans % 1000000007)
}

func main() {
	uniqueLetterString("abc");
}