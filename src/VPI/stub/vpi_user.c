#define PLI_EXPORT 0
#include "../vpi_user.h"

#define PROTO_PARAMS(params) params
#define XXTERN __declspec(dllexport)

/* callback related */
XXTERN vpiHandle vpi_register_cb       PROTO_PARAMS((p_cb_data cb_data_p)){ return 0; }
XXTERN PLI_INT32 vpi_remove_cb         PROTO_PARAMS((vpiHandle cb_obj)){ return 0; }
XXTERN void        vpi_get_cb_info     PROTO_PARAMS((vpiHandle object,
                                                     p_cb_data cb_data_p)){ }
XXTERN vpiHandle   vpi_register_systf  PROTO_PARAMS((p_vpi_systf_data
                                                       systf_data_p)){ return 0; }
XXTERN void        vpi_get_systf_info  PROTO_PARAMS((vpiHandle object,
                                                     p_vpi_systf_data
                                                       systf_data_p)){ }

/* for obtaining handles */
XXTERN vpiHandle vpi_handle_by_name    PROTO_PARAMS((PLI_BYTE8 *name,
                                                     vpiHandle scope)){ return 0; }
XXTERN vpiHandle   vpi_handle_by_index PROTO_PARAMS((vpiHandle object,
                                                     PLI_INT32 indx)){ return 0; }

/* for traversing relationships */
XXTERN vpiHandle vpi_handle            PROTO_PARAMS((PLI_INT32 type,
                                                     vpiHandle refHandle)){ return 0; }
XXTERN vpiHandle vpi_handle_multi      PROTO_PARAMS((PLI_INT32 type,
                                                     vpiHandle refHandle1,
                                                     vpiHandle refHandle2,
                                                     ... )){ return 0; }
XXTERN vpiHandle   vpi_iterate         PROTO_PARAMS((PLI_INT32 type,
                                                     vpiHandle refHandle)){ return 0; }
XXTERN vpiHandle   vpi_scan            PROTO_PARAMS((vpiHandle iterator)){ return 0; }

/* for processing properties */
XXTERN PLI_INT32 vpi_get               PROTO_PARAMS((PLI_INT32 property,
                                                     vpiHandle object)){ return 0; }
XXTERN PLI_BYTE8 *vpi_get_str          PROTO_PARAMS((PLI_INT32 property,
                                                     vpiHandle object)){ return 0; }

/* delay processing */
XXTERN void        vpi_get_delays      PROTO_PARAMS((vpiHandle object,
                                                     p_vpi_delay delay_p)){ }
XXTERN void        vpi_put_delays      PROTO_PARAMS((vpiHandle object,
                                                     p_vpi_delay delay_p)){ }

/* value processing */
XXTERN void        vpi_get_value       PROTO_PARAMS((vpiHandle expr,
                                                     p_vpi_value value_p)){ }
XXTERN vpiHandle   vpi_put_value       PROTO_PARAMS((vpiHandle object,
                                                     p_vpi_value value_p,
                                                     p_vpi_time time_p,
                                                     PLI_INT32 flags)){ return 0; }

/* time processing */
XXTERN void        vpi_get_time        PROTO_PARAMS((vpiHandle object,
                                                     p_vpi_time time_p)){ }

/* I/O routines */
XXTERN PLI_UINT32 vpi_mcd_open         PROTO_PARAMS((PLI_BYTE8 *fileName)){ return 0; }
XXTERN PLI_UINT32 vpi_mcd_close        PROTO_PARAMS((PLI_UINT32 mcd)){ return 0; }
XXTERN PLI_BYTE8 *vpi_mcd_name         PROTO_PARAMS((PLI_UINT32 cd)){ return 0; }
XXTERN PLI_INT32 vpi_mcd_printf        PROTO_PARAMS((PLI_UINT32 mcd,
                                                     PLI_BYTE8 *format,
                                                     ...)){ return 0; }
XXTERN PLI_INT32   vpi_printf          PROTO_PARAMS((PLI_BYTE8 *format,
                                                     ...)){ return 0; }

/* utility routines */
XXTERN PLI_INT32 vpi_compare_objects PROTO_PARAMS((vpiHandle object1,
                                                     vpiHandle object2)){ return 0; }
XXTERN PLI_INT32 vpi_chk_error         PROTO_PARAMS((p_vpi_error_info
                                                       error_info_p)){ return 0; }
XXTERN PLI_INT32 vpi_free_object       PROTO_PARAMS((vpiHandle object)){ return 0; }
XXTERN PLI_INT32 vpi_get_vlog_info     PROTO_PARAMS((p_vpi_vlog_info
                                                       vlog_info_p)){ return 0; }

/* routines added with 1364-2001 */
XXTERN PLI_INT32 vpi_get_data          PROTO_PARAMS((PLI_INT32 id,
                                                     PLI_BYTE8 *dataLoc,
                                                     PLI_INT32 numOfBytes)){ return 0; }
XXTERN PLI_INT32   vpi_put_data        PROTO_PARAMS((PLI_INT32 id,
                                                     PLI_BYTE8 *dataLoc,
                                                     PLI_INT32 numOfBytes)){ return 0; }
XXTERN void       *vpi_get_userdata    PROTO_PARAMS((vpiHandle obj)){ return 0; }
XXTERN PLI_INT32   vpi_put_userdata    PROTO_PARAMS((vpiHandle obj,
                                                     void *userdata)){ return 0; }
XXTERN PLI_INT32   vpi_vprintf         PROTO_PARAMS((PLI_BYTE8 *format,
                                                     va_list ap)){ return 0; }
XXTERN PLI_INT32   vpi_mcd_vprintf     PROTO_PARAMS((PLI_UINT32 mcd,
                                                     PLI_BYTE8 *format,
                                                     va_list ap)){ return 0; }
XXTERN PLI_INT32   vpi_flush           PROTO_PARAMS((void)){ return 0; }
XXTERN PLI_INT32   vpi_mcd_flush       PROTO_PARAMS((PLI_UINT32 mcd)){ return 0; }
XXTERN PLI_INT32   vpi_control         PROTO_PARAMS((PLI_INT32 operation,
                                                     ...)){ return 0; }
XXTERN vpiHandle   vpi_handle_by_multi_index PROTO_PARAMS((vpiHandle obj,
                                                     PLI_INT32 num_index,
                                                     PLI_INT32 *index_array)){ return 0; }