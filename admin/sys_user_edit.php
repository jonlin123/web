<?php
/**
 * 编辑以后
 *
 * @version        $Id: sys_admin_user_edit.php 1 16:22 2010年7月20日Z tianya $
 * @package        DedeCMS.Administrator
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__).'/config.php');
CheckPurview('sys_User');
require_once(DEDEINC.'/typelink.class.php');
if(empty($dopost)) $dopost = '';
//$id = preg_replace("#[^0-9]#", '', $id);

if($dopost=='delete')
{
    if(empty($userok)) $userok="";
    if($userok!="yes")
    {
        $randcode = mt_rand(10000, 99999);
        $safecode = substr(md5($cfg_cookie_encode.$randcode),0,24);
        require_once(DEDEINC."/oxwindow.class.php");
        $wintitle = "删除用户";
        $wecome_info = "<a href='sys_user.php'>用户管理</a>::删除用户";
        $win = new OxWindow();
        $win->Init("sys_user_edit.php","js/blank.js","POST");
        $win->AddHidden("dopost", $dopost);
        $win->AddHidden("userok", "yes");
        $win->AddHidden("randcode", $randcode);
        $win->AddHidden("safecode", $safecode);
        $win->AddHidden("id", $id);
        $win->AddTitle("系统警告！");
        $win->AddMsgItem("你确信要删除用户：$id 吗？","50");
        $win->AddMsgItem("安全验证串：<input name='safecode' type='text' id='safecode' size='16' style='width:200px' />&nbsp;(复制本代码： <font color='red'>$safecode</font> )","30");
        $winform = $win->GetWindow("ok");
        $win->Display();
        exit();
    }
    $safecodeok = substr(md5($cfg_cookie_encode.$randcode),0,24);
    if($safecodeok!=$safecode)
    {
        ShowMsg("请填写正确的安全验证串！", "sys_user.php");
        exit();
    }
    //$id = explode(',',$id);
    $rs = $dsql->ExecuteNoneQuery2("DELETE FROM `dede_user` WHERE id in (".$id.") ");
    if($rs>0)
    {
        ShowMsg("成功删除用户！","sys_user.php");
    }
    exit();
}
