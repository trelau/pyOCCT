#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <GccEnt_Position.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <Standard_DomainError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Handle.hxx>
#include <GccEnt_BadQualifier.hxx>
#include <Standard_Type.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <gp_Lin2d.hxx>
#include <GccEnt_QualifiedLin.hxx>
#include <Standard_OStream.hxx>
#include <GccEnt.hxx>

PYBIND11_MODULE(GccEnt, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\GccEnt_Position.hxx
	py::enum_<GccEnt_Position>(mod, "GccEnt_Position", "Qualifies the position of a solution of a construction algorithm with respect to one of its arguments. This is one of the following: - GccEnt_unqualified: the position of the solution is undefined with respect to the argument, - GccEnt_enclosing: the solution encompasses the argument, - GccEnt_enclosed: the solution is encompassed by the argument, - GccEnt_outside: the solution and the argument are external to one another, - GccEnt_noqualifier: the value returned during a consultation of the qualifier when the argument is defined as GccEnt_unqualified. Note: the interior of a line or any open curve is defined as the left-hand side of the line or curve in relation to its orientation.")
		.value("GccEnt_unqualified", GccEnt_Position::GccEnt_unqualified)
		.value("GccEnt_enclosing", GccEnt_Position::GccEnt_enclosing)
		.value("GccEnt_enclosed", GccEnt_Position::GccEnt_enclosed)
		.value("GccEnt_outside", GccEnt_Position::GccEnt_outside)
		.value("GccEnt_noqualifier", GccEnt_Position::GccEnt_noqualifier)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\GccEnt_BadQualifier.hxx
	py::class_<GccEnt_BadQualifier, opencascade::handle<GccEnt_BadQualifier>, Standard_DomainError> cls_GccEnt_BadQualifier(mod, "GccEnt_BadQualifier", "None");
	cls_GccEnt_BadQualifier.def(py::init<>());
	cls_GccEnt_BadQualifier.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_GccEnt_BadQualifier.def_static("Raise_", (void (*)(const Standard_CString)) &GccEnt_BadQualifier::Raise, "None", py::arg("theMessage"));
	cls_GccEnt_BadQualifier.def_static("Raise_", (void (*)(Standard_SStream &)) &GccEnt_BadQualifier::Raise, "None", py::arg("theMessage"));
	cls_GccEnt_BadQualifier.def_static("NewInstance_", (opencascade::handle<GccEnt_BadQualifier> (*)(const Standard_CString)) &GccEnt_BadQualifier::NewInstance, "None", py::arg("theMessage"));
	cls_GccEnt_BadQualifier.def_static("get_type_name_", (const char * (*)()) &GccEnt_BadQualifier::get_type_name, "None");
	cls_GccEnt_BadQualifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccEnt_BadQualifier::get_type_descriptor, "None");
	cls_GccEnt_BadQualifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccEnt_BadQualifier::*)() const ) &GccEnt_BadQualifier::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GccEnt_QualifiedCirc.hxx
	py::class_<GccEnt_QualifiedCirc, std::unique_ptr<GccEnt_QualifiedCirc, Deleter<GccEnt_QualifiedCirc>>> cls_GccEnt_QualifiedCirc(mod, "GccEnt_QualifiedCirc", "Creates a qualified 2d Circle. A qualified 2D circle is a circle (gp_Circ2d circle) with a qualifier which specifies whether the solution of a construction algorithm using the qualified circle (as an argument): - encloses the circle, or - is enclosed by the circle, or - is built so that both the circle and it are external to one another, or - is undefined (all solutions apply).");
	cls_GccEnt_QualifiedCirc.def(py::init<const gp_Circ2d &, const GccEnt_Position>(), py::arg("Qualified"), py::arg("Qualifier"));
	cls_GccEnt_QualifiedCirc.def("Qualified", (gp_Circ2d (GccEnt_QualifiedCirc::*)() const ) &GccEnt_QualifiedCirc::Qualified, "Returns a 2D circle to which the qualifier is assigned.");
	cls_GccEnt_QualifiedCirc.def("Qualifier", (GccEnt_Position (GccEnt_QualifiedCirc::*)() const ) &GccEnt_QualifiedCirc::Qualifier, "Returns - the qualifier of this qualified circle, if it is enclosing, enclosed or outside, or - GccEnt_noqualifier if it is unqualified.");
	cls_GccEnt_QualifiedCirc.def("IsUnqualified", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const ) &GccEnt_QualifiedCirc::IsUnqualified, "Returns true if the Circ2d is Unqualified and false in the other cases.");
	cls_GccEnt_QualifiedCirc.def("IsEnclosing", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const ) &GccEnt_QualifiedCirc::IsEnclosing, "Returns true if the solution computed by a construction algorithm using this qualified circle encloses the circle.");
	cls_GccEnt_QualifiedCirc.def("IsEnclosed", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const ) &GccEnt_QualifiedCirc::IsEnclosed, "Returns true if the solution computed by a construction algorithm using this qualified circle is enclosed by the circle.");
	cls_GccEnt_QualifiedCirc.def("IsOutside", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const ) &GccEnt_QualifiedCirc::IsOutside, "Returns true if both the solution computed by a construction algorithm using this qualified circle and the circle are external to one another.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GccEnt_QualifiedLin.hxx
	py::class_<GccEnt_QualifiedLin, std::unique_ptr<GccEnt_QualifiedLin, Deleter<GccEnt_QualifiedLin>>> cls_GccEnt_QualifiedLin(mod, "GccEnt_QualifiedLin", "Describes a qualified 2D line. A qualified 2D line is a line (gp_Lin2d line) with a qualifier which specifies whether the solution of a construction algorithm using the qualified line (as an argument): - is 'enclosed' by the line, or - is built so that both the line and it are external to one another, or - is undefined (all solutions apply). Note: the interior of a line is defined as the left-hand side of the line in relation to its orientation (i.e. when moving from the start to the end of the curve).");
	cls_GccEnt_QualifiedLin.def(py::init<const gp_Lin2d &, const GccEnt_Position>(), py::arg("Qualified"), py::arg("Qualifier"));
	cls_GccEnt_QualifiedLin.def("Qualified", (gp_Lin2d (GccEnt_QualifiedLin::*)() const ) &GccEnt_QualifiedLin::Qualified, "Returns a 2D line to which the qualifier is assigned.");
	cls_GccEnt_QualifiedLin.def("Qualifier", (GccEnt_Position (GccEnt_QualifiedLin::*)() const ) &GccEnt_QualifiedLin::Qualifier, "Returns the qualifier of this qualified line, if it is 'enclosed' or 'outside', or - GccEnt_noqualifier if it is unqualified.");
	cls_GccEnt_QualifiedLin.def("IsUnqualified", (Standard_Boolean (GccEnt_QualifiedLin::*)() const ) &GccEnt_QualifiedLin::IsUnqualified, "Returns true if the solution is unqualified and false in the other cases.");
	cls_GccEnt_QualifiedLin.def("IsEnclosed", (Standard_Boolean (GccEnt_QualifiedLin::*)() const ) &GccEnt_QualifiedLin::IsEnclosed, "Returns true if the solution is Enclosed in the Lin2d and false in the other cases.");
	cls_GccEnt_QualifiedLin.def("IsOutside", (Standard_Boolean (GccEnt_QualifiedLin::*)() const ) &GccEnt_QualifiedLin::IsOutside, "Returns true if the solution is Outside the Lin2d and false in the other cases.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GccEnt.hxx
	py::class_<GccEnt, std::unique_ptr<GccEnt, Deleter<GccEnt>>> cls_GccEnt(mod, "GccEnt", "This package provides an implementation of the qualified entities useful to create 2d entities with geometric constraints. The qualifier explains which subfamily of solutions we want to obtain. It uses the following law: the matter/the interior side is at the left of the line, if we go from the beginning to the end. The qualifiers are: Enclosing : the solution(s) must enclose the argument. Enclosed : the solution(s) must be enclosed in the argument. Outside : both the solution(s) and the argument must be outside to each other. Unqualified : the position is undefined, so give all the solutions. The use of a qualifier is always required if such subfamilies exist. For example, it is not used for a point. Note: the interior of a curve is defined as the left-hand side of the curve in relation to its orientation.");
	cls_GccEnt.def(py::init<>());
	cls_GccEnt.def_static("Print_", (Standard_OStream & (*)(const GccEnt_Position, Standard_OStream &)) &GccEnt::Print, "Prints the name of Position type as a String on the Stream.", py::arg("thePosition"), py::arg("theStream"));
	cls_GccEnt.def_static("PositionToString_", (Standard_CString (*)(GccEnt_Position)) &GccEnt::PositionToString, "Returns the string name for a given position.", py::arg("thePosition"));
	cls_GccEnt.def_static("PositionFromString_", (GccEnt_Position (*)(Standard_CString)) &GccEnt::PositionFromString, "Returns the position from the given string identifier (using case-insensitive comparison).", py::arg("thePositionString"));
	cls_GccEnt.def_static("PositionFromString_", (Standard_Boolean (*)(Standard_CString, GccEnt_Position &)) &GccEnt::PositionFromString, "Determines the position from the given string identifier (using case-insensitive comparison).", py::arg("thePositionString"), py::arg("thePosition"));
	cls_GccEnt.def_static("Unqualified_", (GccEnt_QualifiedLin (*)(const gp_Lin2d &)) &GccEnt::Unqualified, "Constructs a qualified line, so that the relative position to the circle or line of the solution computed by a construction algorithm using the qualified circle or line is not qualified, i.e. all solutions apply.", py::arg("Obj"));
	cls_GccEnt.def_static("Unqualified_", (GccEnt_QualifiedCirc (*)(const gp_Circ2d &)) &GccEnt::Unqualified, "Constructs a qualified circle so that the relative position to the circle or line of the solution computed by a construction algorithm using the qualified circle or line is not qualified, i.e. all solutions apply.", py::arg("Obj"));
	cls_GccEnt.def_static("Enclosing_", (GccEnt_QualifiedCirc (*)(const gp_Circ2d &)) &GccEnt::Enclosing, "Constructs such a qualified circle that the solution computed by a construction algorithm using the qualified circle encloses the circle.", py::arg("Obj"));
	cls_GccEnt.def_static("Enclosed_", (GccEnt_QualifiedLin (*)(const gp_Lin2d &)) &GccEnt::Enclosed, "Constructs a qualified line, so that the solution computed by a construction algorithm using the qualified circle or line is enclosed by the circle or line.", py::arg("Obj"));
	cls_GccEnt.def_static("Enclosed_", (GccEnt_QualifiedCirc (*)(const gp_Circ2d &)) &GccEnt::Enclosed, "Constructs a qualified circle so that the solution computed by a construction algorithm using the qualified circle or line is enclosed by the circle or line.", py::arg("Obj"));
	cls_GccEnt.def_static("Outside_", (GccEnt_QualifiedLin (*)(const gp_Lin2d &)) &GccEnt::Outside, "Constructs a qualified line, so that the solution computed by a construction algorithm using the qualified circle or line and the circle or line are external to one another.", py::arg("Obj"));
	cls_GccEnt.def_static("Outside_", (GccEnt_QualifiedCirc (*)(const gp_Circ2d &)) &GccEnt::Outside, "Constructs a qualified circle so that the solution computed by a construction algorithm using the qualified circle or line and the circle or line are external to one another.", py::arg("Obj"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<GccEnt_Array1OfPosition, std::unique_ptr<GccEnt_Array1OfPosition, Deleter<GccEnt_Array1OfPosition>>> cls_GccEnt_Array1OfPosition(mod, "GccEnt_Array1OfPosition", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_GccEnt_Array1OfPosition.def(py::init<>());
	cls_GccEnt_Array1OfPosition.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_GccEnt_Array1OfPosition.def(py::init([] (const GccEnt_Array1OfPosition &other) {return new GccEnt_Array1OfPosition(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_GccEnt_Array1OfPosition.def(py::init<GccEnt_Array1OfPosition &&>(), py::arg("theOther"));
	cls_GccEnt_Array1OfPosition.def(py::init<const GccEnt_Position &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_GccEnt_Array1OfPosition.def("begin", (GccEnt_Array1OfPosition::iterator (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::begin, "Returns an iterator pointing to the first element in the array.");
	cls_GccEnt_Array1OfPosition.def("end", (GccEnt_Array1OfPosition::iterator (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_GccEnt_Array1OfPosition.def("cbegin", (GccEnt_Array1OfPosition::const_iterator (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_GccEnt_Array1OfPosition.def("cend", (GccEnt_Array1OfPosition::const_iterator (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_GccEnt_Array1OfPosition.def("Init", (void (GccEnt_Array1OfPosition::*)(const GccEnt_Position &)) &GccEnt_Array1OfPosition::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_GccEnt_Array1OfPosition.def("Size", (Standard_Integer (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::Size, "Size query");
	cls_GccEnt_Array1OfPosition.def("Length", (Standard_Integer (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::Length, "Length query (the same)");
	cls_GccEnt_Array1OfPosition.def("IsEmpty", (Standard_Boolean (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::IsEmpty, "Return TRUE if array has zero length.");
	cls_GccEnt_Array1OfPosition.def("Lower", (Standard_Integer (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::Lower, "Lower bound");
	cls_GccEnt_Array1OfPosition.def("Upper", (Standard_Integer (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::Upper, "Upper bound");
	cls_GccEnt_Array1OfPosition.def("IsDeletable", (Standard_Boolean (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::IsDeletable, "myDeletable flag");
	cls_GccEnt_Array1OfPosition.def("IsAllocated", (Standard_Boolean (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_GccEnt_Array1OfPosition.def("Assign", (GccEnt_Array1OfPosition & (GccEnt_Array1OfPosition::*)(const GccEnt_Array1OfPosition &)) &GccEnt_Array1OfPosition::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_GccEnt_Array1OfPosition.def("Move", (GccEnt_Array1OfPosition & (GccEnt_Array1OfPosition::*)(GccEnt_Array1OfPosition &&)) &GccEnt_Array1OfPosition::Move, "Move assignment", py::arg("theOther"));
	cls_GccEnt_Array1OfPosition.def("assign", (GccEnt_Array1OfPosition & (GccEnt_Array1OfPosition::*)(const GccEnt_Array1OfPosition &)) &GccEnt_Array1OfPosition::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_GccEnt_Array1OfPosition.def("assign", (GccEnt_Array1OfPosition & (GccEnt_Array1OfPosition::*)(GccEnt_Array1OfPosition &&)) &GccEnt_Array1OfPosition::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_GccEnt_Array1OfPosition.def("First", (const GccEnt_Position & (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::First, "Returns first element");
	cls_GccEnt_Array1OfPosition.def("ChangeFirst", (GccEnt_Position & (GccEnt_Array1OfPosition::*)()) &GccEnt_Array1OfPosition::ChangeFirst, "Returns first element");
	cls_GccEnt_Array1OfPosition.def("Last", (const GccEnt_Position & (GccEnt_Array1OfPosition::*)() const ) &GccEnt_Array1OfPosition::Last, "Returns last element");
	cls_GccEnt_Array1OfPosition.def("ChangeLast", (GccEnt_Position & (GccEnt_Array1OfPosition::*)()) &GccEnt_Array1OfPosition::ChangeLast, "Returns last element");
	cls_GccEnt_Array1OfPosition.def("Value", (const GccEnt_Position & (GccEnt_Array1OfPosition::*)(const Standard_Integer) const ) &GccEnt_Array1OfPosition::Value, "Constant value access", py::arg("theIndex"));
	cls_GccEnt_Array1OfPosition.def("__call__", (const GccEnt_Position & (GccEnt_Array1OfPosition::*)(const Standard_Integer) const ) &GccEnt_Array1OfPosition::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_GccEnt_Array1OfPosition.def("ChangeValue", (GccEnt_Position & (GccEnt_Array1OfPosition::*)(const Standard_Integer)) &GccEnt_Array1OfPosition::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_GccEnt_Array1OfPosition.def("__call__", (GccEnt_Position & (GccEnt_Array1OfPosition::*)(const Standard_Integer)) &GccEnt_Array1OfPosition::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_GccEnt_Array1OfPosition.def("SetValue", (void (GccEnt_Array1OfPosition::*)(const Standard_Integer, const GccEnt_Position &)) &GccEnt_Array1OfPosition::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_GccEnt_Array1OfPosition.def("Resize", (void (GccEnt_Array1OfPosition::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &GccEnt_Array1OfPosition::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_GccEnt_Array1OfPosition.def("__iter__", [](const GccEnt_Array1OfPosition &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
