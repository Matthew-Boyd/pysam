#include <Python.h>

#include <SAM_Sco2AirCooler.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_Sco2AirCooler   data_ptr;
} CommonObject;

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Sco2AirCooler data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	CommonObject* Common_obj = (CommonObject*)new_obj;

	Common_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(CommonObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2AirCooler", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(CommonObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_P_co2_hot_in(CommonObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Common_P_co2_hot_in_nget, self->data_ptr);
}

static int
Common_set_P_co2_hot_in(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2AirCooler_Common_P_co2_hot_in_nset, self->data_ptr);
}

static PyObject *
Common_get_T_amb(CommonObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Common_T_amb_nget, self->data_ptr);
}

static int
Common_set_T_amb(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2AirCooler_Common_T_amb_nset, self->data_ptr);
}

static PyObject *
Common_get_T_co2_cold_out(CommonObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Common_T_co2_cold_out_nget, self->data_ptr);
}

static int
Common_set_T_co2_cold_out(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2AirCooler_Common_T_co2_cold_out_nset, self->data_ptr);
}

static PyObject *
Common_get_T_co2_hot_in(CommonObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Common_T_co2_hot_in_nget, self->data_ptr);
}

static int
Common_set_T_co2_hot_in(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2AirCooler_Common_T_co2_hot_in_nset, self->data_ptr);
}

static PyObject *
Common_get_W_dot_fan(CommonObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Common_W_dot_fan_nget, self->data_ptr);
}

static int
Common_set_W_dot_fan(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2AirCooler_Common_W_dot_fan_nset, self->data_ptr);
}

static PyObject *
Common_get_deltaP(CommonObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Common_deltaP_nget, self->data_ptr);
}

static int
Common_set_deltaP(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2AirCooler_Common_deltaP_nset, self->data_ptr);
}

static PyObject *
Common_get_q_dot_reject(CommonObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Common_q_dot_reject_nget, self->data_ptr);
}

static int
Common_set_q_dot_reject(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2AirCooler_Common_q_dot_reject_nset, self->data_ptr);
}

static PyObject *
Common_get_site_elevation(CommonObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Common_site_elevation_nget, self->data_ptr);
}

