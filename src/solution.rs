use std::collections::HashSet;

fn length_of_longest_substring(s: String) -> i32 {
    if s.len() < 2 {
        return s.len() as i32;
    }
    let mut first_index: usize = 0;
    let mut last_index: usize = 0;
    let mut max_size = 1;
    let mut map = HashSet::new();
    let chars: Vec<char> = s.chars().collect();
    while last_index < chars.len() {
        if map.contains(&chars[last_index]) {
            if (last_index - first_index) > max_size {
                max_size = last_index - first_index;
            }
            map.clear();
            first_index = next_index(&chars, first_index, last_index, chars[last_index]);
            last_index = first_index;
        } else {
            map.insert(chars[last_index]);
            last_index += 1;
        }
    }
    if (last_index - first_index) > max_size {
        max_size = last_index - first_index;
    }
    return max_size as i32;
}

fn next_index(chars: &Vec<char>, start: usize, end: usize, find: char) -> usize {
    let mut index = start;
    while index < end {
        if find == chars[index] {
            break;
        }
        index += 1;
    }
    return index + 1;
}

//14. 最长公共前缀
/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"

示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
pub fn longest_common_prefix(strs: Vec<String>) -> String {
    if strs.len() == 1 {
        return strs[0].to_string();
    }
    return "".to_string();
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn testSubstring() {
        let test = "abcabcbb".to_string();
        let test2 = "bbbbb".to_string();
        let test3 = "pwwkew".to_string();
        let test4 = "au".to_string();
        assert_eq!(length_of_longest_substring(test), 3);
        assert_eq!(length_of_longest_substring(test2), 1);
        assert_eq!(length_of_longest_substring(test3), 3);
        assert_eq!(length_of_longest_substring(test4), 2);
    }
}
