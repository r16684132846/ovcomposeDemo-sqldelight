/*
 * Tencent is pleased to support the open source community by making ovCompose available.
 * Copyright (C) 2025 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import { Compose } from 'compose';
import testNapi from 'libentry.so'
import { registerComposeInteropBuilders } from './ComposeSample';

registerComposeInteropBuilders();

@Entry
@Component
struct Index {
  private controller = testNapi.MainArkUIViewController()

  onPageShow(): void {
    this.controller.onPageShow()
  }

  onPageHide(): void {
    this.controller.onPageHide()
  }

  onBackPress(): boolean | void {
    // 返回事件转发给 Compose，优先给 Compose 消费，若 Compose 不消费再给系统消费
    return this.controller.onBackPress()
  }

  build() {
    Stack() {
      Compose(
        {
          controller: this.controller,
          libraryName: "entry",
          // 若 Compose 不消费，事件会流转到这里，若这里返回 false，则交由系统处理
          onBackPressed: () => false
        }
      ).width('100%').height('100%')

      Column() {
        Button("testParam").onClick(() => testCase1())
        Row().height(10)
        Button("testResult").onClick(() => testCase2())
        Row().height(10)
        Button("testOrigin1").onClick(() => testOrigin1())
        Row().height(10)
        Button("testOrigin2").onClick(() => testOrigin2())
      }.padding(10)
    }.width('100%').height('100%').align(Alignment.BottomEnd)
  }
}

const LOOP_COUNT = 10

const STR_PARAM = "ArkTS: a1aa,Ga,baa,Ja,bb,rb,sb,vb,Bb,eaa,Pb,Vb,bc,cc,dc,ec,fc,hc,lc,faa,gaa,nc,qc,Bc,Ec,Kc,Lc,Fc,kd,ud,Ed,Hd,oaa,Wd,raa,taa,ce,oe,uaa,Ee,Ce,Fe,B,Xe,af,gf,mf,xf,Cf,Lf,zaa,Aaa,Baa,Caa,Qf,Tf,ag,cg,gg,kg,ng,Gaa,Haa,Iaa,Jaa,Kaa,Laa,Gg,Maa,Naa,Og,Sg,Oaa,Taa,Raa,gh,Uaa,Yaa,qh,th,$aa,aba,vh,Jh,eba,fba,Oh,gba,ai,iba,di,pi,jba,kba,qi,ri,si,lba,mba,nba,yi,oba,pba,uba,rba,sba,tba,vba,Ai,hi,Mi,Ni,Aba,Cba,Dba,Ri,Fba,Gba,Iba,Jba,Kba,Mba,Nba,aa,hj,ij,Oba,kj,Rba,tj,Sba,Tba,Ej,Fj,Uba; _.ba=function(a){return function(){return aa[a].apply(this,arguments)}};_.ca=function(a,b){return aa[a]=b};_.da=function(a){_.n.setTimeout(function(){throw a;},0)};_.ea=function(a){a&&typeof a.dispose== function &&a.dispose()};ia=function(a){for(var b=0,c=arguments.length;b<c;++b){var d=arguments[b];_.fa(d)?ia.apply(null,d):_.ea(d)}}; _.ja=function(a,b){if(Error.captureStackTrace)Error.captureStackTrace(this,_.ja);else{var c=Error().stack;c&&(this.stack=c)}a&&(this.message=String(a));b!==void 0&&(this.cause=b);this.j=!0};_.ka=function(a){return a[a.length-1]};_.la=function(a,b,c){for(var d=typeof a=== string ?a.split(  ):a,e=a.length-1;e>=0;--e)e in d&&b.call(c,d[e],e,a)};_.na=function(a,b,c){b=_.ma(a,b,c);return b<0?null:typeof a=== string ?a.charAt(b):a[b]}; _.ma=function(a,b,c){for(var d=a.length,e=typeof a=== string ?a.split(  ):a,f=0;f<d;f++)if(f in e&&b.call(c,e[f],f,a))return f;return-1};_.qa=function(a,b){return(0,_.pa)(a,b)>=0};_.ra=function(a,b){_.qa(a,b)||a.push(b)};_.ta=function(a,b){b=(0,_.pa)(a,b);var c;(c=b>=0)&&_.sa(a,b);return c};_.sa=function(a,b){return Array.prototype.splice.call(a,b,1).length==1};_.ua=function(a){return Array.prototype.concat.apply([],arguments)}; _.va=function(a){var b=a.length;if(b>0){for(var c=Array(b),d=0;d<b;d++)c[d]=a[d];return c}return[]};_.wa=function(a,b){for(var c=1;c<arguments.length;c++){var d=arguments[c];if(_.fa(d)){var e=a.length||0,f=d.length||0;a.length=e+f;for(var g=0;g<f;g++)a[e+g]=d[g]}else a.push(d)}};_.ya=function(a,b,c){return arguments.length<=2?Array.prototype.slice.call(a,b):Array.prototype.slice.call(a,b,c)}; _.Ba=function(a,b){b=b||a;for(var c=0,d=0,e={};d<a.length;){var f=a[d++],g=_.za(f)? o +_.Aa(f):(typeof f).charAt(0)+f;Object.prototype.hasOwnProperty.call(e,g)||(e[g]=!0,b[c++]=f)}b.length=c};_.Ca=function(a,b){if(!_.fa(a)||!_.fa(b)||a.length!=b.length)return!1;for(var c=a.length,d=aaa,e=0;e<c;e++)if(!d(a[e],b[e]))return!1;return!0};_.Da=function(a,b){return a>b?1:a<b?-1:0};aaa=function(a,b){return a===b};_.Fa=function(a,b){var c={};(0,_.Ea)(a,function(d,e){c[b.call(void 0,d,e,a)]=d});return c}; Ga=function(a){return{valueOf:a}.valueOf()};baa=function(){var a=null;if(!Ha)return a;try{var b=function(c){return c};a=Ha.createPolicy( OneGoogleWidgetUi#html ,{createHTML:b,createScript:b,createScriptURL:b})}catch(c){}return a};Ja=function(){Ia===void 0&&(Ia=baa());return Ia};_.Ma=function(a){var b=Ja();a=b?b.createHTML(a):a;return new _.Ka(_.La,a)};_.Na=function(a){return a instanceof _.Ka};_.Oa=function(a){if(_.Na(a))return a.j;throw Error( u );}; _.Qa=function(a){return function ==typeof _.Pa&&a instanceof _.Pa};_.Ra=function(a){if(_.Qa(a))return a.j;throw Error( u );};_.Ta=function(a){var b=Ja();a=b?b.createScriptURL(a):a;return new _.Sa(_.La,a)};_.Ua=function(a){return a instanceof _.Sa};_.Va=function(a){if(_.Ua(a))return a.j;throw Error( u );};_.Xa=function(a){return new _.Wa(_.La,a)};_.Ya=function(a){return a instanceof _.Wa};_.Za=function(a){if(_.Ya(a))return a.j;throw Error( u );}; bb=function(a){return new ab(function(b){return b.substr(0,a.length+1).toLowerCase()===a+ : })};_.eb=function(a,b){b=b===void 0?_.cb:b;if(_.Ya(a))return a;for(var c=0;c<b.length;++c){var d=b[c];if(d instanceof ab&&d.Tj(a))return _.Xa(a)}};_.gb=function(a){var b=!caa.test(a);b&&_.fb(a);if(!b)return a};_.hb=function(a){return a instanceof _.Wa?_.Za(a):_.gb(a)};_.jb=function(a){var b=Ja();a=b?b.createScript(a):a;return new _.ib(_.La,a)};_.kb=function(a){return a instanceof _.ib}; _.lb=function(a){if(_.kb(a))return a.j;throw Error( u );};_.nb=function(a,b){if(_.Na(a))return a;a=_.mb(String(a));if(b==null?0:b.V8)a=a.replace(/(^|[\r\n\t ]) /g, $1&#160; );if(b==null?0:b.U8)a=a.replace(/(\r\n|\n|\r)/g, <br> );if(b==null?0:b.X8)a=a.replace(/(\t+)/g,'<span style= white-space:pre >$1</span>');return _.Ma(a)};_.mb=function(a){return a.replace(/&/g, &amp; ).replace(/</g, &lt; ).replace(/>/g, &gt; ).replace(/ /g, &quot; ).replace(/'/g, &apos; )}; _.pb=function(a){var b=_.ob.apply(1,arguments);if(b.length===0)return _.Ta(a[0]);for(var c=a[0],d=0;d<b.length;d++)c+=encodeURIComponent(b[d])+a[d+1];return _.Ta(c)};rb=function(a){a=a.Ox.charCodeAt(a.Mb++);return qb[a]};sb=function(a){var b=0,c=0;do{var d=rb(a);b|=(d&31)<<c;c+=5}while(d&32);return b<0?b+4294967296:b};vb=function(a){if(_.tb)a(_.tb);else{var b;((b=ub)!=null?b:ub=[]).push(a)}};_.yb=function(){!_.tb&&_.wb&&_.xb(_.wb());return _.tb}; _.xb=function(a){_.tb=a;var b;(b=ub)==null||b.forEach(vb);ub=void 0};_.u=function(a){_.tb&&daa(a)};_.w=function(){_.tb&&Ab(_.tb)};Bb=function(a,b){a.__closure__error__context__984382||(a.__closure__error__context__984382={});a.__closure__error__context__984382.severity=b};eaa=function(){for(var a;a=Cb.remove();){try{a.Lh.call(a.scope)}catch(b){_.da(b)}Db(Eb,a)}Fb=!1};_.Gb=function(a,b,c){for(var d in a)b.call(c,a[d],d,a)}; _.Hb=function(a,b){var c={},d;for(d in a)b.call(void 0,a[d],d,a)&&(c[d]=a[d]);return c};_.Ib=function(a,b,c){var d={},e;for(e in a)d[e]=b.call(c,a[e],e,a);return d};_.Jb=function(a){var b=[],c=0,d;for(d in a)b[c++]=a[d];return b};_.Kb=function(a){var b=[],c=0,d;for(d in a)b[c++]=d;return b};_.Lb=function(a){for(var b in a)return!1;return!0};_.Mb=function(a){var b={},c;for(c in a)b[c]=a[c];return b}; _.Ob=function(a,b){for(var c,d,e=1;e<arguments.length;e++){d=arguments[e];for(c in d)a[c]=d[c];for(var f=0;f<Nb.length;f++)c=Nb[f],Object.prototype.hasOwnProperty.call(d,c)&&(a[c]=d[c])}};Pb=function(a){var b=arguments.length;if(b==1&&Array.isArray(arguments[0]))return Pb.apply(null,arguments[0]);for(var c={},d=0;d<b;d++)c[arguments[d]]=!0;return c};_.Qb=function(a,b){return a.lastIndexOf(b,0)==0};_.Rb=function(a,b){var c=a.length-b.length;return c>=0&&a.indexOf(b,c)==c};_.Sb=function(a){return/^[\s\xa0]*$/.test(a)}; _.Tb=function(a,b){return a.indexOf(b)!=-1};_.Wb=function(a,b){var c=0;a=(0,_.Ub)(String(a)).split( . );b=(0,_.Ub)(String(b)).split( . );for(var d=Math.max(a.length,b.length),e=0;c==0&&e<d;e++){var f=a[e]||  ,g=b[e]||  ;do{f=/(\d*)(\D*)(.*)/.exec(f)||[  ,  ,  ,  ];g=/(\d*)(\D*)(.*)/.exec(g)||[  ,  ,  ,  ];if(f[0].length==0&&g[0].length==0)break;c=Vb(f[1].length==0?0:parseInt(f[1],10),g[1].length==0?0:parseInt(g[1],10))||Vb(f[2].length==0,g[2].length==0)||Vb(f[2],g[2]);f=f[3];g=g[3]}while(c==0)}return c}; Vb=function(a,b){return a<b?-1:a>b?1:0};_.Xb=function(){var a=_.n.navigator;return a&&(a=a.userAgent)?a:  };bc=function(a){if(!$b||!ac)return!1;for(var b=0;b<ac.brands.length;b++){var c=ac.brands[b].brand;if(c&&_.Tb(c,a))return!0}return!1};cc=function(a){return _.Tb(_.Xb(),a)};dc=function(){return $b?!!ac&&ac.brands.length>0:!1};ec=function(){return dc()?!1:cc( Opera )};fc=function(){return dc()?!1:cc( Trident )||cc( MSIE )};hc=function(){return dc()?bc( Microsoft Edge ):cc( Edg/ )}; _.ic=function(){return cc( Firefox )||cc( FxiOS )};_.kc=function(){return cc( Safari )&&!(_.jc()||(dc()?0:cc( Coast ))||ec()||(dc()?0:cc( Edge ))||hc()||(dc()?bc( Opera ):cc( OPR ))||_.ic()||cc( Silk )||cc( Android ))};_.jc=function(){return dc()?bc( Chromium ):(cc( Chrome )||cc( CriOS ))&&!(dc()?0:cc( Edge ))||cc( Silk )};lc=function(){return cc( Android )&&!(_.jc()||_.ic()||ec()||cc( Silk ))}; faa=function(a){var b={};a.forEach(function(c){b[c[0]]=c[1]});return function(c){return b[c.find(function(d){return d in b})]||  }}; gaa=function(a){var b=_.Xb();if(a=== Internet Explorer ){if(fc())if((a=/rv: *([\d\.]*)/.exec(b))&&a[1])b=a[1];else{a=  ;var c=/MSIE +([\d\.]+)/.exec(b);if(c&&c[1])if(b=/Trident\/(\d.\d)/.exec(b),c[1]== 7.0 )if(b&&b[1])switch(b[1]){case  4.0 :a= 8.0 ;break;case  5.0 :a= 9.0 ;break;case  6.0 :a= 10.0 ;break;case  7.0 :a= 11.0 }else a= 7.0 ;else a=c[1];b=a}else b=  ;return b}var d=RegExp( ([A-Z][\\w ]+)/([^\\s]+)\\s*(?:\\((.*?)\\))? , g );c=[];for(var e;e=d.exec(b);)c.push([e[1],e[2],e[3]||void 0]); b=faa(c);switch(a){case  Opera :if(ec())return b([ Version , Opera ]);if(dc()?bc( Opera ):cc( OPR ))return b([ OPR ]);break;case  Microsoft Edge :if(dc()?0:cc( Edge ))return b([ Edge ]);if(hc())return b([ Edg ]);break;case  Chromium :if(_.jc())return b([ Chrome , CriOS , HeadlessChrome ])}return a=== Firefox &&_.ic()||a=== Safari &&_.kc()||a=== Android Browser &&lc()||a=== Silk &&cc( Silk )?(b=c[2])&&b[1]||  :  }; _.mc=function(a){if(dc()&&a!== Silk ){var b=ac.brands.find(function(c){return c.brand===a});if(!b||!b.version)return NaN;b=b.version.split( . )}else{b=gaa(a);if(b===  )return NaN;b=b.split( . )}return b.length===0?NaN:Number(b[0])};nc=function(){return $b?!!ac&&!!ac.platform:!1};_.pc=function(){return nc()?ac.platform=== Android :cc( Android )};qc=function(){return cc( iPhone )&&!cc( iPod )&&!cc( iPad )};_.rc=function(){return qc()||cc( iPad )||cc( iPod )}; _.sc=function(){return nc()?ac.platform=== macOS :cc( Macintosh )};_.tc=function(){return nc()?ac.platform=== Windows :cc( Windows )};_.uc=function(){return nc()?ac.platform=== Chrome OS :cc( CrOS )};_.vc=function(a){return haa&&a!=null&&a instanceof Uint8Array};_.wc=function(){return typeof BigInt=== function };_.xc=function(a){a.b8=!0;return a}; rome ])}return a=== Firefox &&_.ic()||a=== Safari &&_.kc()||a=== Android Browser &&lc()||a=== Silk &&cc( Silk )?(b=c[2])&&b[1]||  :  }; _.mc=function(a){if(dc()&&a!== Silk ){var b=ac.brands.find(function(c){return c.brand===a});if(!b||!b.version)return NaN;b=b.version.split( . )}else{b=gaa(a);if(b===  )return NaN;b=b.split( . )}return b.length===0?NaN:Number(b[0])};nc=function(){return $b?!!ac&&!!ac.platform:!1};_.pc=function(){return nc()?ac.platform=== Android :cc( Android )};qc=function(){return cc(";

function testCase1() {
  const time = new Date().getTime()
  for (let i = 0; i < LOOP_COUNT; i++) {
    testNapi.kn_string_params(STR_PARAM)
  }
  console.log(`KN: ArkTS testCase1 ${new Date().getTime() - time}ms`)
}

function testCase2() {
  const time = new Date().getTime()
  for (let i = 0; i < LOOP_COUNT; i++) {
    testNapi.kn_string_result();
  }
  console.log(`KN: ArkTS testCase2 ${new Date().getTime() - time}ms`)
}

function testOrigin1() {
  const time = new Date().getTime()
  for (let i = 0; i < LOOP_COUNT; i++) {
    testNapi.origin_string_params(STR_PARAM)
  }
  console.log(`KN: ArkTS testOrigin1 ${new Date().getTime() - time}ms`)
}

function testOrigin2() {
  const time = new Date().getTime()
  for (let i = 0; i < LOOP_COUNT; i++) {
    testNapi.origin_string_result();
  }
  console.log(`KN: ArkTS testOrigin2 ${new Date().getTime() - time}ms`)
}