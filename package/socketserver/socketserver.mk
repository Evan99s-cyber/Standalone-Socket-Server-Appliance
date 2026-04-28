##############################################################################

#

# socketserver

#

################################################################################

 

SOCKETSERVER_VERSION = 1.0

SOCKETSERVER_SITE = $(BR2_EXTERNAL_SOCKETSERVER_PATH)/socket-server

SOCKETSERVER_SITE_METHOD = local

 

SOCKETSERVER_LICENSE = MIT

SOCKETSERVER_LICENSE_FILES = LICENSE

 

define SOCKETSERVER_BUILD_CMDS

    $(TARGET_MAKE_ENV) $(MAKE) -C $(@D)

endef

 

define SOCKETSERVER_INSTALL_TARGET_CMDS

    $(INSTALL) -D -m 0755 </span>

        $(@D)/socket_server </span>

        $(TARGET_DIR)/usr/bin/socket_server

endef

 

$(eval $(generic-package))
