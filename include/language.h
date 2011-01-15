enum LanguageString
{
	LANGUAGE_NAME,
	COMMAND_REQUIRES_PERM,
	COMMAND_IDENTIFY_REQUIRED,
	COMMAND_CANNOT_USE,
	COMMAND_CAN_USE,
	COMMAND_DEPRECATED,
	USER_RECORD_NOT_FOUND,
	UNKNOWN_COMMAND,
	UNKNOWN_COMMAND_HELP,
	SYNTAX_ERROR,
	MORE_INFO,
	NO_HELP_AVAILABLE,
	BAD_USERHOST_MASK,
	BAD_EXPIRY_TIME,
	USERHOST_MASK_TOO_WIDE,
	SERVICE_OFFLINE,
	READ_ONLY_MODE,
	PASSWORD_INCORRECT,
	INVALID_TARGET,
	ACCESS_DENIED,
	MORE_OBSCURE_PASSWORD,
	PASSWORD_TOO_LONG,
	NICK_NOT_REGISTERED,
	NICK_X_IS_SERVICES,
	NICK_X_NOT_REGISTERED,
	NICK_X_IN_USE,
	NICK_X_NOT_IN_USE,
	NICK_X_NOT_ON_CHAN,
	NICK_X_FORBIDDEN,
	NICK_X_FORBIDDEN_OPER,
	NICK_X_ILLEGAL,
	NICK_X_TRUNCATED,
	NICK_X_SUSPENDED,
	CHAN_X_NOT_REGISTERED,
	CHAN_X_NOT_IN_USE,
	CHAN_X_FORBIDDEN,
	CHAN_X_FORBIDDEN_OPER,
	CHAN_X_SUSPENDED,
	NICK_IDENTIFY_REQUIRED,
	MAIL_DISABLED,
	MAIL_INVALID,
	MAIL_X_INVALID,
	MAIL_LATER,
	MAIL_DELAYED,
	NO_REASON,
	UNKNOWN,
	DURATION_DAY,
	DURATION_DAYS,
	DURATION_HOUR,
	DURATION_HOURS,
	DURATION_MINUTE,
	DURATION_MINUTES,
	DURATION_SECOND,
	DURATION_SECONDS,
	NO_EXPIRE,
	EXPIRES_SOON,
	EXPIRES_M,
	EXPIRES_1M,
	EXPIRES_HM,
	EXPIRES_H1M,
	EXPIRES_1HM,
	EXPIRES_1H1M,
	EXPIRES_D,
	EXPIRES_1D,
	END_OF_ANY_LIST,
	LIST_INCORRECT_RANGE,
	CS_LIST_INCORRECT_RANGE,
	NICK_IS_REGISTERED,
	NICK_IS_SECURE,
	NICK_MAY_NOT_BE_USED,
	FORCENICKCHANGE_IN_1_MINUTE,
	FORCENICKCHANGE_IN_20_SECONDS,
	FORCENICKCHANGE_NOW,
	FORCENICKCHANGE_CHANGING,
	NICK_REGISTER_SYNTAX,
	NICK_REGISTER_SYNTAX_EMAIL,
	NICK_REGISTRATION_DISABLED,
	NICK_REGISTRATION_FAILED,
	NICK_REG_PLEASE_WAIT,
	NICK_CANNOT_BE_REGISTERED,
	NICK_ALREADY_REGISTERED,
	NICK_REGISTERED,
	NICK_REGISTERED_NO_MASK,
	NICK_PASSWORD_IS,
	NICK_REG_DELAY,
	NICK_GROUP_SYNTAX,
	NICK_GROUP_DISABLED,
	NICK_GROUP_PLEASE_WAIT,
	NICK_GROUP_CHANGE_DISABLED,
	NICK_GROUP_SAME,
	NICK_GROUP_TOO_MANY,
	NICK_GROUP_JOINED,
	NICK_UNGROUP_ONE_NICK,
	NICK_UNGROUP_NOT_IN_GROUP,
	NICK_UNGROUP_SUCCESSFUL,
	NICK_IDENTIFY_SYNTAX,
	NICK_IDENTIFY_FAILED,
	NICK_IDENTIFY_SUCCEEDED,
	NICK_IDENTIFY_EMAIL_REQUIRED,
	NICK_IDENTIFY_EMAIL_HOWTO,
	NICK_ALREADY_IDENTIFIED,
	NICK_UPDATE_SUCCESS,
	NICK_LOGOUT_SYNTAX,
	NICK_LOGOUT_SUCCEEDED,
	NICK_LOGOUT_X_SUCCEEDED,
	NICK_LOGOUT_SERVICESADMIN,
	NICK_DROP_DISABLED,
	NICK_DROPPED,
	NICK_X_DROPPED,
	NICK_SET_SYNTAX,
	NICK_SET_DISABLED,
	NICK_SET_UNKNOWN_OPTION,
	NICK_SET_OPTION_DISABLED,
	NICK_SET_DISPLAY_CHANGED,
	NICK_SET_LANGUAGE_SYNTAX,
	NICK_SET_LANGUAGE_CHANGED,
	NICK_SET_EMAIL_UNSET,
	NICK_SET_EMAIL_UNSET_IMPOSSIBLE,
	NICK_SET_KILL_SYNTAX,
	NICK_SET_KILL_IMMED_SYNTAX,
	NICK_SET_KILL_IMMED,
	NICK_SET_KILL_IMMED_DISABLED,
	NICK_SET_SECURE_SYNTAX,
	NICK_SET_PRIVATE_SYNTAX,
	NICK_SET_HIDE_SYNTAX,
	NICK_SET_MSG_SYNTAX,
	NICK_SET_AUTOOP_SYNTAX,
	NICK_SASET_SYNTAX,
	NICK_SASET_UNKNOWN_OPTION,
	NICK_SASET_BAD_NICK,
	NICK_SASET_DISPLAY_INVALID,
	NICK_SASET_PASSWORD_FAILED,
	NICK_SASET_PASSWORD_CHANGED,
	NICK_SASET_PASSWORD_CHANGED_TO,
	NICK_SASET_EMAIL_CHANGED,
	NICK_SASET_EMAIL_UNSET,
	NICK_SASET_GREET_CHANGED,
	NICK_SASET_GREET_UNSET,
	NICK_SASET_KILL_SYNTAX,
	NICK_SASET_KILL_IMMED_SYNTAX,
	NICK_SASET_KILL_ON,
	NICK_SASET_KILL_QUICK,
	NICK_SASET_KILL_IMMED,
	NICK_SASET_KILL_OFF,
	NICK_SASET_SECURE_SYNTAX,
	NICK_SASET_SECURE_ON,
	NICK_SASET_SECURE_OFF,
	NICK_SASET_PRIVATE_SYNTAX,
	NICK_SASET_PRIVATE_ON,
	NICK_SASET_PRIVATE_OFF,
	NICK_SASET_HIDE_SYNTAX,
	NICK_SASET_HIDE_EMAIL_ON,
	NICK_SASET_HIDE_EMAIL_OFF,
	NICK_SASET_HIDE_MASK_ON,
	NICK_SASET_HIDE_MASK_OFF,
	NICK_SASET_HIDE_QUIT_ON,
	NICK_SASET_HIDE_QUIT_OFF,
	NICK_SASET_HIDE_STATUS_ON,
	NICK_SASET_HIDE_STATUS_OFF,
	NICK_SASET_MSG_SYNTAX,
	NICK_SASET_MSG_ON,
	NICK_SASET_MSG_OFF,
	NICK_SASET_NOEXPIRE_SYNTAX,
	NICK_SASET_NOEXPIRE_ON,
	NICK_SASET_NOEXPIRE_OFF,
	NICK_SASET_AUTOOP_SYNTAX,
	NICK_SASET_AUTOOP_ON,
	NICK_SASET_AUTOOP_OFF,
	NICK_SASET_LANGUAGE_SYNTAX,
	NICK_ACCESS_SYNTAX,
	NICK_ACCESS_ALREADY_PRESENT,
	NICK_ACCESS_REACHED_LIMIT,
	NICK_ACCESS_ADDED,
	NICK_ACCESS_NOT_FOUND,
	NICK_ACCESS_DELETED,
	NICK_ACCESS_LIST,
	NICK_ACCESS_LIST_X,
	NICK_ACCESS_LIST_EMPTY,
	NICK_ACCESS_LIST_X_EMPTY,
	NICK_STATUS_REPLY,
	NICK_INFO_SYNTAX,
	NICK_INFO_REALNAME,
	NICK_INFO_SERVICES_OPERTYPE,
	NICK_INFO_ADDRESS,
	NICK_INFO_ADDRESS_ONLINE,
	NICK_INFO_ADDRESS_ONLINE_NOHOST,
	NICK_INFO_TIME_REGGED,
	NICK_INFO_LAST_SEEN,
	NICK_INFO_LAST_QUIT,
	NICK_INFO_EMAIL,
	NICK_INFO_VHOST,
	NICK_INFO_VHOST2,
	NICK_INFO_GREET,
	NICK_INFO_OPTIONS,
	NICK_INFO_EXPIRE,
	NICK_INFO_OPT_KILL,
	NICK_INFO_OPT_SECURE,
	NICK_INFO_OPT_PRIVATE,
	NICK_INFO_OPT_MSG,
	NICK_INFO_OPT_AUTOOP,
	NICK_INFO_OPT_NONE,
	NICK_INFO_NO_EXPIRE,
	NICK_INFO_SUSPENDED,
	NICK_INFO_SUSPENDED_NO_REASON,
	NICK_LIST_SYNTAX,
	NICK_LIST_SERVADMIN_SYNTAX,
	NICK_LIST_HEADER,
	NICK_LIST_RESULTS,
	NICK_ALIST_HEADER,
	NICK_ALIST_HEADER_X,
	NICK_ALIST_XOP_FORMAT,
	NICK_ALIST_ACCESS_FORMAT,
	NICK_ALIST_FOOTER,
	NICK_GLIST_HEADER,
	NICK_GLIST_HEADER_X,
	NICK_GLIST_FOOTER,
	NICK_GLIST_REPLY,
	NICK_GLIST_REPLY_NOEXPIRE,
	NICK_RECOVER_SYNTAX,
	NICK_NO_RECOVER_SELF,
	NICK_RECOVERED,
	NICK_RELEASE_SYNTAX,
	NICK_RELEASE_NOT_HELD,
	NICK_RELEASED,
	NICK_GHOST_SYNTAX,
	NICK_NO_GHOST_SELF,
	NICK_GHOST_KILLED,
	NICK_GHOST_UNIDENTIFIED,
	NICK_GETPASS_SYNTAX,
	NICK_GETPASS_UNAVAILABLE,
	NICK_GETPASS_PASSWORD_IS,
	NICK_GETEMAIL_SYNTAX,
	NICK_GETEMAIL_EMAILS_ARE,
	NICK_GETEMAIL_NOT_USED,
	NICK_SENDPASS_SYNTAX,
	NICK_SENDPASS_UNAVAILABLE,
	NICK_SENDPASS_SUBJECT,
	NICK_SENDPASS,
	NICK_SENDPASS_OK,
	NICK_RESETPASS_SYNTAX,
	NICK_RESETPASS_SUBJECT,
	NICK_RESETPASS_MESSAGE,
	NICK_RESETPASS_COMPLETE,
	NICK_SUSPEND_SYNTAX,
	NICK_SUSPEND_SUCCEEDED,
	NICK_UNSUSPEND_SYNTAX,
	NICK_UNSUSPEND_SUCCEEDED,
	NICK_FORBID_SYNTAX,
	NICK_FORBID_SYNTAX_REASON,
	NICK_FORBID_SUCCEEDED,
	NICK_REQUESTED,
	NICK_REG_RESENT,
	NICK_REG_UNABLE,
	NICK_IS_PREREG,
	NICK_ENTER_REG_CODE,
	NICK_GETPASS_PASSCODE_IS,
	NICK_FORCE_REG,
	NICK_REG_MAIL_SUBJECT,
	NICK_REG_MAIL,
	NICK_CONFIRM_NOT_FOUND,
	NICK_CONFIRM_INVALID,
	NICK_CONFIRM_EXPIRED,
	NICK_CONFIRM_SUCCESS,
	CHAN_LEVEL_AUTOOP,
	CHAN_LEVEL_AUTOVOICE,
	CHAN_LEVEL_AUTOHALFOP,
	CHAN_LEVEL_AUTOPROTECT,
	CHAN_LEVEL_NOJOIN,
	CHAN_LEVEL_INVITE,
	CHAN_LEVEL_AKICK,
	CHAN_LEVEL_SET,
	CHAN_LEVEL_CLEARUSERS,
	CHAN_LEVEL_UNBAN,
	CHAN_LEVEL_OPDEOP,
	CHAN_LEVEL_ACCESS_LIST,
	CHAN_LEVEL_ACCESS_CHANGE,
	CHAN_LEVEL_MEMO,
	CHAN_LEVEL_ASSIGN,
	CHAN_LEVEL_BADWORDS,
	CHAN_LEVEL_NOKICK,
	CHAN_LEVEL_FANTASIA,
	CHAN_LEVEL_SAY,
	CHAN_LEVEL_GREET,
	CHAN_LEVEL_VOICEME,
	CHAN_LEVEL_VOICE,
	CHAN_LEVEL_GETKEY,
	CHAN_LEVEL_OPDEOPME,
	CHAN_LEVEL_HALFOPME,
	CHAN_LEVEL_HALFOP,
	CHAN_LEVEL_PROTECTME,
	CHAN_LEVEL_PROTECT,
	CHAN_LEVEL_KICKME,
	CHAN_LEVEL_KICK,
	CHAN_LEVEL_SIGNKICK,
	CHAN_LEVEL_BANME,
	CHAN_LEVEL_BAN,
	CHAN_LEVEL_TOPIC,
	CHAN_LEVEL_MODE,
	CHAN_LEVEL_INFO,
	CHAN_LEVEL_AUTOOWNER,
	CHAN_LEVEL_OWNER,
	CHAN_LEVEL_OWNERME,
	CHAN_LEVEL_FOUNDER,
	CHAN_IS_REGISTERED,
	CHAN_MAY_NOT_BE_USED,
	CHAN_NOT_ALLOWED_TO_JOIN,
	CHAN_X_INVALID,
	CHAN_REGISTER_SYNTAX,
	CHAN_REGISTER_DISABLED,
	CHAN_REGISTER_NOT_LOCAL,
	CHAN_MAY_NOT_BE_REGISTERED,
	CHAN_ALREADY_REGISTERED,
	CHAN_MUST_BE_CHANOP,
	CHAN_REACHED_CHANNEL_LIMIT,
	CHAN_EXCEEDED_CHANNEL_LIMIT,
	CHAN_REGISTERED,
	CHAN_SYMBOL_REQUIRED,
	CHAN_DROP_SYNTAX,
	CHAN_DROP_DISABLED,
	CHAN_DROPPED,
	CHAN_SASET_SYNTAX,
	CHAN_SASET_KEEPTOPIC_SYNTAX,
	CHAN_SASET_OPNOTICE_SYNTAX,
	CHAN_SASET_PEACE_SYNTAX,
	CHAN_SASET_PERSIST_SYNTAX,
	CHAN_SASET_PRIVATE_SYNTAX,
	CHAN_SASET_RESTRICTED_SYNTAX,
	CHAN_SASET_SECURE_SYNTAX,
	CHAN_SASET_SECUREFOUNDER_SYNTAX,
	CHAN_SASET_SECUREOPS_SYNTAX,
	CHAN_SASET_SIGNKICK_SYNTAX,
	CHAN_SASET_TOPICLOCK_SYNTAX,
	CHAN_SASET_XOP_SYNTAX,
	CHAN_SET_SYNTAX,
	CHAN_SET_DISABLED,
	CHAN_SETTING_CHANGED,
	CHAN_SETTING_UNSET,
	CHAN_SET_FOUNDER_TOO_MANY_CHANS,
	CHAN_FOUNDER_CHANGED,
	CHAN_SUCCESSOR_CHANGED,
	CHAN_SUCCESSOR_UNSET,
	CHAN_SUCCESSOR_IS_FOUNDER,
	CHAN_DESC_CHANGED,
	CHAN_SET_BANTYPE_INVALID,
	CHAN_SET_BANTYPE_CHANGED,
	CHAN_SET_MLOCK_DEPRECATED,
	CHAN_SET_KEEPTOPIC_SYNTAX,
	CHAN_SET_KEEPTOPIC_ON,
	CHAN_SET_KEEPTOPIC_OFF,
	CHAN_SET_TOPICLOCK_SYNTAX,
	CHAN_SET_TOPICLOCK_ON,
	CHAN_SET_TOPICLOCK_OFF,
	CHAN_SET_PEACE_SYNTAX,
	CHAN_SET_PEACE_ON,
	CHAN_SET_PEACE_OFF,
	CHAN_SET_PRIVATE_SYNTAX,
	CHAN_SET_PRIVATE_ON,
	CHAN_SET_PRIVATE_OFF,
	CHAN_SET_SECUREOPS_SYNTAX,
	CHAN_SET_SECUREOPS_ON,
	CHAN_SET_SECUREOPS_OFF,
	CHAN_SET_SECUREFOUNDER_SYNTAX,
	CHAN_SET_SECUREFOUNDER_ON,
	CHAN_SET_SECUREFOUNDER_OFF,
	CHAN_SET_RESTRICTED_SYNTAX,
	CHAN_SET_RESTRICTED_ON,
	CHAN_SET_RESTRICTED_OFF,
	CHAN_SET_SECURE_SYNTAX,
	CHAN_SET_SECURE_ON,
	CHAN_SET_SECURE_OFF,
	CHAN_SET_SIGNKICK_SYNTAX,
	CHAN_SET_SIGNKICK_ON,
	CHAN_SET_SIGNKICK_LEVEL,
	CHAN_SET_SIGNKICK_OFF,
	CHAN_SET_OPNOTICE_SYNTAX,
	CHAN_SET_OPNOTICE_ON,
	CHAN_SET_OPNOTICE_OFF,
	CHAN_SET_XOP_SYNTAX,
	CHAN_SET_XOP_ON,
	CHAN_SET_XOP_OFF,
	CHAN_SET_PERSIST_SYNTAX,
	CHAN_SET_PERSIST_ON,
	CHAN_SET_PERSIST_OFF,
	CHAN_SET_NOEXPIRE_SYNTAX,
	CHAN_SET_NOEXPIRE_ON,
	CHAN_SET_NOEXPIRE_OFF,
	CHAN_XOP_REACHED_LIMIT,
	CHAN_XOP_LIST_FORMAT,
	CHAN_XOP_ACCESS,
	CHAN_XOP_NOT_AVAILABLE,
	CHAN_QOP_SYNTAX,
	CHAN_QOP_DISABLED,
	CHAN_QOP_ADDED,
	CHAN_QOP_MOVED,
	CHAN_QOP_NO_SUCH_ENTRY,
	CHAN_QOP_NOT_FOUND,
	CHAN_QOP_NO_MATCH,
	CHAN_QOP_DELETED,
	CHAN_QOP_DELETED_ONE,
	CHAN_QOP_DELETED_SEVERAL,
	CHAN_QOP_LIST_EMPTY,
	CHAN_QOP_LIST_HEADER,
	CHAN_QOP_CLEAR,
	CHAN_AOP_SYNTAX,
	CHAN_AOP_DISABLED,
	CHAN_AOP_ADDED,
	CHAN_AOP_MOVED,
	CHAN_AOP_NO_SUCH_ENTRY,
	CHAN_AOP_NOT_FOUND,
	CHAN_AOP_NO_MATCH,
	CHAN_AOP_DELETED,
	CHAN_AOP_DELETED_ONE,
	CHAN_AOP_DELETED_SEVERAL,
	CHAN_AOP_LIST_EMPTY,
	CHAN_AOP_LIST_HEADER,
	CHAN_AOP_CLEAR,
	CHAN_HOP_SYNTAX,
	CHAN_HOP_DISABLED,
	CHAN_HOP_ADDED,
	CHAN_HOP_MOVED,
	CHAN_HOP_NO_SUCH_ENTRY,
	CHAN_HOP_NOT_FOUND,
	CHAN_HOP_NO_MATCH,
	CHAN_HOP_DELETED,
	CHAN_HOP_DELETED_ONE,
	CHAN_HOP_DELETED_SEVERAL,
	CHAN_HOP_LIST_EMPTY,
	CHAN_HOP_LIST_HEADER,
	CHAN_HOP_CLEAR,
	CHAN_SOP_SYNTAX,
	CHAN_SOP_DISABLED,
	CHAN_SOP_ADDED,
	CHAN_SOP_MOVED,
	CHAN_SOP_NO_SUCH_ENTRY,
	CHAN_SOP_NOT_FOUND,
	CHAN_SOP_NO_MATCH,
	CHAN_SOP_DELETED,
	CHAN_SOP_DELETED_ONE,
	CHAN_SOP_DELETED_SEVERAL,
	CHAN_SOP_LIST_EMPTY,
	CHAN_SOP_LIST_HEADER,
	CHAN_SOP_CLEAR,
	CHAN_VOP_SYNTAX,
	CHAN_VOP_DISABLED,
	CHAN_VOP_ADDED,
	CHAN_VOP_MOVED,
	CHAN_VOP_NO_SUCH_ENTRY,
	CHAN_VOP_NOT_FOUND,
	CHAN_VOP_NO_MATCH,
	CHAN_VOP_DELETED,
	CHAN_VOP_DELETED_ONE,
	CHAN_VOP_DELETED_SEVERAL,
	CHAN_VOP_LIST_EMPTY,
	CHAN_VOP_LIST_HEADER,
	CHAN_VOP_CLEAR,
	CHAN_ACCESS_SYNTAX,
	CHAN_ACCESS_XOP,
	CHAN_ACCESS_XOP_HOP,
	CHAN_ACCESS_DISABLED,
	CHAN_ACCESS_LEVEL_NONZERO,
	CHAN_ACCESS_LEVEL_RANGE,
	CHAN_ACCESS_REACHED_LIMIT,
	CHAN_ACCESS_LEVEL_UNCHANGED,
	CHAN_ACCESS_LEVEL_CHANGED,
	CHAN_ACCESS_ADDED,
	CHAN_ACCESS_NOT_FOUND,
	CHAN_ACCESS_NO_MATCH,
	CHAN_ACCESS_DELETED,
	CHAN_ACCESS_DELETED_ONE,
	CHAN_ACCESS_DELETED_SEVERAL,
	CHAN_ACCESS_LIST_EMPTY,
	CHAN_ACCESS_LIST_HEADER,
	CHAN_ACCESS_LIST_FOOTER,
	CHAN_ACCESS_LIST_XOP_FORMAT,
	CHAN_ACCESS_LIST_AXS_FORMAT,
	CHAN_ACCESS_CLEAR,
	CHAN_ACCESS_VIEW_XOP_FORMAT,
	CHAN_ACCESS_VIEW_AXS_FORMAT,
	CHAN_AKICK_SYNTAX,
	CHAN_AKICK_DISABLED,
	CHAN_AKICK_ALREADY_EXISTS,
	CHAN_AKICK_REACHED_LIMIT,
	CHAN_AKICK_ADDED,
	CHAN_AKICK_NOT_FOUND,
	CHAN_AKICK_NO_MATCH,
	CHAN_AKICK_DELETED,
	CHAN_AKICK_DELETED_ONE,
	CHAN_AKICK_DELETED_SEVERAL,
	CHAN_AKICK_LIST_EMPTY,
	CHAN_AKICK_LIST_HEADER,
	CHAN_AKICK_LIST_FORMAT,
	CHAN_AKICK_VIEW_FORMAT,
	CHAN_AKICK_LAST_USED,
	CHAN_AKICK_ENFORCE_DONE,
	CHAN_AKICK_CLEAR,
	CHAN_LEVELS_SYNTAX,
	CHAN_LEVELS_XOP,
	CHAN_LEVELS_RANGE,
	CHAN_LEVELS_CHANGED,
	CHAN_LEVELS_CHANGED_FOUNDER,
	CHAN_LEVELS_UNKNOWN,
	CHAN_LEVELS_DISABLED,
	CHAN_LEVELS_LIST_HEADER,
	CHAN_LEVELS_LIST_DISABLED,
	CHAN_LEVELS_LIST_FOUNDER,
	CHAN_LEVELS_LIST_NORMAL,
	CHAN_LEVELS_RESET,
	CHAN_STATUS_SYNTAX,
	CHAN_STATUS_NOT_REGGED,
	CHAN_STATUS_NOTONLINE,
	CHAN_STATUS_INFO,
	CHAN_INFO_SYNTAX,
	CHAN_INFO_HEADER,
	CHAN_INFO_NO_FOUNDER,
	CHAN_INFO_NO_SUCCESSOR,
	CHAN_INFO_DESCRIPTION,
	CHAN_INFO_TIME_REGGED,
	CHAN_INFO_LAST_USED,
	CHAN_INFO_LAST_TOPIC,
	CHAN_INFO_TOPIC_SET_BY,
	CHAN_INFO_BANTYPE,
	CHAN_INFO_OPT_KEEPTOPIC,
	CHAN_INFO_OPT_OPNOTICE,
	CHAN_INFO_OPT_PEACE,
	CHAN_INFO_OPT_RESTRICTED,
	CHAN_INFO_OPT_SECURE,
	CHAN_INFO_OPT_SECUREOPS,
	CHAN_INFO_OPT_SECUREFOUNDER,
	CHAN_INFO_OPT_SIGNKICK,
	CHAN_INFO_OPT_TOPICLOCK,
	CHAN_INFO_OPT_XOP,
	CHAN_INFO_OPT_PERSIST,
	CHAN_INFO_MODE_LOCK,
	CHAN_INFO_EXPIRE,
	CHAN_INFO_NO_EXPIRE,
	CHAN_LIST_END,
	CHAN_INVITE_SYNTAX,
	CHAN_INVITE_ALREADY_IN,
	CHAN_INVITE_SUCCESS,
	CHAN_INVITE_OTHER_SUCCESS,
	CHAN_UNBAN_SYNTAX,
	CHAN_UNBANNED,
	CHAN_UNBANNED_OTHER,
	CHAN_TOPIC_SYNTAX,
	CHAN_CLEARUSERS_SYNTAX,
	CHAN_CLEARED_USERS,
	CHAN_CLONED,
	CHAN_CLONED_ACCESS,
	CHAN_CLONED_AKICK,
	CHAN_CLONED_BADWORDS,
	CHAN_CLONE_SYNTAX,
	CHAN_GETKEY_SYNTAX,
	CHAN_GETKEY_NOKEY,
	CHAN_GETKEY_KEY,
	CHAN_FORBID_SYNTAX,
	CHAN_FORBID_SYNTAX_REASON,
	CHAN_FORBID_SUCCEEDED,
	CHAN_FORBID_REASON,
	CHAN_SUSPEND_SYNTAX,
	CHAN_SUSPEND_SYNTAX_REASON,
	CHAN_SUSPEND_SUCCEEDED,
	CHAN_SUSPEND_REASON,
	CHAN_UNSUSPEND_SYNTAX,
	CHAN_UNSUSPEND_ERROR,
	CHAN_UNSUSPEND_SUCCEEDED,
	CHAN_UNSUSPEND_FAILED,
	CHAN_EXCEPTED,
	CHAN_OP_SYNTAX,
	CHAN_HALFOP_SYNTAX,
	CHAN_VOICE_SYNTAX,
	CHAN_PROTECT_SYNTAX,
	CHAN_OWNER_SYNTAX,
	CHAN_DEOP_SYNTAX,
	CHAN_DEHALFOP_SYNTAX,
	CHAN_DEVOICE_SYNTAX,
	CHAN_DEPROTECT_SYNTAX,
	CHAN_DEOWNER_SYNTAX,
	CHAN_KICK_SYNTAX,
	CHAN_BAN_SYNTAX,
	CHAN_MODE_SYNTAX,
	CHAN_MODE_LOCK_UNKNOWN,
	CHAN_MODE_LOCK_MISSING_PARAM,
	CHAN_MODE_LOCK_NONE,
	CHAN_MODE_LOCK_HEADER,
	CHAN_MODE_LOCKED,
	CHAN_MODE_NOT_LOCKED,
	CHAN_MODE_UNLOCKED,
	CHAN_MODE_LIST_FMT,
	CHAN_ENTRYMSG_LIST_HEADER,
	CHAN_ENTRYMSG_LIST_ENTRY,
	CHAN_ENTRYMSG_LIST_END,
	CHAN_ENTRYMSG_LIST_EMPTY,
	CHAN_ENTRYMSG_LIST_FULL,
	CHAN_ENTRYMSG_ADDED,
	CHAN_ENTRYMSG_DELETED,
	CHAN_ENTRYMSG_NOT_FOUND,
	CHAN_ENTRYMSG_CLEARED,
	CHAN_ENTRYMSG_SYNTAX,
	MEMO_HAVE_NEW_MEMO,
	MEMO_HAVE_NEW_MEMOS,
	MEMO_TYPE_READ_LAST,
	MEMO_TYPE_READ_NUM,
	MEMO_TYPE_LIST_NEW,
	MEMO_AT_LIMIT,
	MEMO_OVER_LIMIT,
	MEMO_X_MANY_NOTICE,
	MEMO_X_ONE_NOTICE,
	MEMO_NEW_X_MEMO_ARRIVED,
	MEMO_NEW_MEMO_ARRIVED,
	MEMO_HAVE_NO_MEMOS,
	MEMO_X_HAS_NO_MEMOS,
	MEMO_SEND_SYNTAX,
	MEMO_SENDALL_SYNTAX,
	MEMO_SEND_DISABLED,
	MEMO_SEND_PLEASE_WAIT,
	MEMO_X_GETS_NO_MEMOS,
	MEMO_X_HAS_TOO_MANY_MEMOS,
	MEMO_SENT,
	MEMO_MASS_SENT,
	MEMO_STAFF_SYNTAX,
	MEMO_CANCEL_SYNTAX,
	MEMO_CANCEL_NONE,
	MEMO_CANCELLED,
	MEMO_LIST_SYNTAX,
	MEMO_HAVE_NO_NEW_MEMOS,
	MEMO_X_HAS_NO_NEW_MEMOS,
	MEMO_LIST_MEMOS,
	MEMO_LIST_NEW_MEMOS,
	MEMO_LIST_CHAN_MEMOS,
	MEMO_LIST_CHAN_NEW_MEMOS,
	MEMO_LIST_HEADER,
	MEMO_LIST_FORMAT,
	MEMO_READ_SYNTAX,
	MEMO_HEADER,
	MEMO_CHAN_HEADER,
	MEMO_TEXT,
	MEMO_DEL_SYNTAX,
	MEMO_DELETED_ONE,
	MEMO_DELETED_ALL,
	MEMO_CHAN_DELETED_ALL,
	MEMO_SET_DISABLED,
	MEMO_SET_NOTIFY_SYNTAX,
	MEMO_SET_NOTIFY_ON,
	MEMO_SET_NOTIFY_LOGON,
	MEMO_SET_NOTIFY_NEW,
	MEMO_SET_NOTIFY_OFF,
	MEMO_SET_NOTIFY_MAIL,
	MEMO_SET_NOTIFY_NOMAIL,
	MEMO_SET_NOTIFY_INVALIDMAIL,
	MEMO_SET_LIMIT_SYNTAX,
	MEMO_SET_LIMIT_SERVADMIN_SYNTAX,
	MEMO_SET_YOUR_LIMIT_FORBIDDEN,
	MEMO_SET_LIMIT_FORBIDDEN,
	MEMO_SET_YOUR_LIMIT_TOO_HIGH,
	MEMO_SET_LIMIT_TOO_HIGH,
	MEMO_SET_LIMIT_OVERFLOW,
	MEMO_SET_YOUR_LIMIT,
	MEMO_SET_YOUR_LIMIT_ZERO,
	MEMO_UNSET_YOUR_LIMIT,
	MEMO_SET_LIMIT,
	MEMO_SET_LIMIT_ZERO,
	MEMO_UNSET_LIMIT,
	MEMO_INFO_NO_MEMOS,
	MEMO_INFO_MEMO,
	MEMO_INFO_MEMO_UNREAD,
	MEMO_INFO_MEMOS,
	MEMO_INFO_MEMOS_ONE_UNREAD,
	MEMO_INFO_MEMOS_SOME_UNREAD,
	MEMO_INFO_MEMOS_ALL_UNREAD,
	MEMO_INFO_LIMIT,
	MEMO_INFO_HARD_LIMIT,
	MEMO_INFO_LIMIT_ZERO,
	MEMO_INFO_HARD_LIMIT_ZERO,
	MEMO_INFO_NO_LIMIT,
	MEMO_INFO_NOTIFY_OFF,
	MEMO_INFO_NOTIFY_ON,
	MEMO_INFO_NOTIFY_RECEIVE,
	MEMO_INFO_NOTIFY_SIGNON,
	MEMO_INFO_X_NO_MEMOS,
	MEMO_INFO_X_MEMO,
	MEMO_INFO_X_MEMO_UNREAD,
	MEMO_INFO_X_MEMOS,
	MEMO_INFO_X_MEMOS_ONE_UNREAD,
	MEMO_INFO_X_MEMOS_SOME_UNREAD,
	MEMO_INFO_X_MEMOS_ALL_UNREAD,
	MEMO_INFO_X_LIMIT,
	MEMO_INFO_X_HARD_LIMIT,
	MEMO_INFO_X_NO_LIMIT,
	MEMO_INFO_X_NOTIFY_OFF,
	MEMO_INFO_X_NOTIFY_ON,
	MEMO_INFO_X_NOTIFY_RECEIVE,
	MEMO_INFO_X_NOTIFY_SIGNON,
	MEMO_MAIL_SUBJECT,
	NICK_MAIL_TEXT,
	MEMO_RSEND_PLEASE_WAIT,
	MEMO_RSEND_DISABLED,
	MEMO_RSEND_SYNTAX,
	MEMO_RSEND_NICK_MEMO_TEXT,
	MEMO_RSEND_CHAN_MEMO_TEXT,
	MEMO_RSEND_USER_NOTIFICATION,
	MEMO_CHECK_SYNTAX,
	MEMO_CHECK_NOT_READ,
	MEMO_CHECK_READ,
	MEMO_CHECK_NO_MEMO,
	MEMO_NO_RSEND_SELF,
	MEMO_IGNORE_SYNTAX,
	MEMO_IGNORE_ADD,
	MEMO_IGNORE_ALREADY_IGNORED,
	MEMO_IGNORE_DEL,
	MEMO_IGNORE_NOT_IGNORED,
	MEMO_IGNORE_LIST_EMPTY,
	MEMO_IGNORE_LIST_HEADER,
	BOT_DOES_NOT_EXIST,
	BOT_NOT_ASSIGNED,
	BOT_NOT_ON_CHANNEL,
	BOT_REASON_BADWORD,
	BOT_REASON_BADWORD_GENTLE,
	BOT_REASON_BOLD,
	BOT_REASON_CAPS,
	BOT_REASON_COLOR,
	BOT_REASON_FLOOD,
	BOT_REASON_REPEAT,
	BOT_REASON_REVERSE,
	BOT_REASON_UNDERLINE,
	BOT_REASON_ITALIC,
	BOT_REASON_AMSGS,
	BOT_BOT_SYNTAX,
	BOT_BOT_ALREADY_EXISTS,
	BOT_BOT_CREATION_FAILED,
	BOT_BOT_READONLY,
	BOT_BOT_ADDED,
	BOT_BOT_ANY_CHANGES,
	BOT_BOT_CHANGED,
	BOT_BOT_DELETED,
	BOT_BOTLIST_HEADER,
	BOT_BOTLIST_PRIVATE_HEADER,
	BOT_BOTLIST_FOOTER,
	BOT_BOTLIST_EMPTY,
	BOT_ASSIGN_SYNTAX,
	BOT_ASSIGN_READONLY,
	BOT_ASSIGN_ALREADY,
	BOT_ASSIGN_ASSIGNED,
	BOT_UNASSIGN_SYNTAX,
	BOT_UNASSIGN_UNASSIGNED,
	BOT_UNASSIGN_PERSISTANT_CHAN,
	BOT_INFO_SYNTAX,
	BOT_INFO_NOT_FOUND,
	BOT_INFO_BOT_HEADER,
	BOT_INFO_BOT_MASK,
	BOT_INFO_BOT_REALNAME,
	BOT_INFO_BOT_CREATED,
	BOT_INFO_BOT_USAGE,
	BOT_INFO_BOT_OPTIONS,
	BOT_INFO_CHAN_BOT,
	BOT_INFO_CHAN_BOT_NONE,
	BOT_INFO_CHAN_KICK_BADWORDS,
	BOT_INFO_CHAN_KICK_BADWORDS_BAN,
	BOT_INFO_CHAN_KICK_BOLDS,
	BOT_INFO_CHAN_KICK_BOLDS_BAN,
	BOT_INFO_CHAN_KICK_CAPS_ON,
	BOT_INFO_CHAN_KICK_CAPS_BAN,
	BOT_INFO_CHAN_KICK_CAPS_OFF,
	BOT_INFO_CHAN_KICK_COLORS,
	BOT_INFO_CHAN_KICK_COLORS_BAN,
	BOT_INFO_CHAN_KICK_FLOOD_ON,
	BOT_INFO_CHAN_KICK_FLOOD_BAN,
	BOT_INFO_CHAN_KICK_FLOOD_OFF,
	BOT_INFO_CHAN_KICK_REPEAT_ON,
	BOT_INFO_CHAN_KICK_REPEAT_BAN,
	BOT_INFO_CHAN_KICK_REPEAT_OFF,
	BOT_INFO_CHAN_KICK_REVERSES,
	BOT_INFO_CHAN_KICK_REVERSES_BAN,
	BOT_INFO_CHAN_KICK_UNDERLINES,
	BOT_INFO_CHAN_KICK_UNDERLINES_BAN,
	BOT_INFO_CHAN_KICK_ITALICS,
	BOT_INFO_CHAN_KICK_ITALICS_BAN,
	BOT_INFO_CHAN_MSG,
	BOT_INFO_ACTIVE,
	BOT_INFO_INACTIVE,
	BOT_INFO_CHAN_OPTIONS,
	BOT_INFO_OPT_DONTKICKOPS,
	BOT_INFO_OPT_DONTKICKVOICES,
	BOT_INFO_OPT_FANTASY,
	BOT_INFO_OPT_GREET,
	BOT_INFO_OPT_NOBOT,
	BOT_INFO_OPT_SYMBIOSIS,
	BOT_INFO_OPT_NONE,
	BOT_SET_SYNTAX,
	BOT_SET_DISABLED,
	BOT_SET_UNKNOWN,
	BOT_SET_DONTKICKOPS_SYNTAX,
	BOT_SET_DONTKICKOPS_ON,
	BOT_SET_DONTKICKOPS_OFF,
	BOT_SET_DONTKICKVOICES_SYNTAX,
	BOT_SET_DONTKICKVOICES_ON,
	BOT_SET_DONTKICKVOICES_OFF,
	BOT_SET_FANTASY_SYNTAX,
	BOT_SET_FANTASY_ON,
	BOT_SET_FANTASY_OFF,
	BOT_SET_GREET_SYNTAX,
	BOT_SET_GREET_ON,
	BOT_SET_GREET_OFF,
	BOT_SET_NOBOT_SYNTAX,
	BOT_SET_NOBOT_ON,
	BOT_SET_NOBOT_OFF,
	BOT_SET_PRIVATE_SYNTAX,
	BOT_SET_PRIVATE_ON,
	BOT_SET_PRIVATE_OFF,
	BOT_SET_SYMBIOSIS_SYNTAX,
	BOT_SET_SYMBIOSIS_ON,
	BOT_SET_SYMBIOSIS_OFF,
	BOT_SET_MSG_SYNTAX,
	BOT_SET_MSG_OFF,
	BOT_SET_MSG_PRIVMSG,
	BOT_SET_MSG_NOTICE,
	BOT_SET_MSG_NOTICEOPS,
	BOT_KICK_SYNTAX,
	BOT_KICK_DISABLED,
	BOT_KICK_UNKNOWN,
	BOT_KICK_BAD_TTB,
	BOT_KICK_BADWORDS_ON,
	BOT_KICK_BADWORDS_ON_BAN,
	BOT_KICK_BADWORDS_OFF,
	BOT_KICK_BOLDS_ON,
	BOT_KICK_BOLDS_ON_BAN,
	BOT_KICK_BOLDS_OFF,
	BOT_KICK_CAPS_ON,
	BOT_KICK_CAPS_ON_BAN,
	BOT_KICK_CAPS_OFF,
	BOT_KICK_COLORS_ON,
	BOT_KICK_COLORS_ON_BAN,
	BOT_KICK_COLORS_OFF,
	BOT_KICK_FLOOD_ON,
	BOT_KICK_FLOOD_ON_BAN,
	BOT_KICK_FLOOD_OFF,
	BOT_KICK_REPEAT_ON,
	BOT_KICK_REPEAT_ON_BAN,
	BOT_KICK_REPEAT_OFF,
	BOT_KICK_REVERSES_ON,
	BOT_KICK_REVERSES_ON_BAN,
	BOT_KICK_REVERSES_OFF,
	BOT_KICK_UNDERLINES_ON,
	BOT_KICK_UNDERLINES_ON_BAN,
	BOT_KICK_UNDERLINES_OFF,
	BOT_KICK_ITALICS_ON,
	BOT_KICK_ITALICS_ON_BAN,
	BOT_KICK_ITALICS_OFF,
	BOT_KICK_AMSGS_ON,
	BOT_KICK_AMSGS_ON_BAN,
	BOT_KICK_AMSGS_OFF,
	BOT_BADWORDS_SYNTAX,
	BOT_BADWORDS_DISABLED,
	BOT_BADWORDS_REACHED_LIMIT,
	BOT_BADWORDS_ALREADY_EXISTS,
	BOT_BADWORDS_ADDED,
	BOT_BADWORDS_NOT_FOUND,
	BOT_BADWORDS_NO_MATCH,
	BOT_BADWORDS_DELETED,
	BOT_BADWORDS_DELETED_ONE,
	BOT_BADWORDS_DELETED_SEVERAL,
	BOT_BADWORDS_LIST_EMPTY,
	BOT_BADWORDS_LIST_HEADER,
	BOT_BADWORDS_LIST_FORMAT,
	BOT_BADWORDS_CLEAR,
	BOT_SAY_SYNTAX,
	BOT_ACT_SYNTAX,
	BOT_EXCEPT,
	BOT_BAD_NICK,
	BOT_BAD_HOST,
	BOT_BAD_IDENT,
	BOT_LONG_IDENT,
	BOT_LONG_HOST,
	OPER_BOUNCY_MODES,
	OPER_BOUNCY_MODES_U_LINE,
	OPER_GLOBAL_SYNTAX,
	OPER_STATS_UNKNOWN_OPTION,
	OPER_STATS_CURRENT_USERS,
	OPER_STATS_MAX_USERS,
	OPER_STATS_UPTIME_DHMS,
	OPER_STATS_UPTIME_1DHMS,
	OPER_STATS_UPTIME_HMS,
	OPER_STATS_UPTIME_H1MS,
	OPER_STATS_UPTIME_1HMS,
	OPER_STATS_UPTIME_1H1MS,
	OPER_STATS_UPTIME_MS,
	OPER_STATS_UPTIME_M1S,
	OPER_STATS_UPTIME_1MS,
	OPER_STATS_UPTIME_1M1S,
	OPER_STATS_BYTES_READ,
	OPER_STATS_BYTES_WRITTEN,
	OPER_STATS_USER_MEM,
	OPER_STATS_CHANNEL_MEM,
	OPER_STATS_GROUPS_MEM,
	OPER_STATS_ALIASES_MEM,
	OPER_STATS_CHANSERV_MEM,
	OPER_STATS_BOTSERV_MEM,
	OPER_STATS_HOSTSERV_MEM,
	OPER_STATS_OPERSERV_MEM,
	OPER_STATS_SESSIONS_MEM,
	OPER_STATS_AKILL_COUNT,
	OPER_STATS_AKILL_EXPIRE_DAYS,
	OPER_STATS_AKILL_EXPIRE_DAY,
	OPER_STATS_AKILL_EXPIRE_HOURS,
	OPER_STATS_AKILL_EXPIRE_HOUR,
	OPER_STATS_AKILL_EXPIRE_MINS,
	OPER_STATS_AKILL_EXPIRE_MIN,
	OPER_STATS_AKILL_EXPIRE_NONE,
	OPER_STATS_SNLINE_COUNT,
	OPER_STATS_SNLINE_EXPIRE_DAYS,
	OPER_STATS_SNLINE_EXPIRE_DAY,
	OPER_STATS_SNLINE_EXPIRE_HOURS,
	OPER_STATS_SNLINE_EXPIRE_HOUR,
	OPER_STATS_SNLINE_EXPIRE_MINS,
	OPER_STATS_SNLINE_EXPIRE_MIN,
	OPER_STATS_SNLINE_EXPIRE_NONE,
	OPER_STATS_SQLINE_COUNT,
	OPER_STATS_SQLINE_EXPIRE_DAYS,
	OPER_STATS_SQLINE_EXPIRE_DAY,
	OPER_STATS_SQLINE_EXPIRE_HOURS,
	OPER_STATS_SQLINE_EXPIRE_HOUR,
	OPER_STATS_SQLINE_EXPIRE_MINS,
	OPER_STATS_SQLINE_EXPIRE_MIN,
	OPER_STATS_SQLINE_EXPIRE_NONE,
	OPER_STATS_SZLINE_COUNT,
	OPER_STATS_SZLINE_EXPIRE_DAYS,
	OPER_STATS_SZLINE_EXPIRE_DAY,
	OPER_STATS_SZLINE_EXPIRE_HOURS,
	OPER_STATS_SZLINE_EXPIRE_HOUR,
	OPER_STATS_SZLINE_EXPIRE_MINS,
	OPER_STATS_SZLINE_EXPIRE_MIN,
	OPER_STATS_SZLINE_EXPIRE_NONE,
	OPER_STATS_RESET,
	OPER_STATS_UPLINK_SERVER,
	OPER_STATS_UPLINK_CAPAB,
	OPER_STATS_UPLINK_SERVER_COUNT,
	OPER_MODE_SYNTAX,
	OPER_UMODE_SYNTAX,
	OPER_UMODE_SUCCESS,
	OPER_UMODE_CHANGED,
	OPER_OLINE_SYNTAX,
	OPER_OLINE_SUCCESS,
	OPER_OLINE_IRCOP,
	OPER_KICK_SYNTAX,
	OPER_SVSNICK_SYNTAX,
	OPER_SVSNICK_NEWNICK,
	OPER_AKILL_SYNTAX,
	OPER_AKILL_EXISTS,
	OPER_ALREADY_COVERED,
	OPER_AKILL_NO_NICK,
	OPER_AKILL_ADDED,
	OPER_EXPIRY_CHANGED,
	OPER_AKILL_NOT_FOUND,
	OPER_AKILL_NO_MATCH,
	OPER_AKILL_DELETED,
	OPER_AKILL_DELETED_ONE,
	OPER_AKILL_DELETED_SEVERAL,
	OPER_LIST_EMPTY,
	OPER_AKILL_LIST_HEADER,
	OPER_LIST_FORMAT,
	OPER_AKILL_VIEW_HEADER,
	OPER_VIEW_FORMAT,
	OPER_AKILL_CLEAR,
	OPER_CHANKILL_SYNTAX,
	OPER_SNLINE_SYNTAX,
	OPER_SNLINE_EXISTS,
	OPER_SNLINE_ADDED,
	OPER_SNLINE_NOT_FOUND,
	OPER_SNLINE_NO_MATCH,
	OPER_SNLINE_DELETED,
	OPER_SNLINE_DELETED_ONE,
	OPER_SNLINE_DELETED_SEVERAL,
	OPER_SNLINE_LIST_EMPTY,
	OPER_SNLINE_LIST_HEADER,
	OPER_SNLINE_VIEW_HEADER,
	OPER_SNLINE_CLEAR,
	OPER_SQLINE_SYNTAX,
	OPER_SQLINE_CHANNELS_UNSUPPORTED,
	OPER_SQLINE_EXISTS,
	OPER_SQLINE_ADDED,
	OPER_SQLINE_NOT_FOUND,
	OPER_SQLINE_NO_MATCH,
	OPER_SQLINE_DELETED,
	OPER_SQLINE_DELETED_ONE,
	OPER_SQLINE_DELETED_SEVERAL,
	OPER_SQLINE_LIST_EMPTY,
	OPER_SQLINE_LIST_HEADER,
	OPER_SQLINE_VIEW_HEADER,
	OPER_SQLINE_CLEAR,
	OPER_SZLINE_SYNTAX,
	OPER_SZLINE_EXISTS,
	OPER_SZLINE_ONLY_IPS,
	OPER_SZLINE_ADDED,
	OPER_SZLINE_NOT_FOUND,
	OPER_SZLINE_NO_MATCH,
	OPER_SZLINE_DELETED,
	OPER_SZLINE_DELETED_ONE,
	OPER_SZLINE_DELETED_SEVERAL,
	OPER_SZLINE_LIST_EMPTY,
	OPER_SZLINE_LIST_HEADER,
	OPER_SZLINE_VIEW_HEADER,
	OPER_SZLINE_CLEAR,
	OPER_SET_SYNTAX,
	OPER_SET_READONLY_ON,
	OPER_SET_READONLY_OFF,
	OPER_SET_READONLY_ERROR,
	OPER_SET_DEBUG_ON,
	OPER_SET_DEBUG_OFF,
	OPER_SET_DEBUG_LEVEL,
	OPER_SET_DEBUG_ERROR,
	OPER_SET_NOEXPIRE_ON,
	OPER_SET_NOEXPIRE_OFF,
	OPER_SET_NOEXPIRE_ERROR,
	OPER_SET_UNKNOWN_OPTION,
	OPER_SET_LIST_OPTION_ON,
	OPER_SET_LIST_OPTION_OFF,
	OPER_NOOP_SYNTAX,
	OPER_NOOP_SET,
	OPER_NOOP_REVOKE,
	OPER_JUPE_SYNTAX,
	OPER_JUPE_HOST_ERROR,
	OPER_JUPE_INVALID_SERVER,
	OPER_UPDATING,
	OPER_RELOAD,
	OPER_IGNORE_SYNTAX,
	OPER_IGNORE_VALID_TIME,
	OPER_IGNORE_TIME_DONE,
	OPER_IGNORE_PERM_DONE,
	OPER_IGNORE_DEL_DONE,
	OPER_IGNORE_LIST,
	OPER_IGNORE_LIST_NOMATCH,
	OPER_IGNORE_LIST_EMPTY,
	OPER_IGNORE_LIST_CLEARED,
	OPER_CHANLIST_HEADER,
	OPER_CHANLIST_HEADER_USER,
	OPER_CHANLIST_RECORD,
	OPER_CHANLIST_END,
	OPER_USERLIST_HEADER,
	OPER_USERLIST_HEADER_CHAN,
	OPER_USERLIST_RECORD,
	OPER_USERLIST_END,
	OPER_SUPER_ADMIN_ON,
	OPER_SUPER_ADMIN_OFF,
	OPER_SUPER_ADMIN_SYNTAX,
	OPER_SUPER_ADMIN_WALL_ON,
	OPER_SUPER_ADMIN_WALL_OFF,
	OPER_STAFF_LIST_HEADER,
	OPER_STAFF_FORMAT,
	OPER_STAFF_AFORMAT,
	OPER_DEFCON_SYNTAX,
	OPER_DEFCON_DENIED,
	OPER_DEFCON_CHANGED,
	OPER_DEFCON_WALL,
	DEFCON_GLOBAL,
	OPER_MODULE_LOADED,
	OPER_MODULE_UNLOADED,
	OPER_MODULE_RELOADED,
	OPER_MODULE_LOAD_FAIL,
	OPER_MODULE_REMOVE_FAIL,
	OPER_MODULE_NO_UNLOAD,
	OPER_MODULE_ALREADY_LOADED,
	OPER_MODULE_ISNT_LOADED,
	OPER_MODULE_LOAD_SYNTAX,
	OPER_MODULE_UNLOAD_SYNTAX,
	OPER_MODULE_RELOAD_SYNTAX,
	OPER_MODULE_LIST_HEADER,
	OPER_MODULE_LIST,
	OPER_MODULE_LIST_FOOTER,
	OPER_MODULE_INFO_LIST,
	OPER_MODULE_CMD_LIST,
	OPER_MODULE_NO_LIST,
	OPER_MODULE_NO_INFO,
	OPER_MODULE_INFO_SYNTAX,
	OPER_EXCEPTION_SYNTAX,
	OPER_EXCEPTION_DISABLED,
	OPER_EXCEPTION_ADDED,
	OPER_EXCEPTION_MOVED,
	OPER_EXCEPTION_NOT_FOUND,
	OPER_EXCEPTION_NO_MATCH,
	OPER_EXCEPTION_DELETED,
	OPER_EXCEPTION_DELETED_ONE,
	OPER_EXCEPTION_DELETED_SEVERAL,
	OPER_EXCEPTION_LIST_HEADER,
	OPER_EXCEPTION_LIST_FORMAT,
	OPER_EXCEPTION_LIST_COLHEAD,
	OPER_EXCEPTION_VIEW_FORMAT,
	OPER_EXCEPTION_INVALID_LIMIT,
	OPER_EXCEPTION_INVALID_HOSTMASK,
	OPER_EXCEPTION_EXISTS,
	OPER_EXCEPTION_CHANGED,
	OPER_SESSION_LIST_SYNTAX,
	OPER_SESSION_INVALID_THRESHOLD,
	OPER_SESSION_NOT_FOUND,
	OPER_SESSION_LIST_HEADER,
	OPER_SESSION_LIST_COLHEAD,
	OPER_SESSION_LIST_FORMAT,
	OPER_SESSION_VIEW_FORMAT,
	OPER_HELP_EXCEPTION,
	OPER_HELP_SESSION,
	OPER_HELP_STAFF,
	OPER_HELP_DEFCON,
	OPER_HELP_DEFCON_NO_NEW_CHANNELS,
	OPER_HELP_DEFCON_NO_NEW_NICKS,
	OPER_HELP_DEFCON_NO_MLOCK_CHANGE,
	OPER_HELP_DEFCON_FORCE_CHAN_MODES,
	OPER_HELP_DEFCON_REDUCE_SESSION,
	OPER_HELP_DEFCON_NO_NEW_CLIENTS,
	OPER_HELP_DEFCON_OPER_ONLY,
	OPER_HELP_DEFCON_SILENT_OPER_ONLY,
	OPER_HELP_DEFCON_AKILL_NEW_CLIENTS,
	OPER_HELP_DEFCON_NO_NEW_MEMOS,
	OPER_HELP_CHANKILL,
	NEWS_LOGON_TEXT,
	NEWS_OPER_TEXT,
	NEWS_RANDOM_TEXT,
	NEWS_LOGON_SYNTAX,
	NEWS_LOGON_LIST_HEADER,
	NEWS_LIST_ENTRY,
	NEWS_LOGON_LIST_NONE,
	NEWS_LOGON_ADD_SYNTAX,
	NEWS_ADD_FULL,
	NEWS_LOGON_ADDED,
	NEWS_LOGON_DEL_SYNTAX,
	NEWS_LOGON_DEL_NOT_FOUND,
	NEWS_LOGON_DELETED,
	NEWS_LOGON_DEL_NONE,
	NEWS_LOGON_DELETED_ALL,
	NEWS_OPER_SYNTAX,
	NEWS_OPER_LIST_HEADER,
	NEWS_OPER_LIST_NONE,
	NEWS_OPER_ADD_SYNTAX,
	NEWS_OPER_ADDED,
	NEWS_OPER_DEL_SYNTAX,
	NEWS_OPER_DEL_NOT_FOUND,
	NEWS_OPER_DELETED,
	NEWS_OPER_DEL_NONE,
	NEWS_OPER_DELETED_ALL,
	NEWS_RANDOM_SYNTAX,
	NEWS_RANDOM_LIST_HEADER,
	NEWS_RANDOM_LIST_NONE,
	NEWS_RANDOM_ADD_SYNTAX,
	NEWS_RANDOM_ADDED,
	NEWS_RANDOM_DEL_SYNTAX,
	NEWS_RANDOM_DEL_NOT_FOUND,
	NEWS_RANDOM_DELETED,
	NEWS_RANDOM_DEL_NONE,
	NEWS_RANDOM_DELETED_ALL,
	NEWS_HELP_LOGON,
	NEWS_HELP_OPER,
	NEWS_HELP_RANDOM,
	NICK_HELP_CMD_CONFIRM,
	NICK_HELP_CMD_RESEND,
	NICK_HELP_CMD_REGISTER,
	NICK_HELP_CMD_GROUP,
	NICK_HELP_CMD_UNGROUP,
	NICK_HELP_CMD_IDENTIFY,
	NICK_HELP_CMD_ACCESS,
	NICK_HELP_CMD_SET,
	NICK_HELP_CMD_SASET,
	NICK_HELP_CMD_DROP,
	NICK_HELP_CMD_RECOVER,
	NICK_HELP_CMD_RELEASE,
	NICK_HELP_CMD_SENDPASS,
	NICK_HELP_CMD_RESETPASS,
	NICK_HELP_CMD_GHOST,
	NICK_HELP_CMD_ALIST,
	NICK_HELP_CMD_GLIST,
	NICK_HELP_CMD_INFO,
	NICK_HELP_CMD_LIST,
	NICK_HELP_CMD_LOGOUT,
	NICK_HELP_CMD_STATUS,
	NICK_HELP_CMD_UPDATE,
	NICK_HELP_CMD_GETPASS,
	NICK_HELP_CMD_GETEMAIL,
	NICK_HELP_CMD_FORBID,
	NICK_HELP_CMD_SUSPEND,
	NICK_HELP_CMD_UNSUSPEND,
	NICK_HELP,
	NICK_HELP_FOOTER,
	NICK_HELP_EXPIRES,
	NICK_HELP_REGISTER,
	NICK_HELP_GROUP,
	NICK_HELP_UNGROUP,
	NICK_HELP_IDENTIFY,
	NICK_HELP_UPDATE,
	NICK_HELP_LOGOUT,
	NICK_HELP_DROP,
	NICK_HELP_ACCESS,
	NICK_HELP_SET_HEAD,
	NICK_HELP_CMD_SET_DISPLAY,
	NICK_HELP_CMD_SET_PASSWORD,
	NICK_HELP_CMD_SET_LANGUAGE,
	NICK_HELP_CMD_SET_EMAIL,
	NICK_HELP_CMD_SET_GREET,
	NICK_HELP_CMD_SET_KILL,
	NICK_HELP_CMD_SET_SECURE,
	NICK_HELP_CMD_SET_PRIVATE,
	NICK_HELP_CMD_SET_HIDE,
	NICK_HELP_CMD_SET_MSG,
	NICK_HELP_CMD_SET_AUTOOP,
	NICK_HELP_SET_TAIL,
	NICK_HELP_SET_DISPLAY,
	NICK_HELP_SET_PASSWORD,
	NICK_HELP_SET_LANGUAGE,
	NICK_HELP_SET_EMAIL,
	NICK_HELP_SET_GREET,
	NICK_HELP_SET_KILL,
	NICK_HELP_SET_SECURE,
	NICK_HELP_SET_PRIVATE,
	NICK_HELP_SET_HIDE,
	NICK_HELP_SET_MSG,
	NICK_HELP_SET_AUTOOP,
	NICK_HELP_SASET_HEAD,
	NICK_HELP_CMD_SASET_DISPLAY,
	NICK_HELP_CMD_SASET_PASSWORD,
	NICK_HELP_CMD_SASET_EMAIL,
	NICK_HELP_CMD_SASET_GREET,
	NICK_HELP_CMD_SASET_PRIVATE,
	NICK_HELP_CMD_SASET_NOEXPIRE,
	NICK_HELP_CMD_SASET_AUTOOP,
	NICK_HELP_CMD_SASET_LANGUAGE,
	NICK_HELP_SASET_TAIL,
	NICK_HELP_SASET_DISPLAY,
	NICK_HELP_SASET_PASSWORD,
	NICK_HELP_SASET_EMAIL,
	NICK_HELP_SASET_GREET,
	NICK_HELP_SASET_KILL,
	NICK_HELP_SASET_SECURE,
	NICK_HELP_SASET_PRIVATE,
	NICK_HELP_SASET_HIDE,
	NICK_HELP_SASET_MSG,
	NICK_HELP_SASET_NOEXPIRE,
	NICK_HELP_SASET_AUTOOP,
	NICK_HELP_SASET_LANGUAGE,
	NICK_HELP_RECOVER,
	NICK_HELP_RELEASE,
	NICK_HELP_GHOST,
	NICK_HELP_INFO,
	NICK_HELP_LIST,
	NICK_HELP_ALIST,
	NICK_HELP_GLIST,
	NICK_HELP_STATUS,
	NICK_HELP_SENDPASS,
	NICK_HELP_RESETPASS,
	NICK_HELP_CONFIRM,
	NICK_HELP_CONFIRM_OPER,
	NICK_HELP_RESEND,
	NICK_SERVADMIN_HELP,
	NICK_SERVADMIN_HELP_LOGOUT,
	NICK_SERVADMIN_HELP_DROP,
	NICK_SERVADMIN_HELP_LIST,
	NICK_SERVADMIN_HELP_ALIST,
	NICK_SERVADMIN_HELP_GLIST,
	NICK_SERVADMIN_HELP_GETPASS,
	NICK_SERVADMIN_HELP_GETEMAIL,
	NICK_SERVADMIN_HELP_FORBID,
	NICK_SERVADMIN_HELP_SUSPEND,
	NICK_SERVADMIN_HELP_UNSUSPEND,
	CHAN_HELP_CMD_REGISTER,
	CHAN_HELP_CMD_FORBID,
	CHAN_HELP_CMD_SUSPEND,
	CHAN_HELP_CMD_UNSUSPEND,
	CHAN_HELP_CMD_STATUS,
	CHAN_HELP_CMD_SET,
	CHAN_HELP_CMD_SASET,
	CHAN_HELP_CMD_QOP,
	CHAN_HELP_CMD_AOP,
	CHAN_HELP_CMD_SOP,
	CHAN_HELP_CMD_ACCESS,
	CHAN_HELP_CMD_LEVELS,
	CHAN_HELP_CMD_AKICK,
	CHAN_HELP_CMD_DROP,
	CHAN_HELP_CMD_BAN,
	CHAN_HELP_CMD_CLEARUSERS,
	CHAN_HELP_CMD_DEVOICE,
	CHAN_HELP_CMD_GETKEY,
	CHAN_HELP_CMD_INFO,
	CHAN_HELP_CMD_INVITE,
	CHAN_HELP_CMD_KICK,
	CHAN_HELP_CMD_LIST,
	CHAN_HELP_CMD_OP,
	CHAN_HELP_CMD_TOPIC,
	CHAN_HELP_CMD_UNBAN,
	CHAN_HELP_CMD_VOICE,
	CHAN_HELP_CMD_VOP,
	CHAN_HELP_CMD_DEHALFOP,
	CHAN_HELP_CMD_DEOWNER,
	CHAN_HELP_CMD_DEPROTECT,
	CHAN_HELP_CMD_HALFOP,
	CHAN_HELP_CMD_HOP,
	CHAN_HELP_CMD_OWNER,
	CHAN_HELP_CMD_PROTECT,
	CHAN_HELP_CMD_DEOP,
	CHAN_HELP_CMD_CLONE,
	CHAN_HELP_CMD_MODE,
	CHAN_HELP_CMD_ENTRYMSG,
	CHAN_HELP,
	CHAN_HELP_EXPIRES,
	CHAN_HELP_REGISTER,
	CHAN_HELP_DROP,
	CHAN_HELP_SASET_HEAD,
	CHAN_HELP_SET_HEAD,
	CHAN_HELP_CMD_SET_FOUNDER,
	CHAN_HELP_CMD_SET_SUCCESSOR,
	CHAN_HELP_CMD_SET_DESC,
	CHAN_HELP_CMD_SET_BANTYPE,
	CHAN_HELP_CMD_SET_KEEPTOPIC,
	CHAN_HELP_CMD_SET_OPNOTICE,
	CHAN_HELP_CMD_SET_PEACE,
	CHAN_HELP_CMD_SET_PRIVATE,
	CHAN_HELP_CMD_SET_RESTRICTED,
	CHAN_HELP_CMD_SET_SECURE,
	CHAN_HELP_CMD_SET_SECUREOPS,
	CHAN_HELP_CMD_SET_SECUREFOUNDER,
	CHAN_HELP_CMD_SET_SIGNKICK,
	CHAN_HELP_CMD_SET_TOPICLOCK,
	CHAN_HELP_CMD_SET_XOP,
	CHAN_HELP_CMD_SET_PERSIST,
	CHAN_HELP_CMD_SET_NOEXPIRE,
	CHAN_HELP_SET_TAIL,
	CHAN_HELP_SASET_TAIL,
	CHAN_HELP_SET_FOUNDER,
	CHAN_HELP_SET_SUCCESSOR,
	CHAN_HELP_SET_DESC,
	CHAN_HELP_SET_BANTYPE,
	CHAN_HELP_SET_KEEPTOPIC,
	CHAN_HELP_SET_TOPICLOCK,
	CHAN_HELP_SET_PEACE,
	CHAN_HELP_SET_PRIVATE,
	CHAN_HELP_SET_RESTRICTED,
	CHAN_HELP_SET_SECURE,
	CHAN_HELP_SET_SECUREOPS,
	CHAN_HELP_SET_SECUREFOUNDER,
	CHAN_HELP_SET_SIGNKICK,
	CHAN_HELP_SET_XOP,
	CHAN_HELP_SET_PERSIST,
	CHAN_HELP_SET_OPNOTICE,
	CHAN_HELP_QOP,
	CHAN_HELP_AOP,
	CHAN_HELP_HOP,
	CHAN_HELP_SOP,
	CHAN_HELP_VOP,
	CHAN_HELP_ACCESS,
	CHAN_HELP_ACCESS_LEVELS,
	CHAN_HELP_AKICK,
	CHAN_HELP_LEVELS,
	CHAN_HELP_LEVELS_DESC,
	CHAN_HELP_LEVELS_DESC_FORMAT,
	CHAN_HELP_INFO,
	CHAN_HELP_LIST,
	CHAN_HELP_OP,
	CHAN_HELP_DEOP,
	CHAN_HELP_VOICE,
	CHAN_HELP_DEVOICE,
	CHAN_HELP_HALFOP,
	CHAN_HELP_DEHALFOP,
	CHAN_HELP_PROTECT,
	CHAN_HELP_DEPROTECT,
	CHAN_HELP_OWNER,
	CHAN_HELP_DEOWNER,
	CHAN_HELP_INVITE,
	CHAN_HELP_UNBAN,
	CHAN_HELP_KICK,
	CHAN_HELP_BAN,
	CHAN_HELP_TOPIC,
	CHAN_HELP_CLEARUSERS,
	CHAN_HELP_GETKEY,
	CHAN_HELP_CLONE,
	CHAN_HELP_MODE,
	CHAN_HELP_ENTRYMSG,
	CHAN_SERVADMIN_HELP,
	CHAN_SERVADMIN_HELP_DROP,
	CHAN_SERVADMIN_HELP_SET_NOEXPIRE,
	CHAN_SERVADMIN_HELP_FORBID,
	CHAN_SERVADMIN_HELP_SUSPEND,
	CHAN_SERVADMIN_HELP_UNSUSPEND,
	CHAN_SERVADMIN_HELP_STATUS,
	MEMO_HELP_CMD_SEND,
	MEMO_HELP_CMD_CANCEL,
	MEMO_HELP_CMD_LIST,
	MEMO_HELP_CMD_READ,
	MEMO_HELP_CMD_DEL,
	MEMO_HELP_CMD_SET,
	MEMO_HELP_CMD_INFO,
	MEMO_HELP_CMD_RSEND,
	MEMO_HELP_CMD_CHECK,
	MEMO_HELP_CMD_SENDALL,
	MEMO_HELP_CMD_STAFF,
	MEMO_HELP_CMD_IGNORE,
	MEMO_HELP_HEADER,
	MEMO_HELP_FOOTER,
	MEMO_HELP_SEND,
	MEMO_HELP_CANCEL,
	MEMO_HELP_LIST,
	MEMO_HELP_READ,
	MEMO_HELP_DEL,
	MEMO_HELP_SET,
	MEMO_HELP_SET_NOTIFY,
	MEMO_HELP_SET_LIMIT,
	MEMO_HELP_INFO,
	MEMO_SERVADMIN_HELP_SET_LIMIT,
	MEMO_SERVADMIN_HELP_INFO,
	MEMO_HELP_STAFF,
	MEMO_HELP_SENDALL,
	MEMO_HELP_RSEND,
	MEMO_HELP_CHECK,
	MEMO_HELP_IGNORE,
	OPER_HELP_CMD_GLOBAL,
	OPER_HELP_CMD_STATS,
	OPER_HELP_CMD_STAFF,
	OPER_HELP_CMD_MODE,
	OPER_HELP_CMD_KICK,
	OPER_HELP_CMD_AKILL,
	OPER_HELP_CMD_SNLINE,
	OPER_HELP_CMD_SQLINE,
	OPER_HELP_CMD_SZLINE,
	OPER_HELP_CMD_CHANLIST,
	OPER_HELP_CMD_USERLIST,
	OPER_HELP_CMD_LOGONNEWS,
	OPER_HELP_CMD_RANDOMNEWS,
	OPER_HELP_CMD_OPERNEWS,
	OPER_HELP_CMD_SESSION,
	OPER_HELP_CMD_EXCEPTION,
	OPER_HELP_CMD_NOOP,
	OPER_HELP_CMD_JUPE,
	OPER_HELP_CMD_IGNORE,
	OPER_HELP_CMD_SET,
	OPER_HELP_CMD_RELOAD,
	OPER_HELP_CMD_UPDATE,
	OPER_HELP_CMD_RESTART,
	OPER_HELP_CMD_QUIT,
	OPER_HELP_CMD_SHUTDOWN,
	OPER_HELP_CMD_DEFCON,
	OPER_HELP_CMD_CHANKILL,
	OPER_HELP_CMD_OLINE,
	OPER_HELP_CMD_UMODE,
	OPER_HELP_CMD_SVSNICK,
	OPER_HELP_CMD_MODLOAD,
	OPER_HELP_CMD_MODUNLOAD,
	OPER_HELP_CMD_MODRELOAD,
	OPER_HELP_CMD_MODINFO,
	OPER_HELP_CMD_MODLIST,
	OPER_HELP,
	OPER_HELP_LOGGED,
	OPER_HELP_GLOBAL,
	OPER_HELP_STATS,
	OPER_HELP_IGNORE,
	OPER_HELP_MODE,
	OPER_HELP_UMODE,
	OPER_HELP_OLINE,
	OPER_HELP_KICK,
	OPER_HELP_SVSNICK,
	OPER_HELP_AKILL,
	OPER_HELP_SNLINE,
	OPER_HELP_SQLINE,
	OPER_HELP_SZLINE,
	OPER_HELP_SET,
	OPER_HELP_SET_READONLY,
	OPER_HELP_SET_DEBUG,
	OPER_HELP_SET_NOEXPIRE,
	OPER_HELP_SET_SUPERADMIN,
	OPER_HELP_SET_LIST,
	OPER_HELP_NOOP,
	OPER_HELP_JUPE,
	OPER_HELP_UPDATE,
	OPER_HELP_RELOAD,
	OPER_HELP_QUIT,
	OPER_HELP_SHUTDOWN,
	OPER_HELP_RESTART,
	OPER_HELP_CHANLIST,
	OPER_HELP_USERLIST,
	OPER_HELP_MODLOAD,
	OPER_HELP_MODUNLOAD,
	OPER_HELP_MODRELOAD,
	OPER_HELP_MODINFO,
	OPER_HELP_MODLIST,
	BOT_HELP_CMD_BOTLIST,
	BOT_HELP_CMD_ASSIGN,
	BOT_HELP_CMD_SET,
	BOT_HELP_CMD_KICK,
	BOT_HELP_CMD_BADWORDS,
	BOT_HELP_CMD_ACT,
	BOT_HELP_CMD_INFO,
	BOT_HELP_CMD_SAY,
	BOT_HELP_CMD_UNASSIGN,
	BOT_HELP_CMD_BOT,
	BOT_HELP,
	BOT_HELP_FOOTER,
	BOT_HELP_BOTLIST,
	BOT_HELP_ASSIGN,
	BOT_HELP_UNASSIGN,
	BOT_HELP_INFO,
	BOT_HELP_SET,
	BOT_HELP_SET_DONTKICKOPS,
	BOT_HELP_SET_DONTKICKVOICES,
	BOT_HELP_SET_FANTASY,
	BOT_HELP_SET_GREET,
	BOT_HELP_SET_SYMBIOSIS,
	BOT_HELP_SET_MSG,
	BOT_HELP_KICK,
	BOT_HELP_KICK_BOLDS,
	BOT_HELP_KICK_COLORS,
	BOT_HELP_KICK_REVERSES,
	BOT_HELP_KICK_UNDERLINES,
	BOT_HELP_KICK_CAPS,
	BOT_HELP_KICK_FLOOD,
	BOT_HELP_KICK_REPEAT,
	BOT_HELP_KICK_BADWORDS,
	BOT_HELP_KICK_ITALICS,
	BOT_HELP_KICK_AMSGS,
	BOT_HELP_BADWORDS,
	BOT_HELP_SAY,
	BOT_HELP_ACT,
	BOT_SERVADMIN_HELP_BOT,
	BOT_SERVADMIN_HELP_SET,
	BOT_SERVADMIN_HELP_SET_NOBOT,
	BOT_SERVADMIN_HELP_SET_PRIVATE,
	HOST_ENTRY,
	HOST_IDENT_ENTRY,
	HOST_SET,
	HOST_IDENT_SET,
	HOST_SETALL,
	HOST_DELALL,
	HOST_DELALL_SYNTAX,
	HOST_IDENT_SETALL,
	HOST_SET_ERROR,
	HOST_SET_IDENT_ERROR,
	HOST_SET_TOOLONG,
	HOST_SET_IDENTTOOLONG,
	HOST_NOREG,
	HOST_SET_SYNTAX,
	HOST_SETALL_SYNTAX,
	HOST_NOT_ASSIGNED,
	HOST_ACTIVATED,
	HOST_IDENT_ACTIVATED,
	HOST_DEL,
	HOST_DEL_SYNTAX,
	HOST_OFF,
	HOST_NO_VIDENT,
	HOST_GROUP,
	HOST_IDENT_GROUP,
	HOST_LIST_FOOTER,
	HOST_LIST_RANGE_FOOTER,
	HOST_LIST_KEY_FOOTER,
	HOST_HELP_CMD_ON,
	HOST_HELP_CMD_OFF,
	HOST_HELP_CMD_GROUP,
	HOST_HELP_CMD_SET,
	HOST_HELP_CMD_SETALL,
	HOST_HELP_CMD_DEL,
	HOST_HELP_CMD_DELALL,
	HOST_HELP_CMD_LIST,
	HOST_HELP_ON,
	HOST_HELP_SET,
	HOST_HELP_DELALL,
	HOST_HELP_SETALL,
	HOST_HELP_OFF,
	HOST_HELP_DEL,
	HOST_HELP_LIST,
	HOST_HELP_GROUP,
	OPER_SUPER_ADMIN_NOT_ENABLED,
	OPER_HELP_SYNC,
	OPER_HELP_CMD_SQLSYNC,
	OPER_SYNC_UPDATED,
	LANG_STRING_COUNT
};
