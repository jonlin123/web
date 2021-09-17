<section id="utility" class="utility">
  <div class="container">
    <div class="row">
      <div class="col-md-12 col-sm-12 col-xs-12">
        <h2 class="lg-title text-center"><span><a href="{dede:field name='typeurl'/}">{dede:field name='typename'/}</a></span></h2>
      </div>
    </div>
    <div class="row">
      <div class="col-md-12">
        <div id="blog-carousel" class="blog-carousel"> {dede:arclist row='5' titlelen='50' orderby='pubdate'}
          <div class="item"> <a href="[field:arcurl/]" class="thumb-link"><img src="[field:picname/]" alt="[field:title/]"/></a>
            <h4 class="title"><a href="[field:arcurl/]" title="[field:title/]">[field:title/]</a></h4>
            <div class="meta"> <span><i class="fa fa-calendar"></i> [field:pubdate function="MyDate('Y-m-d',@me)"/]</span> <span> / by [field:writer/]</span> </div>
            <p class="desc">[field:description function="cn_substr(@me,160)"/]...</p>
          </div>
          {/dede:arclist} </div>
      </div>
    </div>
  </div>
</section>