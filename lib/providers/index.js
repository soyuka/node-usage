var providers = {
    'linux': require('./proc'),
    'solaris': require('./solaris'),
    'mac': require('./bsd'),
    'freebsd': require('./bsd'),
    'win': require('./win'),
    'other': require('./other')
};

module.exports = function(sysinfo) {

    var provider = providers[sysinfo.OS];
    if(provider) {
        return provider(sysinfo);
    } else {
        return providers['other'](sysinfo);
    }
}
