/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */
import java.util.*;
import org.mozilla.javascript.*;
import xdc.services.intern.xsr.*;
import xdc.services.spec.Session;

public class ti_sysbios_fatfs
{
    static final String VERS = "@(#) xdc-A71\n";

    static final Proto.Elm $$T_Bool = Proto.Elm.newBool();
    static final Proto.Elm $$T_Num = Proto.Elm.newNum();
    static final Proto.Elm $$T_Str = Proto.Elm.newStr();
    static final Proto.Elm $$T_Obj = Proto.Elm.newObj();

    static final Proto.Fxn $$T_Met = new Proto.Fxn(null, null, 0, -1, false);
    static final Proto.Map $$T_Map = new Proto.Map($$T_Obj);
    static final Proto.Arr $$T_Vec = new Proto.Arr($$T_Obj);

    static final XScriptO $$DEFAULT = Value.DEFAULT;
    static final Object $$UNDEF = Undefined.instance;

    static final Proto.Obj $$Package = (Proto.Obj)Global.get("$$Package");
    static final Proto.Obj $$Module = (Proto.Obj)Global.get("$$Module");
    static final Proto.Obj $$Instance = (Proto.Obj)Global.get("$$Instance");
    static final Proto.Obj $$Params = (Proto.Obj)Global.get("$$Params");

    static final Object $$objFldGet = Global.get("$$objFldGet");
    static final Object $$objFldSet = Global.get("$$objFldSet");
    static final Object $$proxyGet = Global.get("$$proxyGet");
    static final Object $$proxySet = Global.get("$$proxySet");
    static final Object $$delegGet = Global.get("$$delegGet");
    static final Object $$delegSet = Global.get("$$delegSet");

    Scriptable xdcO;
    Session ses;
    Value.Obj om;

    boolean isROV;
    boolean isCFG;

    Proto.Obj pkgP;
    Value.Obj pkgV;

    ArrayList<Object> imports = new ArrayList<Object>();
    ArrayList<Object> loggables = new ArrayList<Object>();
    ArrayList<Object> mcfgs = new ArrayList<Object>();
    ArrayList<Object> icfgs = new ArrayList<Object>();
    ArrayList<String> inherits = new ArrayList<String>();
    ArrayList<Object> proxies = new ArrayList<Object>();
    ArrayList<Object> sizes = new ArrayList<Object>();
    ArrayList<Object> tdefs = new ArrayList<Object>();

    void $$IMPORTS()
    {
        Global.callFxn("loadPackage", xdcO, "ti.sysbios");
        Global.callFxn("loadPackage", xdcO, "xdc");
        Global.callFxn("loadPackage", xdcO, "xdc.corevers");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.sysbios.fatfs.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.sysbios.fatfs", new Value.Obj("ti.sysbios.fatfs", pkgP));
    }

