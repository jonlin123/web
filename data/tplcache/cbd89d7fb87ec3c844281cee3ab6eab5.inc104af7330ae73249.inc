<?php
$z[0]=Array("field","",25,51);
$z[0][4]=array();
$z[0][4]['name']="currentstyle";
$z[1]=Array("field","",63,91);
$z[1][4]=array();
$z[1][4]['name']="typeurl";
$z[2]=Array("field","",146,175);
$z[2][4]=array();
$z[2][4]['name']="typename";
$z[3]=Array("field","\r\n            global \$dsql;\r\n            \$sql = \"SELECT id From `dede_arctype` WHERE reid='@me' And ishidden<>1 order by sortrank asc limit 0, 100 \";\r\n            \$row = \$dsql->GetOne(\$sql);      \r\n            @me=is_array(\$row)?'<i class=\"fa fa-caret-down\"></i>':'';\r\n            ",190,521);
$z[3][4]=array();
$z[3][4]['name']="typeid";
$z[3][4]['runphp']="yes";
$z[4]=Array("field","\r\nglobal \$dsql;\r\n\$sql = \"SELECT id From `#@__arctype` WHERE reid='@me' And ishidden<>1 order by sortrank asc limit 0, 100 \";\r\n\$row = \$dsql->\r\n              GetOne(\$sql);\r\n              @me=is_array(\$row)?'class=\"dropdown-menu sub-menu2\" role=\"menu\"':'style=\"display:none\"';\r\n              ",543,882);
$z[4][4]=array();
$z[4][4]['name']="typeid";
$z[4][4]['runphp']="yes";
$z[5]=Array("channel","\r\n              <li class=\"Lev2\"> <a href=\"[field:typeurl/]\" class=\"menu2\">[field:typename/]</a> </li>\r\n              ",915,1086);
$z[5][4]=array();
$z[5][4]['type']="son";
$z[5][4]['noself']="yes";

?>