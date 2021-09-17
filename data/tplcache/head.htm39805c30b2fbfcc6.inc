<?php
$z[0]=Array("global","",212,234);
$z[0][4]=array();
$z[0][4]['name']="cfg_tel";
$z[1]=Array("global","",300,324);
$z[1][4]=array();
$z[1][4]['name']="cfg_email";
$z[2]=Array("global","",365,389);
$z[2][4]=array();
$z[2][4]['name']="cfg_email";
$z[3]=Array("global","",544,568);
$z[3][4]=array();
$z[3][4]['name']="cfg_weibo";
$z[4]=Array("global","",649,675);
$z[4][4]=array();
$z[4][4]['name']="cfg_qqweibo";
$z[5]=Array("global","",800,821);
$z[5][4]=array();
$z[5][4]['name']="cfg_qq";
$z[6]=Array("global","",924,947);
$z[6][4]=array();
$z[6][4]['name']="cfg_shop";
$z[7]=Array("global","",1525,1551);
$z[7][4]=array();
$z[7][4]['name']="cfg_webname";
$z[8]=Array("field","(@me==\"\")? @me=\" class='Lev1 active' \":@me=\"\";",1693,1789);
$z[8][4]=array();
$z[8][4]['name']="typeid";
$z[8][4]['runphp']="yes";
$z[9]=Array("channelartlist","\r\n          <li class=\"Lev1 dropdown {dede:field.currentstyle/}\"> <a href=\"{dede:field name='typeurl'/}\" class=\"menu1 dropdown-toggle\" data-toggle=\"dropdown\">{dede:field name='typename'/} \r\n            {dede:field name=typeid runphp=\"yes\"}\r\n            global \$dsql;\r\n            \$sql = \"SELECT id From `dede_arctype` WHERE reid='@me' And ishidden<>1 order by sortrank asc limit 0, 100 \";\r\n            \$row = \$dsql->GetOne(\$sql);      \r\n            @me=is_array(\$row)?'<i class=\"fa fa-caret-down\"></i>':'';\r\n            {/dede:field}</a>\r\n            <ul {dede:field name=typeid runphp=\"yes\"}\r\nglobal \$dsql;\r\n\$sql = \"SELECT id From `#@__arctype` WHERE reid='@me' And ishidden<>1 order by sortrank asc limit 0, 100 \";\r\n\$row = \$dsql->\r\n              GetOne(\$sql);\r\n              @me=is_array(\$row)?'class=\"dropdown-menu sub-menu2\" role=\"menu\"':'style=\"display:none\"';\r\n              {/dede:field}>\r\n              \r\n              {dede:channel type='son' noself='yes'}\r\n              <li class=\"Lev2\"> <a href=\"[field:typeurl/]\" class=\"menu2\">[field:typename/]</a> </li>\r\n              {/dede:channel}\r\n            </ul>\r\n          </li>\r\n          ",1850,3074);
$z[9][4]=array();
$z[9][4]['typeid']="top";
$z[9][4]['currentstyle']="active";

?>