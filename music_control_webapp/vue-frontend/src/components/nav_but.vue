<template>
    <button @click = "clicked()">{{this.count}}</button>
</template>

<script>
    export default{
        name: 'nav_but',
         props: {
            but_name:{
                type: String,
                default: "The default",
            }
        },
        data(){
            return{
                count:0
            }
        },
        methods:{
            clicked(){
                this.count++
            }
        }
        

    }
</script>