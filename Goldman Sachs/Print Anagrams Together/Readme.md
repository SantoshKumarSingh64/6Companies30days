<h1>Print Anagrams Together</h1>
<p><br>
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.
<br><br>
Example 1:<br>
&emsp; &emsp;Input:<br>
&emsp; &emsp;&emsp; &emsp;N = 5<br>
&emsp; &emsp;&emsp; &emsp;words[] = {act,god,cat,dog,tac}<br>
&emsp; &emsp;Output: <br>
&emsp; &emsp;&emsp; &emsp;god dog<br>
&emsp; &emsp;&emsp; &emsp;act cat tac<br>
&emsp; &emsp;Explanation:<br>
&emsp; &emsp;&emsp; &emsp;There are 2 groups of anagrams "god", "dog" make group 1.<br>
&emsp; &emsp;&emsp; &emsp;"act", "cat", "tac" make group 2.<br>
<br>
Example 2:<br>
&emsp; &emsp;Input:<br>
&emsp; &emsp;&emsp; &emsp;N = 3<br>
&emsp; &emsp;&emsp; &emsp;words[] = {no,on,is}<br>
&emsp; &emsp;Output:<br> 
&emsp; &emsp;&emsp; &emsp;no on<br>
&emsp; &emsp;&emsp; &emsp;is<br>
&emsp; &emsp;Explanation:<br>
&emsp; &emsp;&emsp; &emsp;There are 2 groups of anagrams "no", "on" make group 1.<br>
&emsp; &emsp;&emsp; &emsp;"is" makes group 2. <br>
<br><br>
Your Task:<br>
The task is to complete the function Anagrams() that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.
<br>
<br>
Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.<br>
Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.<br>
<br>
Constraints:<br>
&emsp;&emsp;1<=N<=100<br>
</p>
