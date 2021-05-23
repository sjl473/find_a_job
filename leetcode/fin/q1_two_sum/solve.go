package awesomeProject

func twoSum_2(nums []int, target int) []int {
	hash_table := map[int]int{}
	for i, j := range nums {
		if m, ok := hash_table[target - j]; ok {
			return []int{m, i}
		}
		hash_table[j] = i
	}
	return nil
}
func twoSum_1(nums []int, target int) []int {
	for i, j := range nums {
		for m := i + 1; m <= len(nums); m++  {
			if nums[m] + j == target {
				return []int{i, m}
			}
		}
	}
	return nil;
}