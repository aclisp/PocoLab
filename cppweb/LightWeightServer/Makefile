#
# Makefile
#
# $Id: //poco/1.4/PageCompiler/samples/HTTPTimeServer/Makefile#1 $
#
# Makefile for Poco HTTPTimeServer
#

include $(POCO_BASE)/build/rules/global

# Where to find the PageCompiler executable
PAGECOMPILER = $(POCO_BUILD)/PageCompiler/bin/$(POCO_HOST_OSNAME)/$(POCO_HOST_OSARCH)/cpspc

objects = LightWeightServer DefaultRequestHandlerFactory DefaultPage

target         = lwserv
target_version = 1
target_libs    = PocoUtil PocoNet PocoXML PocoFoundation

include $(POCO_BASE)/build/rules/exec

# Rule for runnning PageCompiler
src/%.cpp: src/%.cpsp
	@echo "** Compiling Page" $<
	$(PAGECOMPILER) $<
