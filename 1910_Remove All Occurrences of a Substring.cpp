//Two Pointer Approach

string removeOccurrences (string s, string part){
  int i = 0, j = 0, k = part.length ();
// cout<<s.substr(0,3);
  while (j < s.length ()){
      if (j - i + 1 < part.length ()){
	      j++;
	  }
      else if (j - i + 1 == k){
	     if (s.substr (i, k) == part){
	        s.erase (i, k);
	        i = 0;
	        j = 0;
	     }else{
	        j++;
	        i++;
	    }
	  }
    }
    return s;
}
