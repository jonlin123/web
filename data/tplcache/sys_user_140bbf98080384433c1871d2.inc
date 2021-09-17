<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=<?php echo $cfg_soft_lang; ?>">
  <title>用户管理</title>
  <link rel="stylesheet" type="text/css" href="css/base.css">
  <script language="javascript" src="../include/js/dedeajax2.js"></script>
  <script language="javascript" src="js/ieemu.js"></script>
  <script language="javascript" src="js/context_menu.js"></script>
  <script language="javascript" src="js/main.js"></script>
  <script language="javascript" src="js/list.js"></script>
</head>
<body leftmargin="8" topmargin="8" background='images/allbg.gif' onLoad="ContextMenu.intializeContextMenu()">

<!--  快速转换位置按钮  -->
<table width="98%" border="0" cellpadding="0" cellspacing="1" bgcolor="#ccd9b9" align="center">
  <tr>
    <td height="26" background="images/newlinebg3.gif">
      <table width="98%" border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td width="24%" style="padding-left:10px;"><b>用户管理</b> </td>
        </tr>
      </table>
    </td>
  </tr>
</table>

<!--  内容列表   -->
<form name="form2" id="form2">
  <table width="98%" border="0" cellpadding="2" cellspacing="1" bgcolor="#CFCFCF" align="center" style="margin-top:8px">
    <tr bgcolor="#E7E7E7" >
      <td height="28" colspan="6" background="images/tbg.gif" style="padding-left:10px;">
        用户管理
      </td>
    </tr>
    <tr align="center" bgcolor="#FBFCE2" height="25">
      <td width="4%" height="24" align="center">选择</td>
      <td width="10%" height="24" align="center">ID</td>
      <td width="13%" align="center">QQ</td>
      <td width="22%" align="center">微信</td>
      <td width="22%" align="center">添加时间</td>
      <td width="23%" align="center">操作</td>
    </tr>
    <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
    <tr align='center' bgcolor="#FFFFFF" height="26" align="center" onMouseMove="javascript:this.bgColor='#FCFDEE';" onMouseOut="javascript:this.bgColor='#FFFFFF';">
      <td>
        <input name="arcID" type="checkbox" id="arcID" value="<?php echo $fields['id']; ?>" class="np" />
      </td>
      <td><?php echo $fields['id']; ?></td>
      <td><?php echo $fields['qq']; ?><br> </td>
      <td><?php echo $fields['wechat']; ?></td>
      <td><?php echo $fields['add_time']; ?></td>
      <td>
        <a href='sys_user_edit.php?id=<?php echo $fields['id']; ?>&userid=<?php echo $fields['userid']; ?>&dopost=delete'><u>删除</u></a>
      </td>
    </tr>
    <?php
}
}?>
    <tr bgcolor="#ffffff">
      <td height="36" colspan="10">
        &nbsp;
        <a href="javascript:selAll()" class="coolbg">全选</a>
        <a href="javascript:noSelAll()" class="coolbg">取消</a>
        <a href="javascript:;" onClick="delall()" class="coolbg">&nbsp;批量删除&nbsp;</a>
      </td>
    </tr>
</form>
<tr align="right" bgcolor="#F9FCEF">
  <td height="36" colspan="10" align="center">
    <?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '3';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

  </td>
</tr>
</table>

</body>
<script>

  function delall()
  {
    var obj = document.getElementsByName("arcID");
    var id='';
    for(k in obj){
      if(obj[k].checked){
        if(id==''){
          id += obj[k].value;
        }else{
          id += ','+obj[k].value;
        }
      }
    }
    if(id == ''){
      alert('必须选择一个或多个用户！');
      return;
    }else{
      location="sys_user_edit.php?dopost=delete&id="+id;
    }
  }
</script>
</html>