#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = iar.targets.arm.M4{1,0,7.40,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.sysbios.fatfs/package/package_ti.sysbios.fatfs.orm4.dep
package/lib/lib/release/ti.sysbios.fatfs/package/package_ti.sysbios.fatfs.orm4.dep: ;
endif

package/lib/lib/release/ti.sysbios.fatfs/package/package_ti.sysbios.fatfs.orm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/package/package_ti.sysbios.fatfs.orm4: package/package_ti.sysbios.fatfs.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release/ti.sysbios.fatfs/package/package_ti.sysbios.fatfs.srm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/package/package_ti.sysbios.fatfs.srm4: package/package_ti.sysbios.fatfs.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.sysbios.fatfs/ff.orm4.dep
package/lib/lib/release/ti.sysbios.fatfs/ff.orm4.dep: ;
endif

package/lib/lib/release/ti.sysbios.fatfs/ff.orm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/ff.orm4: ff.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release/ti.sysbios.fatfs/ff.srm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/ff.srm4: ff.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.sysbios.fatfs/diskio.orm4.dep
package/lib/lib/release/ti.sysbios.fatfs/diskio.orm4.dep: ;
endif

package/lib/lib/release/ti.sysbios.fatfs/diskio.orm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/diskio.orm4: diskio.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release/ti.sysbios.fatfs/diskio.srm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/diskio.srm4: diskio.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.sysbios.fatfs/ramdisk.orm4.dep
package/lib/lib/release/ti.sysbios.fatfs/ramdisk.orm4.dep: ;
endif

package/lib/lib/release/ti.sysbios.fatfs/ramdisk.orm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/ramdisk.orm4: ramdisk.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release/ti.sysbios.fatfs/ramdisk.srm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/ramdisk.srm4: ramdisk.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.sysbios.fatfs/syncsysbios.orm4.dep
package/lib/lib/release/ti.sysbios.fatfs/syncsysbios.orm4.dep: ;
endif

package/lib/lib/release/ti.sysbios.fatfs/syncsysbios.orm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/syncsysbios.orm4: syncsysbios.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release/ti.sysbios.fatfs/syncsysbios.srm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/syncsysbios.srm4: syncsysbios.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.sysbios.fatfs/memsysbios.orm4.dep
package/lib/lib/release/ti.sysbios.fatfs/memsysbios.orm4.dep: ;
endif

package/lib/lib/release/ti.sysbios.fatfs/memsysbios.orm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/memsysbios.orm4: memsysbios.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release/ti.sysbios.fatfs/memsysbios.srm4: | .interfaces
package/lib/lib/release/ti.sysbios.fatfs/memsysbios.srm4: memsysbios.c lib/release/ti.sysbios.fatfs.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

clean,rm4 ::
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/package/package_ti.sysbios.fatfs.orm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/ff.orm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/diskio.orm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/ramdisk.orm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/syncsysbios.orm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/memsysbios.orm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/package/package_ti.sysbios.fatfs.srm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/ff.srm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/diskio.srm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/ramdisk.srm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/syncsysbios.srm4
	-$(RM) package/lib/lib/release/ti.sysbios.fatfs/memsysbios.srm4

lib/release/ti.sysbios.fatfs.arm4: package/lib/lib/release/ti.sysbios.fatfs/package/package_ti.sysbios.fatfs.orm4 package/lib/lib/release/ti.sysbios.fatfs/ff.orm4 package/lib/lib/release/ti.sysbios.fatfs/diskio.orm4 package/lib/lib/release/ti.sysbios.fatfs/ramdisk.orm4 package/lib/lib/release/ti.sysbios.fatfs/syncsysbios.orm4 package/lib/lib/release/ti.sysbios.fatfs/memsysbios.orm4 lib/release/ti.sysbios.fatfs.arm4.mak

clean::
	-$(RM) lib/release/ti.sysbios.fatfs.arm4.mak
