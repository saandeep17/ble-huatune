#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = iar.targets.arm.M3{1,0,7.40,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/boot/package/package_iar.targets.arm.rts.orm3.dep
package/lib/lib/debug/boot/package/package_iar.targets.arm.rts.orm3.dep: ;
endif

package/lib/lib/debug/boot/package/package_iar.targets.arm.rts.orm3: | .interfaces
package/lib/lib/debug/boot/package/package_iar.targets.arm.rts.orm3: package/package_iar.targets.arm.rts.c lib/debug/boot.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/debug/boot/package/package_iar.targets.arm.rts.srm3: | .interfaces
package/lib/lib/debug/boot/package/package_iar.targets.arm.rts.srm3: package/package_iar.targets.arm.rts.c lib/debug/boot.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/boot/cstartup_M.orm3.dep
package/lib/lib/debug/boot/cstartup_M.orm3.dep: ;
endif

package/lib/lib/debug/boot/cstartup_M.orm3: | .interfaces
package/lib/lib/debug/boot/cstartup_M.orm3: cstartup_M.c lib/debug/boot.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/debug/boot/cstartup_M.srm3: | .interfaces
package/lib/lib/debug/boot/cstartup_M.srm3: cstartup_M.c lib/debug/boot.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/boot/iar_xdc_init.orm3.dep
package/lib/lib/debug/boot/iar_xdc_init.orm3.dep: ;
endif

package/lib/lib/debug/boot/iar_xdc_init.orm3: | .interfaces
package/lib/lib/debug/boot/iar_xdc_init.orm3: iar_xdc_init.c lib/debug/boot.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/debug/boot/iar_xdc_init.srm3: | .interfaces
package/lib/lib/debug/boot/iar_xdc_init.srm3: iar_xdc_init.c lib/debug/boot.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/boot/cmain.orm3.dep
package/lib/lib/debug/boot/cmain.orm3.dep: ;
endif

package/lib/lib/debug/boot/cmain.orm3: | .interfaces
package/lib/lib/debug/boot/cmain.orm3: cmain.s lib/debug/boot.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) asmrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iasmarm -S --cpu Cortex-M3 --endian little  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2   $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/boot/boot.orm3.dep
package/lib/lib/debug/boot/boot.orm3.dep: ;
endif

package/lib/lib/debug/boot/boot.orm3: | .interfaces
package/lib/lib/debug/boot/boot.orm3: boot.s lib/debug/boot.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) asmrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iasmarm -S --cpu Cortex-M3 --endian little  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2   $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

clean,rm3 ::
	-$(RM) package/lib/lib/debug/boot/package/package_iar.targets.arm.rts.orm3
	-$(RM) package/lib/lib/debug/boot/cstartup_M.orm3
	-$(RM) package/lib/lib/debug/boot/iar_xdc_init.orm3
	-$(RM) package/lib/lib/debug/boot/cmain.orm3
	-$(RM) package/lib/lib/debug/boot/boot.orm3
	-$(RM) package/lib/lib/debug/boot/package/package_iar.targets.arm.rts.srm3
	-$(RM) package/lib/lib/debug/boot/cstartup_M.srm3
	-$(RM) package/lib/lib/debug/boot/iar_xdc_init.srm3

lib/debug/boot.arm3: package/lib/lib/debug/boot/package/package_iar.targets.arm.rts.orm3 package/lib/lib/debug/boot/cstartup_M.orm3 package/lib/lib/debug/boot/iar_xdc_init.orm3 package/lib/lib/debug/boot/cmain.orm3 package/lib/lib/debug/boot/boot.orm3 lib/debug/boot.arm3.mak

clean::
	-$(RM) lib/debug/boot.arm3.mak