    void FatFS$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sysbios.fatfs.FatFS.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sysbios.fatfs.FatFS", new Value.Obj("ti.sysbios.fatfs.FatFS", po));
        pkgV.bind("FatFS", vo);
        // decls 
    }

    void FatFS$$CONSTS()
    {
        // module FatFS
    }

    void FatFS$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void FatFS$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void FatFS$$SIZES()
    {
    }

    void FatFS$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sysbios/fatfs/FatFS.xs");
        om.bind("ti.sysbios.fatfs.FatFS$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sysbios.fatfs.FatFS.Module", "ti.sysbios.fatfs");
        po.init("ti.sysbios.fatfs.FatFS.Module", $$Module);
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("getFatTimeHook", new Proto.Adr("xdc_Int32(*)(xdc_Void)", "PFn"), null, "wh");
        po.addFld("fatfsPrefix", $$T_Str, "fat", "wh");
        po.addFld("ramdiskSymbolName", $$T_Str, "", "wh");
        po.addFld("ramdiskSize", Proto.Elm.newCNum("(xdc_UInt)"), Global.eval("512 * 256"), "wh");
        po.addFld("ramdiskDriveId", Proto.Elm.newCNum("(xdc_Int)"), Global.eval("-1"), "wh");
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sysbios.fatfs.FatFS$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sysbios.fatfs.FatFS$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sysbios.fatfs.FatFS$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        // typedef FatFS.fatTimeHookFxn
        om.bind("ti.sysbios.fatfs.FatFS.fatTimeHookFxn", new Proto.Adr("xdc_Int32(*)(xdc_Void)", "PFn"));
    }

    void FatFS$$ROV()
    {
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.sysbios.fatfs.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.sysbios.fatfs"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sysbios/fatfs/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.sysbios.fatfs"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.sysbios.fatfs"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.sysbios.fatfs"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.sysbios.fatfs"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.sysbios.fatfs"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.sysbios.fatfs"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.sysbios.fatfs", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.sysbios.fatfs");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.sysbios.fatfs.");
        pkgV.bind("$vers", Global.newArray(1, 0, 0));
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        imports.add(Global.newArray("ti.sysbios", Global.newArray()));
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.sysbios.fatfs'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("if ('ti.sysbios.fatfs$$stat$base' in xdc.om) {\n");
            sb.append("pkg.packageBase = xdc.om['ti.sysbios.fatfs$$stat$base'];\n");
            sb.append("pkg.packageRepository = xdc.om['ti.sysbios.fatfs$$stat$root'];\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/release/ti.sysbios.fatfs.aem3',\n");
            sb.append("'lib/release/ti.sysbios.fatfs.aem4',\n");
            sb.append("'lib/release/ti.sysbios.fatfs.am3g',\n");
            sb.append("'lib/release/ti.sysbios.fatfs.am4g',\n");
            sb.append("'lib/release/ti.sysbios.fatfs.arm3',\n");
            sb.append("'lib/release/ti.sysbios.fatfs.arm4',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/release/ti.sysbios.fatfs.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/release/ti.sysbios.fatfs.aem4', {target: 'ti.targets.arm.elf.M4', suffix: 'em4'}],\n");
            sb.append("['lib/release/ti.sysbios.fatfs.am3g', {target: 'gnu.targets.arm.M3', suffix: 'm3g'}],\n");
            sb.append("['lib/release/ti.sysbios.fatfs.am4g', {target: 'gnu.targets.arm.M4', suffix: 'm4g'}],\n");
            sb.append("['lib/release/ti.sysbios.fatfs.arm3', {target: 'iar.targets.arm.M3', suffix: 'rm3'}],\n");
            sb.append("['lib/release/ti.sysbios.fatfs.arm4', {target: 'iar.targets.arm.M4', suffix: 'rm4'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void FatFS$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sysbios.fatfs.FatFS", "ti.sysbios.fatfs");
        po = (Proto.Obj)om.findStrict("ti.sysbios.fatfs.FatFS.Module", "ti.sysbios.fatfs");
        vo.init2(po, "ti.sysbios.fatfs.FatFS", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sysbios.fatfs.FatFS$$capsule", "ti.sysbios.fatfs"));
        vo.bind("$package", om.findStrict("ti.sysbios.fatfs", "ti.sysbios.fatfs"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        vo.bind("fatTimeHookFxn", om.findStrict("ti.sysbios.fatfs.FatFS.fatTimeHookFxn", "ti.sysbios.fatfs"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sysbios.fatfs")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.sysbios.fatfs.FatFS$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.setElem("", "./FatFS.xdt");
        atmap.seal("length");
        vo.bind("TEMPLATE$", "./FatFS.xdt");
        pkgV.bind("FatFS", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("FatFS");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sysbios.fatfs.FatFS", "ti.sysbios.fatfs"));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.sysbios.fatfs.FatFS")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.sysbios.fatfs")).add(pkgV);
    }

    public void exec( Scriptable xdcO, Session ses )
    {
        this.xdcO = xdcO;
        this.ses = ses;
        om = (Value.Obj)xdcO.get("om", null);

        Object o = om.geto("$name");
        String s = o instanceof String ? (String)o : null;
        isCFG = s != null && s.equals("cfg");
        isROV = s != null && s.equals("rov");

        $$IMPORTS();
        $$OBJECTS();
        FatFS$$OBJECTS();
        FatFS$$CONSTS();
        FatFS$$CREATES();
        FatFS$$FUNCTIONS();
        FatFS$$SIZES();
        FatFS$$TYPES();
        if (isROV) {
            FatFS$$ROV();
        }//isROV
        $$SINGLETONS();
        FatFS$$SINGLETONS();
        $$INITIALIZATION();
    }
}
