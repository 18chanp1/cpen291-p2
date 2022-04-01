"use strict";(self["webpackChunkvue_frontend"]=self["webpackChunkvue_frontend"]||[]).push([[35],{5460:function(t,e,o){o.r(e),o.d(e,{default:function(){return z}});var s=o(3396),n=o(9242),l=o(7139);const r={class:"General"},i=(0,s._)("h1",null,"Music Input",-1),u=(0,s._)("h2",null,"Option 1: Text Input",-1),a=(0,s._)("p",null," To input your song, please prepare the following information: ",-1),c=(0,s._)("ol",null,[(0,s._)("li",null,"The pitch of each note (e.g. C)"),(0,s._)("li",null,"The length of each note (e.g. 1 relative unit)")],-1),d=(0,s._)("p",null," Type in chronological order, the pitch of each note, followed by the relative length of each note. Do not include spaces. ",-1),h=(0,s._)("p",null," For example, if you wish to play the note C for 1 RU, followed by the note B for 2 RU, you would input the following: ",-1),p=(0,s._)("p",null," C1B2 ",-1),m=(0,s._)("br",null,null,-1),b=(0,s._)("input",{type:"submit",value:"Submit",class:"flexbut",id:"ButtonForSubmit"},null,-1),g=(0,s._)("h2",null,"Option 2: Button Input",-1),f=(0,s._)("p",null," Push the buttons to input the corresponding note. The duration defaults to 1 RU. ",-1),y={class:"noteInput"},_=(0,s._)("p",null," Your Input: ",-1),w={class:"inputdisp"},v={class:"submitButtons"},B={id:"snackbar"},x={id:"snackbarG"};function k(t,e,o,k,P,S){const T=(0,s.up)("std_but");return(0,s.wg)(),(0,s.iD)("div",r,[i,u,a,c,d,h,p,(0,s._)("form",{onSubmit:e[1]||(e[1]=(0,n.iM)(((...t)=>S.submitForm&&S.submitForm(...t)),["prevent"]))},[(0,s.wy)((0,s._)("textarea",{"onUpdate:modelValue":e[0]||(e[0]=t=>P.typedscript=t)},"Input your music here.",512),[[n.nr,P.typedscript]]),m,b],32),g,f,(0,s._)("form",{onSubmit:e[12]||(e[12]=(0,n.iM)(((...t)=>S.submitBut&&S.submitBut(...t)),["prevent"]))},[(0,s._)("div",y,[(0,s.Wm)(T,{type:"button",onPressedButton:e[2]||(e[2]=t=>S.clicked(t)),class:"flexbut",text:"C"}),(0,s.Wm)(T,{type:"button",onPressedButton:e[3]||(e[3]=t=>S.clicked(t)),class:"flexbut",text:"D"}),(0,s.Wm)(T,{type:"button",onPressedButton:e[4]||(e[4]=t=>S.clicked(t)),class:"flexbut",text:"E"}),(0,s.Wm)(T,{type:"button",onPressedButton:e[5]||(e[5]=t=>S.clicked(t)),class:"flexbut",text:"F"}),(0,s.Wm)(T,{type:"button",onPressedButton:e[6]||(e[6]=t=>S.clicked(t)),class:"flexbut",text:"G"}),(0,s.Wm)(T,{type:"button",onPressedButton:e[7]||(e[7]=t=>S.clicked(t)),class:"flexbut",text:"A"}),(0,s.Wm)(T,{type:"button",onPressedButton:e[8]||(e[8]=t=>S.clicked(t)),class:"flexbut",text:"B"}),(0,s.Wm)(T,{type:"button",onPressedButton:e[9]||(e[9]=t=>S.clicked(t)),class:"flexbut",text:"R"})]),_,(0,s._)("p",w,(0,l.zw)(this.script),1),(0,s._)("div",v,[(0,s.Wm)(T,{type:"button",onPressedButton:e[10]||(e[10]=t=>S.reset()),text:"Reset",class:"flexbut2"}),(0,s.Wm)(T,{onPressedButton:e[11]||(e[11]=e=>t.submit()),text:"Submit",class:"flexbut2"})]),(0,s._)("div",B,(0,l.zw)(P.error),1),(0,s._)("div",x,(0,l.zw)(P.error),1)],32)])}function P(t,e,o,n,r,i){return(0,s.wg)(),(0,s.iD)("button",{onClick:e[0]||(e[0]=t=>i.clicked())},(0,l.zw)(o.text),1)}var S={name:"std_but",props:{text:String},data(){return{count:0}},methods:{clicked(){this.count++,this.$emit("pressed-button",this.text.concat(1))}}},T=o(89);const F=(0,T.Z)(S,[["render",P]]);var I=F,W=o(6265),G=o.n(W),N={name:"musicInput",data(){return{count:0,script:"",typedscript:"",error:""}},components:{std_but:I},methods:{clicked(t){this.count++,this.script=this.script.concat(t)},reset(){this.script=""},async submitForm(){var t=/^(([A-GR][1-9]+)*)$/;if(console.log(t.test(this.typedscript)),!t.test(this.typedscript))return console.log("inputerr"),void this.showBar("Input error. Please study the input format in detail.","");var e=this.isFree();if(console.log("checking server is free?"),console.log(e),0==this.isFree())return console.log("robot playing"),void this.showBar("The robot is currently playing music. Please try again later","");if(2!=this.isFree()){console.log("submitted, typed");const t={type:"MusicInTyped",arguments:this.typedscript};await G().post("/api/input/",t).then((t=>{console.log(t),this.showBar("Submission accepted. You will now be redirected home","G"),setTimeout(this.redirectHome,2500)})).catch((t=>{console.log(t),this.showBar("Server error. Please try again later.","")}))}else this.showBar("Server error. Please try again later.","")},async submitBut(){console.log("submitted, button");const t={type:"MusicInButtoned",arguments:this.script};await G().post("/api/input/",t).then((t=>{console.log(t),this.showBar("Submission accepted. You will now be redirected home","G"),setTimeout(this.redirectHome,2500)})).catch((t=>{console.log(t),this.showBar("Server error. Please try again later.","")}))},showBar(t,e){this.error=t;var o=document.getElementById("snackbar"+e);o.className="show",setTimeout((function(){o.className=o.className.replace("show","")}),3e3)},redirectHome(){this.$router.push("/")},isFree(){console.log("getting data"),G().get("/api/status").then((t=>(console.log("The data"),console.log(t.data),"FREE"==t.data?(console.log("returning true"),1):0))).catch((t=>(console.log(t),console.log("Returning false because server err"),2)))}}};const R=(0,T.Z)(N,[["render",k]]);var z=R},100:function(t,e,o){o.r(e),o.d(e,{default:function(){return f}});var s=o(3396),n=o(7139);const l={class:"General"},r=(0,s._)("h1",null,"Statistics",-1),i={class:"General"},u=(0,s._)("th",null,"Your favorite note",-1),a=(0,s._)("th",null,"Lifetime notes played",-1),c=(0,s._)("th",null,"Total song uploads",-1);function d(t,e,o,d,h,p){return(0,s.wg)(),(0,s.iD)("div",l,[r,(0,s._)("table",i,[(0,s._)("tr",null,[u,(0,s._)("td",null,(0,n.zw)(this.favnote),1)]),(0,s._)("tr",null,[a,(0,s._)("td",null,(0,n.zw)(this.lifnote),1)]),(0,s._)("tr",null,[c,(0,s._)("td",null,(0,n.zw)(this.songs),1)])])])}var h=o(6265),p=o.n(h),m={name:"statsPage",data(){return{favnote:"No data",lifnote:"No data",songs:"No data"}},mounted(){this.getData()},methods:{async getData(){console.log("getting data"),await p().get("/api/stats").then((t=>{console.log(t),this.favnote=t.favoriteNote,this.lifnote=t.lifetimeNotes,this.songs=t.numberOfSongs})).catch((t=>{console.log(t)}))}}},b=o(89);const g=(0,b.Z)(m,[["render",d]]);var f=g}}]);
//# sourceMappingURL=musicInput.c1251797.js.map