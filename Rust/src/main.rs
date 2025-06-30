mod question594;
use question594::Solution594;

fn main()  {
    let nums = vec![1,3,2,2,5,2,3,7];
    let result1 = Solution594::find_lhs(&nums, 2);
    println!("resulit is {result1}");
}