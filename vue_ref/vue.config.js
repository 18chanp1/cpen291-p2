const BundleTracker = require("webpack-bundle-tracker");

//declare pages
const pages = {
    'vue_app_01': {
        entry: './src/main.js',
        chunks: ['chunk-vendors']
    },
    'vue_app_02': {
        entry: './src/newhampshir.js',
        chunks: ['chunk-vendors']
    },
}

//define bundles.
module.exports = {
    pages: pages,
    filenameHashing: false,
    productionSourceMap: false,
    //while production, empty public path.
    //non production, go to server. 
    publicPath: process.env.NODE_ENV === 'production'
        ? ''
        : 'http://localhost:8080/',
    outputDir: '../django_vue_mpa/static/vue/', //where to place product ready js. Django application static file loc.

    
    
    chainWebpack: config => {
        //optimizations and caching.
        config.optimization
            .splitChunks({
                cacheGroups: {
                    vendor: {
                        test: /[\\/]node_modules[\\/]/,
                        name: "chunk-vendors",
                        chunks: "all",
                        priority: 1
                    },
                },
            });

        Object.keys(pages).forEach(page => {
            config.plugins.delete(`html-${page}`);
            config.plugins.delete(`preload-${page}`);
            config.plugins.delete(`prefetch-${page}`);
        })

        //describe bundles produced. Use by Django webpackloader
        config
            .plugin('BundleTracker')
            .use(BundleTracker, [{filename: '../vue_frontend/webpack-stats.json'}]);


        //trickery
        config.resolve.alias
            .set('__STATIC__', 'static')

        //dev server for non development.
        config.devServer
            .public('http://localhost:8080')
            .host('localhost')
            .port(8080)
            .hotOnly(true)
            .watchOptions({poll: 1000})
            .https(false)
            .headers({"Access-Control-Allow-Origin": ["*"]})

    }
};

django-webpack-loader==0.6.0