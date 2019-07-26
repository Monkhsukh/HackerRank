Taum is planning to celebrate the birthday of his friend, Diksha. There are two types of gifts that Diksha wants from Taum: one is black and the other is white. To make her happy, Taum has to buy  black gifts and  white gifts.

The cost of each black gift is  units.
The cost of every white gift is  units.
The cost of converting each black gift into white gift or vice versa is  units.
Help Taum by deducing the minimum amount he needs to spend on Diksha's gifts.

For example, if Taum wants to buy  black gifts and  white gifts at a cost of  and conversion cost , we see that he can buy a black gift for  and convert it to a white gift for , making the total cost of each white gift . That matches the cost of a white gift, so he can do that or just buy black gifts and white gifts. Either way, the overall cost is .

Function Description

Complete the function taumBday in the editor below. It should return the minimal cost of obtaining the desired gifts.

taumBday has the following parameter(s):

b: the number of black gifts
w: the number of white gifts
bc: the cost of a black gift
wc: the cost of a white gift
z: the cost to convert one color gift to the other color
Input Format

The first line will contain an integer , the number of test cases.

The next  pairs of lines are as follows: 
- The first line contains the values of integers  and . 
- The next line contains the values of integers , , and .

Constraints

 

Output Format

 lines, each containing an integer: the minimum amount of units Taum needs to spend on gifts.

Sample Input

5
10 10
1 1 1
5 9
2 3 4
3 6
9 1 1
7 7
4 2 1
3 3
1 9 2
Sample Output

20
37
12
35
12
Explanation

Test Case #01: 
Since black gifts cost the same as white, there is no benefit to converting the gifts. Taum will have to buy each gift for 1 unit. The cost of buying all gifts will be: .

Test Case #02: 
Again, we can't decrease the cost of black or white gifts by converting colors.  is too high. We will buy gifts at their original prices, so the cost of buying all gifts will be: .

Test Case #03: 
Since , we will buy  white gifts at their original price of .  of the gifts must be black, and the cost per conversion, . Total cost is .

Test Case #04: 
Similarly, we will buy  white gifts at their original price, . For black gifts, we will first buy white ones and color them to black, so that their cost will be reduced to . So cost of buying all gifts will be: .

Test Case #05: We will buy black gifts at their original price, . For white gifts, we will first black gifts worth  unit and color them to white for  units. The cost for white gifts is reduced to  units. The cost of buying all gifts will be: .