static int
Common_set_site_elevation(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2AirCooler_Common_site_elevation_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"P_co2_hot_in", (getter)Common_get_P_co2_hot_in,(setter)Common_set_P_co2_hot_in,
	PyDoc_STR("*float*: Pressure of CO2 at inlet to cooler [MPa]\n\n*Required*: True"),
 	NULL},
{"T_amb", (getter)Common_get_T_amb,(setter)Common_set_T_amb,
	PyDoc_STR("*float*: Ambient temperature at design [C]\n\n*Required*: True"),
 	NULL},
{"T_co2_cold_out", (getter)Common_get_T_co2_cold_out,(setter)Common_set_T_co2_cold_out,
	PyDoc_STR("*float*: Cold temperature of CO2 at cooler exit [C]\n\n*Required*: True"),
 	NULL},
{"T_co2_hot_in", (getter)Common_get_T_co2_hot_in,(setter)Common_set_T_co2_hot_in,
	PyDoc_STR("*float*: Hot temperature of CO2 at inlet to cooler [C]\n\n*Required*: True"),
 	NULL},
{"W_dot_fan", (getter)Common_get_W_dot_fan,(setter)Common_set_W_dot_fan,
	PyDoc_STR("*float*: Air fan power [MWe]\n\n*Required*: True"),
 	NULL},
{"deltaP", (getter)Common_get_deltaP,(setter)Common_set_deltaP,
	PyDoc_STR("*float*: Pressure drop of CO2 through cooler [MPa]\n\n*Required*: True"),
 	NULL},
{"q_dot_reject", (getter)Common_get_q_dot_reject,(setter)Common_set_q_dot_reject,
	PyDoc_STR("*float*: Heat rejected from CO2 stream [MWt]\n\n*Required*: True"),
 	NULL},
{"site_elevation", (getter)Common_get_site_elevation,(setter)Common_set_site_elevation,
	PyDoc_STR("*float*: Site elevation [m]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2AirCooler.Common",             /*tp_name*/
		sizeof(CommonObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


/*
 * Outputs Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_Sco2AirCooler   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Sco2AirCooler data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	OutputsObject* Outputs_obj = (OutputsObject*)new_obj;

	Outputs_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(OutputsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2AirCooler", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_export(OutputsObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_UA_total(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Outputs_UA_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_d_tube_in(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Outputs_d_tube_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_d_tube_out(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Outputs_d_tube_out_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depth_footprint(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Outputs_depth_footprint_nget, self->data_ptr);
}

static PyObject *
Outputs_get_length(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Outputs_length_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_V_hx_material(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Outputs_m_V_hx_material_nget, self->data_ptr);
}

static PyObject *
Outputs_get_n_passes_series(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Outputs_n_passes_series_nget, self->data_ptr);
}

static PyObject *
Outputs_get_number_of_tubes(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Outputs_number_of_tubes_nget, self->data_ptr);
}

static PyObject *
Outputs_get_parallel_paths(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Outputs_parallel_paths_nget, self->data_ptr);
}

static PyObject *
Outputs_get_width_footprint(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2AirCooler_Outputs_width_footprint_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"UA_total", (getter)Outputs_get_UA_total,(setter)0,
	PyDoc_STR("*float*: Total air-side conductance [kW/K]"),
 	NULL},
{"d_tube_in", (getter)Outputs_get_d_tube_in,(setter)0,
	PyDoc_STR("*float*: CO2 tube inner diameter [cm]"),
 	NULL},
{"d_tube_out", (getter)Outputs_get_d_tube_out,(setter)0,
	PyDoc_STR("*float*: CO2 tube outer diameter [cm]"),
 	NULL},
{"depth_footprint", (getter)Outputs_get_depth_footprint,(setter)0,
	PyDoc_STR("*float*: Dimension of total air cooler in loop/air flow direction [m]"),
 	NULL},
{"length", (getter)Outputs_get_length,(setter)0,
	PyDoc_STR("*float*: Length of tube (one pass) [m]"),
 	NULL},
{"m_V_hx_material", (getter)Outputs_get_m_V_hx_material,(setter)0,
	PyDoc_STR("*float*: Total hx material volume - no headers [m^3]"),
 	NULL},
{"n_passes_series", (getter)Outputs_get_n_passes_series,(setter)0,
	PyDoc_STR("*float*: Number of serial tubes in flow path [-]"),
 	NULL},
{"number_of_tubes", (getter)Outputs_get_number_of_tubes,(setter)0,
	PyDoc_STR("*float*: Number of tubes (one pass) [-]"),
 	NULL},
{"parallel_paths", (getter)Outputs_get_parallel_paths,(setter)0,
	PyDoc_STR("*float*: Number of parallel flow paths [-]"),
 	NULL},
{"width_footprint", (getter)Outputs_get_width_footprint,(setter)0,
	PyDoc_STR("*float*: Dimension of total air cooler of parallel loops [m]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2AirCooler.Outputs",             /*tp_name*/
		sizeof(OutputsObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/*
 * Sco2AirCooler
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Sco2AirCooler   data_ptr;
} Sco2AirCoolerObject;

static PyTypeObject Sco2AirCooler_Type;

static Sco2AirCoolerObject *
newSco2AirCoolerObject(void* data_ptr)
{
	Sco2AirCoolerObject *self;
	self = PyObject_New(Sco2AirCoolerObject, &Sco2AirCooler_Type);

	PySAM_TECH_ATTR("Sco2AirCooler", SAM_Sco2AirCooler_construct)

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);


	return self;
}

/* Sco2AirCooler methods */

static void
Sco2AirCooler_dealloc(Sco2AirCoolerObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Sco2AirCooler_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Sco2AirCooler_execute(Sco2AirCoolerObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Sco2AirCooler_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Sco2AirCooler_assign(Sco2AirCoolerObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Sco2AirCooler"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Sco2AirCooler_export(Sco2AirCoolerObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef Sco2AirCooler_methods[] = {
		{"execute",            (PyCFunction)Sco2AirCooler_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Sco2AirCooler_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Sco2AirCooler_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Sco2AirCooler_getattro(Sco2AirCoolerObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Sco2AirCooler_setattr(Sco2AirCoolerObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Sco2AirCooler_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2AirCooler",            /*tp_name*/
		sizeof(Sco2AirCoolerObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Sco2AirCooler_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Sco2AirCooler_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Sco2AirCooler_getattro, /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		"This class contains all the variable information for running a simulation. Variables are grouped together in the subclasses as properties. If property assignments are the wrong type, an error is thrown.",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Sco2AirCooler_methods,      /*tp_methods*/
		0,                          /*tp_members*/
		0,       /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,                          /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/* --------------------------------------------------------------------- */


/* Function of no arguments returning new Sco2AirCooler object */

static PyObject *
Sco2AirCooler_new(PyObject *self, PyObject *args)
{
	Sco2AirCoolerObject *rv;
	rv = newSco2AirCoolerObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Sco2AirCooler_wrap(PyObject *self, PyObject *args)
{
	Sco2AirCoolerObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSco2AirCoolerObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Sco2AirCooler_default(PyObject *self, PyObject *args)
{
	Sco2AirCoolerObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSco2AirCoolerObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Sco2AirCooler", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Sco2AirCoolerModule_methods[] = {
		{"new",             Sco2AirCooler_new,         METH_VARARGS,
				PyDoc_STR("new() -> Sco2AirCooler")},
		{"default",             Sco2AirCooler_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Sco2AirCooler\n\nUse financial model-specific default attributes\n"
				"config options:\n\n")},
		{"wrap",             Sco2AirCooler_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Sco2AirCooler\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Supercritical CO2 Power Cycle Air Cooler");


static int
Sco2AirCoolerModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error(m) < 0) goto fail;

	Sco2AirCooler_Type.tp_dict = PyDict_New();
	if (!Sco2AirCooler_Type.tp_dict) { goto fail; }

	/// Add the Common type object to Sco2AirCooler_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2AirCooler_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to Sco2AirCooler_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2AirCooler_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Sco2AirCooler type object to the module
	if (PyType_Ready(&Sco2AirCooler_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Sco2AirCooler",
				(PyObject*)&Sco2AirCooler_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Sco2AirCoolerModule_slots[] = {
		{Py_mod_exec, Sco2AirCoolerModule_exec},
		{0, NULL},
};

static struct PyModuleDef Sco2AirCoolerModule = {
		PyModuleDef_HEAD_INIT,
		"Sco2AirCooler",
		module_doc,
		0,
		Sco2AirCoolerModule_methods,
		Sco2AirCoolerModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Sco2AirCooler(void)
{
	return PyModuleDef_Init(&Sco2AirCoolerModule);
}