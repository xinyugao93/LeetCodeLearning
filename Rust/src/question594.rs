use std::collections::HashMap;

pub struct Solution594;

impl Solution594 {
    pub fn find_lhs(nums: &[i32], impl_type: i32) -> i32 {
        if impl_type == 1 {
            return Self::slide_window_impl(&nums);
        }
        Self::hash_map_impl(&nums)
    }

    fn slide_window_impl(nums: &[i32]) -> i32 {
        if nums.len() < 2 {
            return 0;
        }

        let mut indices: Vec<usize> = (0..nums.len()).collect();
        indices.sort_by_key(|&i| nums[i]);

        let mut left = 0;
        let mut max_len = 0;

        for right in 0..indices.len() {
            let left_val = nums[indices[left]];
            let right_val = nums[indices[right]];
            if right_val - left_val == 1 {
                max_len = max_len.max(right - left + 1);
            } else {
                while left <= right && nums[indices[right]] - nums[indices[left]] > 1 {
                    left += 1;
                }
            }
        }
        return max_len as i32;
    }

    fn hash_map_impl(nums: &[i32]) -> i32 {
        let mut map_num2cnt: HashMap<i32, i32> = HashMap::new();
        for &num in nums {
            *map_num2cnt.entry(num).or_insert(0) += 1;
        }

        let mut max_len = 0;
        for (&key, &value) in &map_num2cnt {
            if let Some(&next_count) = map_num2cnt.get(&(key + 1)) {
                max_len = max_len.max(next_count + value);
            }
        }

        return max_len as i32;
    }
}