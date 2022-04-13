<?php

//define the path as relative
$path = ".";

//using the opendir function
$dir_handle = @opendir($path) or die("Unable to open $path");


//echo "Directory Listing of <br/>";
$dir=getcwd();
$dir_list=split("/",$dir);
$path_len=count($dir_list);
$dir_idx=$path_len-1;
$parent_idx=$path_len-2;

echo "<TABLE WIDTH=50% BORDER=1 CELLPADDING=4 CELLSPACING=3>";
echo "<COL WIDTH=256*> <TBODY>";
echo "<TR><TH>$dir_list[$parent_idx] $dir_list[$dir_idx]</TH></TR>";

// read dir into array
while ($file = readdir($dir_handle)) {
  $list[] = $file;
}

sort($list);
$count=0;
foreach ($list as $file) {
   if ( stripos($file,'.cpp') || 
        stripos($file,'.doc') || 
        stripos($file,'.dat') || 
        stripos($file,'.gif') || 
        stripos($file,'.hpp') || 
        stripos($file,'.jpg') ||
        stripos($file,'.out') || 
        stripos($file,'.pdf') || 
        stripos($file,'.plt') || 
        stripos($file,'.png') || 
        stripos($file,'.ps')  || 
        stripos($file,'.sh')  || 
        stripos($file,'.tar') || 
        stripos($file,'.tgz') || 
        stripos($file,'.txt') || 
        stripos($file,'.zip')
      ){
     $bgcolor="ffffff";
     $count++;
     if ($count%2)  $bgcolor="ccffcc";
     echo "<TR> <TD BGCOLOR=$bgcolor VALIGN=TOP>";
     echo "<dd><a href=$file>$file</a>";
     echo "</TD> </TR>";
  }
}

//closing the directory
closedir($dir_handle);

?> 
