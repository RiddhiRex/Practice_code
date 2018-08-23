"""
Write a program that uses regular expressions to determine if a string is a valid email address. 
For this challenge, let's define a valid email address as name@domain.tld where "name" can contain the characters a-z, A-Z, 0-9, _, and
. (dot). And "domain" can contain the characters a-z, and -. "name" and "domain" must be non-empty. "tld" can be "com", "org", or "net".
Input:
Your program should read lines of text from standard input. Each line contains a string that may or may not be a valid email address.
Output:
For each input string, print 'true' to standard output if the string is a valid email address as defined in this challenge. 
Otherwise print 'false'. Print one string per line.
"""
import re
def isValidEmail(email):
 if len(email) > 7:
 if re.match("^.+@([?)[a-zA-Z0-9-.]+.([a-zA-Z]{2,3}|[0-9]{1,3})(]?)$", email) != None:
 return True
 return False
if isValidEmail("my.email@gmail.com") == True :
 print "This is a valid email address"
else:
 print "This is not a valid email address"
