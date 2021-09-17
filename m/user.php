<?php
/**
 *
 * 栏目列表/频道动态页
 *
 * @version        $Id: list.php 1 15:38 2010年7月8日Z tianya $
 * @package        DedeCMS.Site
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
define('DEDEMOB', 'Y');
require_once(dirname(__FILE__)."/../include/common.inc.php");

function sendmail($email, $mailtitle, $mailbody)
{
    global $cfg_sendmail_bysmtp, $cfg_smtp_server, $cfg_smtp_port, $cfg_smtp_usermail, $cfg_smtp_user, $cfg_smtp_password, $cfg_adminemail,$cfg_webname;
    if($cfg_sendmail_bysmtp == 'Y' && !empty($cfg_smtp_server))
    {
        $mailtype = 'HTML';
        require_once(DEDEINC.'/mail.class.php');
        $smtp = new smtp($cfg_smtp_server,$cfg_smtp_port,true,$cfg_smtp_usermail,$cfg_smtp_password);
        $smtp->debug = false;
        if(!$smtp->smtp_sockopen($cfg_smtp_server)){
            ShowMsg('邮件发送失败,请联系管理员','-1');
            exit();
        }
        $smtp->sendmail($email,$cfg_webname,$cfg_smtp_usermail, $mailtitle, $mailbody, $mailtype);
    }else{
        @mail($email, $mailtitle, $mailbody, $headers);
    }
}

$action = $_GET['action'];
if($action == 'add'){
    $qq = $_POST['qq'];
    $wechat = $_POST['wechat'];
    $mailbody = '新用户';
    if($qq){
        $mailbody .= ' QQ:'.$qq;
        $res = $dsql->GetOne("SELECT * FROM `dede_user` WHERE qq='$qq'");
        if($res){
            echo json_encode(['msg'=>'QQ:'.$qq." 已存在"]);die();
        }
    }
    if($wechat){
        $mailbody .= ' 微信:'.$wechat;
        $res = $dsql->GetOne("SELECT * FROM `dede_user` WHERE wechat='$wechat'");
        if($res){
            echo json_encode(['msg'=>'微信:'.$wechat." 已存在"]);die();
        }
    }
    $datetime = date('Y-m-d H:i:s',time());
    $inquery = "INSERT INTO `dede_user`(qq,wechat,add_time) VALUES ('".$qq."','$wechat','$datetime'); ";
    if($dsql->ExecuteNoneQuery($inquery)){
        $email = "544197366@qq.com";  //填写要发送到的邮箱
        $mailtitle = "手游诚招一级代理";
        sendmail($email, $mailtitle, $mailbody);

        $msg = '提交成功';
    }else{
        $msg = '提交失败';
    }
    echo json_encode(['msg'=>$msg]);
}

