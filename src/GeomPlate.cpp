#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Law_Function.hxx>
#include <GeomLProp_SLProps.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Geom2d_Curve.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_Type.hxx>
#include <GeomPlate_CurveConstraint.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <GeomPlate_SequenceOfCurveConstraint.hxx>
#include <GeomPlate_HSequenceOfCurveConstraint.hxx>
#include <NCollection_Array1.hxx>
#include <GeomPlate_Array1OfSequenceOfReal.hxx>
#include <GeomPlate_HArray1OfSequenceOfReal.hxx>
#include <Geom_Surface.hxx>
#include <gp_Pnt2d.hxx>
#include <GeomPlate_PointConstraint.hxx>
#include <GeomPlate_SequenceOfPointConstraint.hxx>
#include <GeomPlate_HSequenceOfPointConstraint.hxx>
#include <GeomPlate_Array1OfHCurve.hxx>
#include <GeomPlate_HArray1OfHCurve.hxx>
#include <Plate_Plate.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf2d.hxx>
#include <Geom_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_Geometry.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <GeomPlate_Surface.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColgp_SequenceOfXYZ.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <GeomPlate_BuildPlateSurface.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_SequenceOfVec.hxx>
#include <Geom_Plane.hxx>
#include <Geom_Line.hxx>
#include <GeomPlate_SequenceOfAij.hxx>
#include <GeomPlate_BuildAveragePlane.hxx>
#include <GeomPlate_Aij.hxx>
#include <AdvApp2Var_Criterion.hxx>
#include <Geom_BSplineSurface.hxx>
#include <GeomPlate_MakeApprox.hxx>
#include <AdvApp2Var_CriterionType.hxx>
#include <AdvApp2Var_CriterionRepartition.hxx>
#include <AdvApp2Var_Patch.hxx>
#include <AdvApp2Var_Context.hxx>
#include <GeomPlate_PlateG0Criterion.hxx>
#include <GeomPlate_PlateG1Criterion.hxx>

PYBIND11_MODULE(GeomPlate, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.Law");
	py::module::import("OCCT.GeomLProp");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Plate");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TColGeom2d");
	py::module::import("OCCT.AdvApp2Var");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_CurveConstraint.hxx
	py::class_<GeomPlate_CurveConstraint, opencascade::handle<GeomPlate_CurveConstraint>, Standard_Transient> cls_GeomPlate_CurveConstraint(mod, "GeomPlate_CurveConstraint", "Defines curves as constraints to be used to deform a surface.");
	cls_GeomPlate_CurveConstraint.def(py::init<>());
	cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer>(), py::arg("Boundary"), py::arg("Order"));
	cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"));
	cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"));
	cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"), py::arg("TolAng"));
	cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"), py::arg("TolAng"), py::arg("TolCurv"));
	cls_GeomPlate_CurveConstraint.def("SetOrder", (void (GeomPlate_CurveConstraint::*)(const Standard_Integer)) &GeomPlate_CurveConstraint::SetOrder, "Allows you to set the order of continuity required for the constraints: G0, G1, and G2, controlled respectively by G0Criterion G1Criterion and G2Criterion.", py::arg("Order"));
	cls_GeomPlate_CurveConstraint.def("Order", (Standard_Integer (GeomPlate_CurveConstraint::*)() const ) &GeomPlate_CurveConstraint::Order, "Returns the order of constraint, one of G0, G1 or G2.");
	cls_GeomPlate_CurveConstraint.def("NbPoints", (Standard_Integer (GeomPlate_CurveConstraint::*)() const ) &GeomPlate_CurveConstraint::NbPoints, "Returns the number of points on the curve used as a constraint. The default setting is 10. This parameter affects computation time, which increases by the cube of the number of points.");
	cls_GeomPlate_CurveConstraint.def("SetNbPoints", (void (GeomPlate_CurveConstraint::*)(const Standard_Integer)) &GeomPlate_CurveConstraint::SetNbPoints, "Allows you to set the number of points on the curve constraint. The default setting is 10. This parameter affects computation time, which increases by the cube of the number of points.", py::arg("NewNb"));
	cls_GeomPlate_CurveConstraint.def("SetG0Criterion", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Law_Function> &)) &GeomPlate_CurveConstraint::SetG0Criterion, "Allows you to set the G0 criterion. This is the law defining the greatest distance allowed between the constraint and the target surface for each point of the constraint. If this criterion is not set, TolDist, the distance tolerance from the constructor, is used.", py::arg("G0Crit"));
	cls_GeomPlate_CurveConstraint.def("SetG1Criterion", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Law_Function> &)) &GeomPlate_CurveConstraint::SetG1Criterion, "Allows you to set the G1 criterion. This is the law defining the greatest angle allowed between the constraint and the target surface. If this criterion is not set, TolAng, the angular tolerance from the constructor, is used. Raises ConstructionError if the curve is not on a surface", py::arg("G1Crit"));
	cls_GeomPlate_CurveConstraint.def("SetG2Criterion", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Law_Function> &)) &GeomPlate_CurveConstraint::SetG2Criterion, "None", py::arg("G2Crit"));
	cls_GeomPlate_CurveConstraint.def("G0Criterion", (Standard_Real (GeomPlate_CurveConstraint::*)(const Standard_Real) const ) &GeomPlate_CurveConstraint::G0Criterion, "Returns the G0 criterion at the parametric point U on the curve. This is the greatest distance allowed between the constraint and the target surface at U.", py::arg("U"));
	cls_GeomPlate_CurveConstraint.def("G1Criterion", (Standard_Real (GeomPlate_CurveConstraint::*)(const Standard_Real) const ) &GeomPlate_CurveConstraint::G1Criterion, "Returns the G1 criterion at the parametric point U on the curve. This is the greatest angle allowed between the constraint and the target surface at U. Raises ConstructionError if the curve is not on a surface", py::arg("U"));
	cls_GeomPlate_CurveConstraint.def("G2Criterion", (Standard_Real (GeomPlate_CurveConstraint::*)(const Standard_Real) const ) &GeomPlate_CurveConstraint::G2Criterion, "Returns the G2 criterion at the parametric point U on the curve. This is the greatest difference in curvature allowed between the constraint and the target surface at U. Raises ConstructionError if the curve is not on a surface", py::arg("U"));
	cls_GeomPlate_CurveConstraint.def("FirstParameter", (Standard_Real (GeomPlate_CurveConstraint::*)() const ) &GeomPlate_CurveConstraint::FirstParameter, "None");
	cls_GeomPlate_CurveConstraint.def("LastParameter", (Standard_Real (GeomPlate_CurveConstraint::*)() const ) &GeomPlate_CurveConstraint::LastParameter, "None");
	cls_GeomPlate_CurveConstraint.def("Length", (Standard_Real (GeomPlate_CurveConstraint::*)() const ) &GeomPlate_CurveConstraint::Length, "None");
	cls_GeomPlate_CurveConstraint.def("LPropSurf", (GeomLProp_SLProps & (GeomPlate_CurveConstraint::*)(const Standard_Real)) &GeomPlate_CurveConstraint::LPropSurf, "None", py::arg("U"));
	cls_GeomPlate_CurveConstraint.def("D0", (void (GeomPlate_CurveConstraint::*)(const Standard_Real, gp_Pnt &) const ) &GeomPlate_CurveConstraint::D0, "None", py::arg("U"), py::arg("P"));
	cls_GeomPlate_CurveConstraint.def("D1", (void (GeomPlate_CurveConstraint::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &GeomPlate_CurveConstraint::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_GeomPlate_CurveConstraint.def("D2", (void (GeomPlate_CurveConstraint::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomPlate_CurveConstraint::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("V5"));
	cls_GeomPlate_CurveConstraint.def("Curve3d", (opencascade::handle<Adaptor3d_HCurve> (GeomPlate_CurveConstraint::*)() const ) &GeomPlate_CurveConstraint::Curve3d, "None");
	cls_GeomPlate_CurveConstraint.def("SetCurve2dOnSurf", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Geom2d_Curve> &)) &GeomPlate_CurveConstraint::SetCurve2dOnSurf, "loads a 2d curve associated the surface resulting of the constraints", py::arg("Curve2d"));
	cls_GeomPlate_CurveConstraint.def("Curve2dOnSurf", (opencascade::handle<Geom2d_Curve> (GeomPlate_CurveConstraint::*)() const ) &GeomPlate_CurveConstraint::Curve2dOnSurf, "Returns a 2d curve associated the surface resulting of the constraints");
	cls_GeomPlate_CurveConstraint.def("SetProjectedCurve", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Real)) &GeomPlate_CurveConstraint::SetProjectedCurve, "loads a 2d curve resulting from the normal projection of the curve on the initial surface", py::arg("Curve2d"), py::arg("TolU"), py::arg("TolV"));
	cls_GeomPlate_CurveConstraint.def("ProjectedCurve", (opencascade::handle<Adaptor2d_HCurve2d> (GeomPlate_CurveConstraint::*)() const ) &GeomPlate_CurveConstraint::ProjectedCurve, "Returns the projected curve resulting from the normal projection of the curve on the initial surface");
	cls_GeomPlate_CurveConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_CurveConstraint::get_type_name, "None");
	cls_GeomPlate_CurveConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_CurveConstraint::get_type_descriptor, "None");
	cls_GeomPlate_CurveConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_CurveConstraint::*)() const ) &GeomPlate_CurveConstraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<GeomPlate_SequenceOfCurveConstraint, std::unique_ptr<GeomPlate_SequenceOfCurveConstraint, Deleter<GeomPlate_SequenceOfCurveConstraint>>, NCollection_BaseSequence> cls_GeomPlate_SequenceOfCurveConstraint(mod, "GeomPlate_SequenceOfCurveConstraint", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_GeomPlate_SequenceOfCurveConstraint.def(py::init<>());
	cls_GeomPlate_SequenceOfCurveConstraint.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_GeomPlate_SequenceOfCurveConstraint.def(py::init([] (const GeomPlate_SequenceOfCurveConstraint &other) {return new GeomPlate_SequenceOfCurveConstraint(other);}), "Copy constructor", py::arg("other"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("begin", (GeomPlate_SequenceOfCurveConstraint::iterator (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_GeomPlate_SequenceOfCurveConstraint.def("end", (GeomPlate_SequenceOfCurveConstraint::iterator (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_GeomPlate_SequenceOfCurveConstraint.def("cbegin", (GeomPlate_SequenceOfCurveConstraint::const_iterator (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_GeomPlate_SequenceOfCurveConstraint.def("cend", (GeomPlate_SequenceOfCurveConstraint::const_iterator (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_GeomPlate_SequenceOfCurveConstraint.def("Size", (Standard_Integer (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::Size, "Number of items");
	cls_GeomPlate_SequenceOfCurveConstraint.def("Length", (Standard_Integer (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::Length, "Number of items");
	cls_GeomPlate_SequenceOfCurveConstraint.def("Lower", (Standard_Integer (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::Lower, "Method for consistency with other collections.");
	cls_GeomPlate_SequenceOfCurveConstraint.def("Upper", (Standard_Integer (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::Upper, "Method for consistency with other collections.");
	cls_GeomPlate_SequenceOfCurveConstraint.def("IsEmpty", (Standard_Boolean (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::IsEmpty, "Empty query");
	cls_GeomPlate_SequenceOfCurveConstraint.def("Reverse", (void (GeomPlate_SequenceOfCurveConstraint::*)()) &GeomPlate_SequenceOfCurveConstraint::Reverse, "Reverse sequence");
	cls_GeomPlate_SequenceOfCurveConstraint.def("Exchange", (void (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer, const Standard_Integer)) &GeomPlate_SequenceOfCurveConstraint::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_GeomPlate_SequenceOfCurveConstraint.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_SequenceOfCurveConstraint::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("Clear", [](GeomPlate_SequenceOfCurveConstraint &self) -> void { return self.Clear(); });
	cls_GeomPlate_SequenceOfCurveConstraint.def("Clear", (void (GeomPlate_SequenceOfCurveConstraint::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_SequenceOfCurveConstraint::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("Assign", (GeomPlate_SequenceOfCurveConstraint & (GeomPlate_SequenceOfCurveConstraint::*)(const GeomPlate_SequenceOfCurveConstraint &)) &GeomPlate_SequenceOfCurveConstraint::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("assign", (GeomPlate_SequenceOfCurveConstraint & (GeomPlate_SequenceOfCurveConstraint::*)(const GeomPlate_SequenceOfCurveConstraint &)) &GeomPlate_SequenceOfCurveConstraint::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("Remove", (void (GeomPlate_SequenceOfCurveConstraint::*)(GeomPlate_SequenceOfCurveConstraint::Iterator &)) &GeomPlate_SequenceOfCurveConstraint::Remove, "Remove one item", py::arg("thePosition"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("Remove", (void (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer)) &GeomPlate_SequenceOfCurveConstraint::Remove, "Remove one item", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("Remove", (void (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer, const Standard_Integer)) &GeomPlate_SequenceOfCurveConstraint::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("Append", (void (GeomPlate_SequenceOfCurveConstraint::*)(const opencascade::handle<GeomPlate_CurveConstraint> &)) &GeomPlate_SequenceOfCurveConstraint::Append, "Append one item", py::arg("theItem"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("Append", (void (GeomPlate_SequenceOfCurveConstraint::*)(GeomPlate_SequenceOfCurveConstraint &)) &GeomPlate_SequenceOfCurveConstraint::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("Prepend", (void (GeomPlate_SequenceOfCurveConstraint::*)(const opencascade::handle<GeomPlate_CurveConstraint> &)) &GeomPlate_SequenceOfCurveConstraint::Prepend, "Prepend one item", py::arg("theItem"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("Prepend", (void (GeomPlate_SequenceOfCurveConstraint::*)(GeomPlate_SequenceOfCurveConstraint &)) &GeomPlate_SequenceOfCurveConstraint::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("InsertBefore", (void (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer, const opencascade::handle<GeomPlate_CurveConstraint> &)) &GeomPlate_SequenceOfCurveConstraint::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("InsertBefore", (void (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer, GeomPlate_SequenceOfCurveConstraint &)) &GeomPlate_SequenceOfCurveConstraint::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("InsertAfter", (void (GeomPlate_SequenceOfCurveConstraint::*)(GeomPlate_SequenceOfCurveConstraint::Iterator &, const opencascade::handle<GeomPlate_CurveConstraint> &)) &GeomPlate_SequenceOfCurveConstraint::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("InsertAfter", (void (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer, GeomPlate_SequenceOfCurveConstraint &)) &GeomPlate_SequenceOfCurveConstraint::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("InsertAfter", (void (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer, const opencascade::handle<GeomPlate_CurveConstraint> &)) &GeomPlate_SequenceOfCurveConstraint::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("Split", (void (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer, GeomPlate_SequenceOfCurveConstraint &)) &GeomPlate_SequenceOfCurveConstraint::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("First", (const opencascade::handle<GeomPlate_CurveConstraint> & (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::First, "First item access");
	cls_GeomPlate_SequenceOfCurveConstraint.def("ChangeFirst", (opencascade::handle<GeomPlate_CurveConstraint> & (GeomPlate_SequenceOfCurveConstraint::*)()) &GeomPlate_SequenceOfCurveConstraint::ChangeFirst, "First item access");
	cls_GeomPlate_SequenceOfCurveConstraint.def("Last", (const opencascade::handle<GeomPlate_CurveConstraint> & (GeomPlate_SequenceOfCurveConstraint::*)() const ) &GeomPlate_SequenceOfCurveConstraint::Last, "Last item access");
	cls_GeomPlate_SequenceOfCurveConstraint.def("ChangeLast", (opencascade::handle<GeomPlate_CurveConstraint> & (GeomPlate_SequenceOfCurveConstraint::*)()) &GeomPlate_SequenceOfCurveConstraint::ChangeLast, "Last item access");
	cls_GeomPlate_SequenceOfCurveConstraint.def("Value", (const opencascade::handle<GeomPlate_CurveConstraint> & (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer) const ) &GeomPlate_SequenceOfCurveConstraint::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("__call__", (const opencascade::handle<GeomPlate_CurveConstraint> & (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer) const ) &GeomPlate_SequenceOfCurveConstraint::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("ChangeValue", (opencascade::handle<GeomPlate_CurveConstraint> & (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer)) &GeomPlate_SequenceOfCurveConstraint::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("__call__", (opencascade::handle<GeomPlate_CurveConstraint> & (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer)) &GeomPlate_SequenceOfCurveConstraint::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("SetValue", (void (GeomPlate_SequenceOfCurveConstraint::*)(const Standard_Integer, const opencascade::handle<GeomPlate_CurveConstraint> &)) &GeomPlate_SequenceOfCurveConstraint::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfCurveConstraint.def("__iter__", [](const GeomPlate_SequenceOfCurveConstraint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<GeomPlate_Array1OfSequenceOfReal, std::unique_ptr<GeomPlate_Array1OfSequenceOfReal, Deleter<GeomPlate_Array1OfSequenceOfReal>>> cls_GeomPlate_Array1OfSequenceOfReal(mod, "GeomPlate_Array1OfSequenceOfReal", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_GeomPlate_Array1OfSequenceOfReal.def(py::init<>());
	cls_GeomPlate_Array1OfSequenceOfReal.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_GeomPlate_Array1OfSequenceOfReal.def(py::init([] (const GeomPlate_Array1OfSequenceOfReal &other) {return new GeomPlate_Array1OfSequenceOfReal(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_GeomPlate_Array1OfSequenceOfReal.def(py::init<GeomPlate_Array1OfSequenceOfReal &&>(), py::arg("theOther"));
	cls_GeomPlate_Array1OfSequenceOfReal.def(py::init<const TColStd_SequenceOfReal &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_GeomPlate_Array1OfSequenceOfReal.def("begin", (GeomPlate_Array1OfSequenceOfReal::iterator (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::begin, "Returns an iterator pointing to the first element in the array.");
	cls_GeomPlate_Array1OfSequenceOfReal.def("end", (GeomPlate_Array1OfSequenceOfReal::iterator (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_GeomPlate_Array1OfSequenceOfReal.def("cbegin", (GeomPlate_Array1OfSequenceOfReal::const_iterator (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_GeomPlate_Array1OfSequenceOfReal.def("cend", (GeomPlate_Array1OfSequenceOfReal::const_iterator (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_GeomPlate_Array1OfSequenceOfReal.def("Init", (void (GeomPlate_Array1OfSequenceOfReal::*)(const TColStd_SequenceOfReal &)) &GeomPlate_Array1OfSequenceOfReal::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_GeomPlate_Array1OfSequenceOfReal.def("Size", (Standard_Integer (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::Size, "Size query");
	cls_GeomPlate_Array1OfSequenceOfReal.def("Length", (Standard_Integer (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::Length, "Length query (the same)");
	cls_GeomPlate_Array1OfSequenceOfReal.def("IsEmpty", (Standard_Boolean (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::IsEmpty, "Return TRUE if array has zero length.");
	cls_GeomPlate_Array1OfSequenceOfReal.def("Lower", (Standard_Integer (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::Lower, "Lower bound");
	cls_GeomPlate_Array1OfSequenceOfReal.def("Upper", (Standard_Integer (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::Upper, "Upper bound");
	cls_GeomPlate_Array1OfSequenceOfReal.def("IsDeletable", (Standard_Boolean (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::IsDeletable, "myDeletable flag");
	cls_GeomPlate_Array1OfSequenceOfReal.def("IsAllocated", (Standard_Boolean (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_GeomPlate_Array1OfSequenceOfReal.def("Assign", (GeomPlate_Array1OfSequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)(const GeomPlate_Array1OfSequenceOfReal &)) &GeomPlate_Array1OfSequenceOfReal::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_GeomPlate_Array1OfSequenceOfReal.def("Move", (GeomPlate_Array1OfSequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)(GeomPlate_Array1OfSequenceOfReal &&)) &GeomPlate_Array1OfSequenceOfReal::Move, "Move assignment", py::arg("theOther"));
	cls_GeomPlate_Array1OfSequenceOfReal.def("assign", (GeomPlate_Array1OfSequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)(const GeomPlate_Array1OfSequenceOfReal &)) &GeomPlate_Array1OfSequenceOfReal::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_GeomPlate_Array1OfSequenceOfReal.def("assign", (GeomPlate_Array1OfSequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)(GeomPlate_Array1OfSequenceOfReal &&)) &GeomPlate_Array1OfSequenceOfReal::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_GeomPlate_Array1OfSequenceOfReal.def("First", (const TColStd_SequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::First, "Returns first element");
	cls_GeomPlate_Array1OfSequenceOfReal.def("ChangeFirst", (TColStd_SequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)()) &GeomPlate_Array1OfSequenceOfReal::ChangeFirst, "Returns first element");
	cls_GeomPlate_Array1OfSequenceOfReal.def("Last", (const TColStd_SequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)() const ) &GeomPlate_Array1OfSequenceOfReal::Last, "Returns last element");
	cls_GeomPlate_Array1OfSequenceOfReal.def("ChangeLast", (TColStd_SequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)()) &GeomPlate_Array1OfSequenceOfReal::ChangeLast, "Returns last element");
	cls_GeomPlate_Array1OfSequenceOfReal.def("Value", (const TColStd_SequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)(const Standard_Integer) const ) &GeomPlate_Array1OfSequenceOfReal::Value, "Constant value access", py::arg("theIndex"));
	cls_GeomPlate_Array1OfSequenceOfReal.def("__call__", (const TColStd_SequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)(const Standard_Integer) const ) &GeomPlate_Array1OfSequenceOfReal::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_GeomPlate_Array1OfSequenceOfReal.def("ChangeValue", (TColStd_SequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)(const Standard_Integer)) &GeomPlate_Array1OfSequenceOfReal::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_GeomPlate_Array1OfSequenceOfReal.def("__call__", (TColStd_SequenceOfReal & (GeomPlate_Array1OfSequenceOfReal::*)(const Standard_Integer)) &GeomPlate_Array1OfSequenceOfReal::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_GeomPlate_Array1OfSequenceOfReal.def("SetValue", (void (GeomPlate_Array1OfSequenceOfReal::*)(const Standard_Integer, const TColStd_SequenceOfReal &)) &GeomPlate_Array1OfSequenceOfReal::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_Array1OfSequenceOfReal.def("Resize", (void (GeomPlate_Array1OfSequenceOfReal::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &GeomPlate_Array1OfSequenceOfReal::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_GeomPlate_Array1OfSequenceOfReal.def("__iter__", [](const GeomPlate_Array1OfSequenceOfReal &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_PointConstraint.hxx
	py::class_<GeomPlate_PointConstraint, opencascade::handle<GeomPlate_PointConstraint>, Standard_Transient> cls_GeomPlate_PointConstraint(mod, "GeomPlate_PointConstraint", "Defines points as constraints to be used to deform a surface.");
	cls_GeomPlate_PointConstraint.def(py::init<const gp_Pnt &, const Standard_Integer>(), py::arg("Pt"), py::arg("Order"));
	cls_GeomPlate_PointConstraint.def(py::init<const gp_Pnt &, const Standard_Integer, const Standard_Real>(), py::arg("Pt"), py::arg("Order"), py::arg("TolDist"));
	cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"));
	cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"), py::arg("TolDist"));
	cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"), py::arg("TolDist"), py::arg("TolAng"));
	cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"), py::arg("TolDist"), py::arg("TolAng"), py::arg("TolCurv"));
	cls_GeomPlate_PointConstraint.def("SetOrder", (void (GeomPlate_PointConstraint::*)(const Standard_Integer)) &GeomPlate_PointConstraint::SetOrder, "None", py::arg("Order"));
	cls_GeomPlate_PointConstraint.def("Order", (Standard_Integer (GeomPlate_PointConstraint::*)() const ) &GeomPlate_PointConstraint::Order, "Returns the order of constraint: G0, G1, and G2, controlled respectively by G0Criterion G1Criterion and G2Criterion.");
	cls_GeomPlate_PointConstraint.def("SetG0Criterion", (void (GeomPlate_PointConstraint::*)(const Standard_Real)) &GeomPlate_PointConstraint::SetG0Criterion, "Allows you to set the G0 criterion. This is the law defining the greatest distance allowed between the constraint and the target surface. If this criterion is not set, {TolDist, the distance tolerance from the constructor, is used", py::arg("TolDist"));
	cls_GeomPlate_PointConstraint.def("SetG1Criterion", (void (GeomPlate_PointConstraint::*)(const Standard_Real)) &GeomPlate_PointConstraint::SetG1Criterion, "Allows you to set the G1 criterion. This is the law defining the greatest angle allowed between the constraint and the target surface. If this criterion is not set, TolAng, the angular tolerance from the constructor, is used. Raises ConstructionError if the point is not on the surface", py::arg("TolAng"));
	cls_GeomPlate_PointConstraint.def("SetG2Criterion", (void (GeomPlate_PointConstraint::*)(const Standard_Real)) &GeomPlate_PointConstraint::SetG2Criterion, "Allows you to set the G2 criterion. This is the law defining the greatest difference in curvature allowed between the constraint and the target surface. If this criterion is not set, TolCurv, the curvature tolerance from the constructor, is used. Raises ConstructionError if the point is not on the surface", py::arg("TolCurv"));
	cls_GeomPlate_PointConstraint.def("G0Criterion", (Standard_Real (GeomPlate_PointConstraint::*)() const ) &GeomPlate_PointConstraint::G0Criterion, "Returns the G0 criterion. This is the greatest distance allowed between the constraint and the target surface.");
	cls_GeomPlate_PointConstraint.def("G1Criterion", (Standard_Real (GeomPlate_PointConstraint::*)() const ) &GeomPlate_PointConstraint::G1Criterion, "Returns the G1 criterion. This is the greatest angle allowed between the constraint and the target surface. Raises ConstructionError if the point is not on the surface.");
	cls_GeomPlate_PointConstraint.def("G2Criterion", (Standard_Real (GeomPlate_PointConstraint::*)() const ) &GeomPlate_PointConstraint::G2Criterion, "Returns the G2 criterion. This is the greatest difference in curvature allowed between the constraint and the target surface. Raises ConstructionError if the point is not on the surface");
	cls_GeomPlate_PointConstraint.def("D0", (void (GeomPlate_PointConstraint::*)(gp_Pnt &) const ) &GeomPlate_PointConstraint::D0, "None", py::arg("P"));
	cls_GeomPlate_PointConstraint.def("D1", (void (GeomPlate_PointConstraint::*)(gp_Pnt &, gp_Vec &, gp_Vec &) const ) &GeomPlate_PointConstraint::D1, "None", py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_GeomPlate_PointConstraint.def("D2", (void (GeomPlate_PointConstraint::*)(gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomPlate_PointConstraint::D2, "None", py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("V5"));
	cls_GeomPlate_PointConstraint.def("HasPnt2dOnSurf", (Standard_Boolean (GeomPlate_PointConstraint::*)() const ) &GeomPlate_PointConstraint::HasPnt2dOnSurf, "None");
	cls_GeomPlate_PointConstraint.def("SetPnt2dOnSurf", (void (GeomPlate_PointConstraint::*)(const gp_Pnt2d &)) &GeomPlate_PointConstraint::SetPnt2dOnSurf, "None", py::arg("Pnt"));
	cls_GeomPlate_PointConstraint.def("Pnt2dOnSurf", (gp_Pnt2d (GeomPlate_PointConstraint::*)() const ) &GeomPlate_PointConstraint::Pnt2dOnSurf, "None");
	cls_GeomPlate_PointConstraint.def("LPropSurf", (GeomLProp_SLProps & (GeomPlate_PointConstraint::*)()) &GeomPlate_PointConstraint::LPropSurf, "None");
	cls_GeomPlate_PointConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_PointConstraint::get_type_name, "None");
	cls_GeomPlate_PointConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_PointConstraint::get_type_descriptor, "None");
	cls_GeomPlate_PointConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_PointConstraint::*)() const ) &GeomPlate_PointConstraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<GeomPlate_SequenceOfPointConstraint, std::unique_ptr<GeomPlate_SequenceOfPointConstraint, Deleter<GeomPlate_SequenceOfPointConstraint>>, NCollection_BaseSequence> cls_GeomPlate_SequenceOfPointConstraint(mod, "GeomPlate_SequenceOfPointConstraint", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_GeomPlate_SequenceOfPointConstraint.def(py::init<>());
	cls_GeomPlate_SequenceOfPointConstraint.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_GeomPlate_SequenceOfPointConstraint.def(py::init([] (const GeomPlate_SequenceOfPointConstraint &other) {return new GeomPlate_SequenceOfPointConstraint(other);}), "Copy constructor", py::arg("other"));
	cls_GeomPlate_SequenceOfPointConstraint.def("begin", (GeomPlate_SequenceOfPointConstraint::iterator (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_GeomPlate_SequenceOfPointConstraint.def("end", (GeomPlate_SequenceOfPointConstraint::iterator (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_GeomPlate_SequenceOfPointConstraint.def("cbegin", (GeomPlate_SequenceOfPointConstraint::const_iterator (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_GeomPlate_SequenceOfPointConstraint.def("cend", (GeomPlate_SequenceOfPointConstraint::const_iterator (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_GeomPlate_SequenceOfPointConstraint.def("Size", (Standard_Integer (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::Size, "Number of items");
	cls_GeomPlate_SequenceOfPointConstraint.def("Length", (Standard_Integer (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::Length, "Number of items");
	cls_GeomPlate_SequenceOfPointConstraint.def("Lower", (Standard_Integer (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::Lower, "Method for consistency with other collections.");
	cls_GeomPlate_SequenceOfPointConstraint.def("Upper", (Standard_Integer (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::Upper, "Method for consistency with other collections.");
	cls_GeomPlate_SequenceOfPointConstraint.def("IsEmpty", (Standard_Boolean (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::IsEmpty, "Empty query");
	cls_GeomPlate_SequenceOfPointConstraint.def("Reverse", (void (GeomPlate_SequenceOfPointConstraint::*)()) &GeomPlate_SequenceOfPointConstraint::Reverse, "Reverse sequence");
	cls_GeomPlate_SequenceOfPointConstraint.def("Exchange", (void (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer, const Standard_Integer)) &GeomPlate_SequenceOfPointConstraint::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_GeomPlate_SequenceOfPointConstraint.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_SequenceOfPointConstraint::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_GeomPlate_SequenceOfPointConstraint.def("Clear", [](GeomPlate_SequenceOfPointConstraint &self) -> void { return self.Clear(); });
	cls_GeomPlate_SequenceOfPointConstraint.def("Clear", (void (GeomPlate_SequenceOfPointConstraint::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_SequenceOfPointConstraint::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_GeomPlate_SequenceOfPointConstraint.def("Assign", (GeomPlate_SequenceOfPointConstraint & (GeomPlate_SequenceOfPointConstraint::*)(const GeomPlate_SequenceOfPointConstraint &)) &GeomPlate_SequenceOfPointConstraint::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_GeomPlate_SequenceOfPointConstraint.def("assign", (GeomPlate_SequenceOfPointConstraint & (GeomPlate_SequenceOfPointConstraint::*)(const GeomPlate_SequenceOfPointConstraint &)) &GeomPlate_SequenceOfPointConstraint::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_GeomPlate_SequenceOfPointConstraint.def("Remove", (void (GeomPlate_SequenceOfPointConstraint::*)(GeomPlate_SequenceOfPointConstraint::Iterator &)) &GeomPlate_SequenceOfPointConstraint::Remove, "Remove one item", py::arg("thePosition"));
	cls_GeomPlate_SequenceOfPointConstraint.def("Remove", (void (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer)) &GeomPlate_SequenceOfPointConstraint::Remove, "Remove one item", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfPointConstraint.def("Remove", (void (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer, const Standard_Integer)) &GeomPlate_SequenceOfPointConstraint::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_GeomPlate_SequenceOfPointConstraint.def("Append", (void (GeomPlate_SequenceOfPointConstraint::*)(const opencascade::handle<GeomPlate_PointConstraint> &)) &GeomPlate_SequenceOfPointConstraint::Append, "Append one item", py::arg("theItem"));
	cls_GeomPlate_SequenceOfPointConstraint.def("Append", (void (GeomPlate_SequenceOfPointConstraint::*)(GeomPlate_SequenceOfPointConstraint &)) &GeomPlate_SequenceOfPointConstraint::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_GeomPlate_SequenceOfPointConstraint.def("Prepend", (void (GeomPlate_SequenceOfPointConstraint::*)(const opencascade::handle<GeomPlate_PointConstraint> &)) &GeomPlate_SequenceOfPointConstraint::Prepend, "Prepend one item", py::arg("theItem"));
	cls_GeomPlate_SequenceOfPointConstraint.def("Prepend", (void (GeomPlate_SequenceOfPointConstraint::*)(GeomPlate_SequenceOfPointConstraint &)) &GeomPlate_SequenceOfPointConstraint::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_GeomPlate_SequenceOfPointConstraint.def("InsertBefore", (void (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer, const opencascade::handle<GeomPlate_PointConstraint> &)) &GeomPlate_SequenceOfPointConstraint::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfPointConstraint.def("InsertBefore", (void (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer, GeomPlate_SequenceOfPointConstraint &)) &GeomPlate_SequenceOfPointConstraint::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_GeomPlate_SequenceOfPointConstraint.def("InsertAfter", (void (GeomPlate_SequenceOfPointConstraint::*)(GeomPlate_SequenceOfPointConstraint::Iterator &, const opencascade::handle<GeomPlate_PointConstraint> &)) &GeomPlate_SequenceOfPointConstraint::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfPointConstraint.def("InsertAfter", (void (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer, GeomPlate_SequenceOfPointConstraint &)) &GeomPlate_SequenceOfPointConstraint::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_GeomPlate_SequenceOfPointConstraint.def("InsertAfter", (void (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer, const opencascade::handle<GeomPlate_PointConstraint> &)) &GeomPlate_SequenceOfPointConstraint::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfPointConstraint.def("Split", (void (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer, GeomPlate_SequenceOfPointConstraint &)) &GeomPlate_SequenceOfPointConstraint::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_GeomPlate_SequenceOfPointConstraint.def("First", (const opencascade::handle<GeomPlate_PointConstraint> & (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::First, "First item access");
	cls_GeomPlate_SequenceOfPointConstraint.def("ChangeFirst", (opencascade::handle<GeomPlate_PointConstraint> & (GeomPlate_SequenceOfPointConstraint::*)()) &GeomPlate_SequenceOfPointConstraint::ChangeFirst, "First item access");
	cls_GeomPlate_SequenceOfPointConstraint.def("Last", (const opencascade::handle<GeomPlate_PointConstraint> & (GeomPlate_SequenceOfPointConstraint::*)() const ) &GeomPlate_SequenceOfPointConstraint::Last, "Last item access");
	cls_GeomPlate_SequenceOfPointConstraint.def("ChangeLast", (opencascade::handle<GeomPlate_PointConstraint> & (GeomPlate_SequenceOfPointConstraint::*)()) &GeomPlate_SequenceOfPointConstraint::ChangeLast, "Last item access");
	cls_GeomPlate_SequenceOfPointConstraint.def("Value", (const opencascade::handle<GeomPlate_PointConstraint> & (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer) const ) &GeomPlate_SequenceOfPointConstraint::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfPointConstraint.def("__call__", (const opencascade::handle<GeomPlate_PointConstraint> & (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer) const ) &GeomPlate_SequenceOfPointConstraint::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfPointConstraint.def("ChangeValue", (opencascade::handle<GeomPlate_PointConstraint> & (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer)) &GeomPlate_SequenceOfPointConstraint::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfPointConstraint.def("__call__", (opencascade::handle<GeomPlate_PointConstraint> & (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer)) &GeomPlate_SequenceOfPointConstraint::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfPointConstraint.def("SetValue", (void (GeomPlate_SequenceOfPointConstraint::*)(const Standard_Integer, const opencascade::handle<GeomPlate_PointConstraint> &)) &GeomPlate_SequenceOfPointConstraint::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfPointConstraint.def("__iter__", [](const GeomPlate_SequenceOfPointConstraint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<GeomPlate_Array1OfHCurve, std::unique_ptr<GeomPlate_Array1OfHCurve, Deleter<GeomPlate_Array1OfHCurve>>> cls_GeomPlate_Array1OfHCurve(mod, "GeomPlate_Array1OfHCurve", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_GeomPlate_Array1OfHCurve.def(py::init<>());
	cls_GeomPlate_Array1OfHCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_GeomPlate_Array1OfHCurve.def(py::init([] (const GeomPlate_Array1OfHCurve &other) {return new GeomPlate_Array1OfHCurve(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_GeomPlate_Array1OfHCurve.def(py::init<GeomPlate_Array1OfHCurve &&>(), py::arg("theOther"));
	cls_GeomPlate_Array1OfHCurve.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_GeomPlate_Array1OfHCurve.def("begin", (GeomPlate_Array1OfHCurve::iterator (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::begin, "Returns an iterator pointing to the first element in the array.");
	cls_GeomPlate_Array1OfHCurve.def("end", (GeomPlate_Array1OfHCurve::iterator (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_GeomPlate_Array1OfHCurve.def("cbegin", (GeomPlate_Array1OfHCurve::const_iterator (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_GeomPlate_Array1OfHCurve.def("cend", (GeomPlate_Array1OfHCurve::const_iterator (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_GeomPlate_Array1OfHCurve.def("Init", (void (GeomPlate_Array1OfHCurve::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomPlate_Array1OfHCurve::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_GeomPlate_Array1OfHCurve.def("Size", (Standard_Integer (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::Size, "Size query");
	cls_GeomPlate_Array1OfHCurve.def("Length", (Standard_Integer (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::Length, "Length query (the same)");
	cls_GeomPlate_Array1OfHCurve.def("IsEmpty", (Standard_Boolean (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::IsEmpty, "Return TRUE if array has zero length.");
	cls_GeomPlate_Array1OfHCurve.def("Lower", (Standard_Integer (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::Lower, "Lower bound");
	cls_GeomPlate_Array1OfHCurve.def("Upper", (Standard_Integer (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::Upper, "Upper bound");
	cls_GeomPlate_Array1OfHCurve.def("IsDeletable", (Standard_Boolean (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::IsDeletable, "myDeletable flag");
	cls_GeomPlate_Array1OfHCurve.def("IsAllocated", (Standard_Boolean (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_GeomPlate_Array1OfHCurve.def("Assign", (GeomPlate_Array1OfHCurve & (GeomPlate_Array1OfHCurve::*)(const GeomPlate_Array1OfHCurve &)) &GeomPlate_Array1OfHCurve::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_GeomPlate_Array1OfHCurve.def("Move", (GeomPlate_Array1OfHCurve & (GeomPlate_Array1OfHCurve::*)(GeomPlate_Array1OfHCurve &&)) &GeomPlate_Array1OfHCurve::Move, "Move assignment", py::arg("theOther"));
	cls_GeomPlate_Array1OfHCurve.def("assign", (GeomPlate_Array1OfHCurve & (GeomPlate_Array1OfHCurve::*)(const GeomPlate_Array1OfHCurve &)) &GeomPlate_Array1OfHCurve::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_GeomPlate_Array1OfHCurve.def("assign", (GeomPlate_Array1OfHCurve & (GeomPlate_Array1OfHCurve::*)(GeomPlate_Array1OfHCurve &&)) &GeomPlate_Array1OfHCurve::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_GeomPlate_Array1OfHCurve.def("First", (const opencascade::handle<Adaptor3d_HCurve> & (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::First, "Returns first element");
	cls_GeomPlate_Array1OfHCurve.def("ChangeFirst", (opencascade::handle<Adaptor3d_HCurve> & (GeomPlate_Array1OfHCurve::*)()) &GeomPlate_Array1OfHCurve::ChangeFirst, "Returns first element");
	cls_GeomPlate_Array1OfHCurve.def("Last", (const opencascade::handle<Adaptor3d_HCurve> & (GeomPlate_Array1OfHCurve::*)() const ) &GeomPlate_Array1OfHCurve::Last, "Returns last element");
	cls_GeomPlate_Array1OfHCurve.def("ChangeLast", (opencascade::handle<Adaptor3d_HCurve> & (GeomPlate_Array1OfHCurve::*)()) &GeomPlate_Array1OfHCurve::ChangeLast, "Returns last element");
	cls_GeomPlate_Array1OfHCurve.def("Value", (const opencascade::handle<Adaptor3d_HCurve> & (GeomPlate_Array1OfHCurve::*)(const Standard_Integer) const ) &GeomPlate_Array1OfHCurve::Value, "Constant value access", py::arg("theIndex"));
	cls_GeomPlate_Array1OfHCurve.def("__call__", (const opencascade::handle<Adaptor3d_HCurve> & (GeomPlate_Array1OfHCurve::*)(const Standard_Integer) const ) &GeomPlate_Array1OfHCurve::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_GeomPlate_Array1OfHCurve.def("ChangeValue", (opencascade::handle<Adaptor3d_HCurve> & (GeomPlate_Array1OfHCurve::*)(const Standard_Integer)) &GeomPlate_Array1OfHCurve::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_GeomPlate_Array1OfHCurve.def("__call__", (opencascade::handle<Adaptor3d_HCurve> & (GeomPlate_Array1OfHCurve::*)(const Standard_Integer)) &GeomPlate_Array1OfHCurve::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_GeomPlate_Array1OfHCurve.def("SetValue", (void (GeomPlate_Array1OfHCurve::*)(const Standard_Integer, const opencascade::handle<Adaptor3d_HCurve> &)) &GeomPlate_Array1OfHCurve::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_Array1OfHCurve.def("Resize", (void (GeomPlate_Array1OfHCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &GeomPlate_Array1OfHCurve::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_GeomPlate_Array1OfHCurve.def("__iter__", [](const GeomPlate_Array1OfHCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_Surface.hxx
	py::class_<GeomPlate_Surface, opencascade::handle<GeomPlate_Surface>, Geom_Surface> cls_GeomPlate_Surface(mod, "GeomPlate_Surface", "Describes the characteristics of plate surface objects returned by BuildPlateSurface::Surface. These can be used to verify the quality of the resulting surface before approximating it to a Geom_BSpline surface generated by MakeApprox. This proves necessary in cases where you want to use the resulting surface as the support for a shape. The algorithmically generated surface cannot fill this function as is, and as a result must be converted first.");
	cls_GeomPlate_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Plate_Plate &>(), py::arg("Surfinit"), py::arg("Surfinter"));
	cls_GeomPlate_Surface.def("UReverse", (void (GeomPlate_Surface::*)()) &GeomPlate_Surface::UReverse, "Reverses the U direction of parametrization of <me>. The bounds of the surface are not modified.");
	cls_GeomPlate_Surface.def("UReversedParameter", (Standard_Real (GeomPlate_Surface::*)(const Standard_Real) const ) &GeomPlate_Surface::UReversedParameter, "Return the parameter on the Ureversed surface for the point of parameter U on <me>.", py::arg("U"));
	cls_GeomPlate_Surface.def("VReverse", (void (GeomPlate_Surface::*)()) &GeomPlate_Surface::VReverse, "Reverses the V direction of parametrization of <me>. The bounds of the surface are not modified.");
	cls_GeomPlate_Surface.def("VReversedParameter", (Standard_Real (GeomPlate_Surface::*)(const Standard_Real) const ) &GeomPlate_Surface::VReversedParameter, "Return the parameter on the Vreversed surface for the point of parameter V on <me>.", py::arg("V"));
	cls_GeomPlate_Surface.def("TransformParameters", (void (GeomPlate_Surface::*)(Standard_Real &, Standard_Real &, const gp_Trsf &) const ) &GeomPlate_Surface::TransformParameters, "Computes the parameters on the transformed surface for the transform of the point of parameters U,V on <me>.", py::arg("U"), py::arg("V"), py::arg("T"));
	cls_GeomPlate_Surface.def("ParametricTransformation", (gp_GTrsf2d (GeomPlate_Surface::*)(const gp_Trsf &) const ) &GeomPlate_Surface::ParametricTransformation, "Returns a 2d transformation used to find the new parameters of a point on the transformed surface.", py::arg("T"));
	cls_GeomPlate_Surface.def("Bounds", (void (GeomPlate_Surface::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &GeomPlate_Surface::Bounds, "None", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
	cls_GeomPlate_Surface.def("IsUClosed", (Standard_Boolean (GeomPlate_Surface::*)() const ) &GeomPlate_Surface::IsUClosed, "Is the surface closed in the parametric direction U ? Returns True if for each parameter V the distance between the point P (UFirst, V) and P (ULast, V) is lower or equal to Resolution from gp. UFirst and ULast are the parametric bounds in the U direction.");
	cls_GeomPlate_Surface.def("IsVClosed", (Standard_Boolean (GeomPlate_Surface::*)() const ) &GeomPlate_Surface::IsVClosed, "Is the surface closed in the parametric direction V ? Returns True if for each parameter U the distance between the point P (U, VFirst) and P (U, VLast) is lower or equal to Resolution from gp. VFirst and VLast are the parametric bounds in the V direction.");
	cls_GeomPlate_Surface.def("IsUPeriodic", (Standard_Boolean (GeomPlate_Surface::*)() const ) &GeomPlate_Surface::IsUPeriodic, "Is the parametrization of a surface periodic in the direction U ? It is possible only if the surface is closed in this parametric direction and if the following relation is satisfied : for each parameter V the distance between the point P (U, V) and the point P (U + T, V) is lower or equal to Resolution from package gp. T is the parametric period and must be a constant.");
	cls_GeomPlate_Surface.def("UPeriod", (Standard_Real (GeomPlate_Surface::*)() const ) &GeomPlate_Surface::UPeriod, "returns the Uperiod. raises if the surface is not uperiodic.");
	cls_GeomPlate_Surface.def("IsVPeriodic", (Standard_Boolean (GeomPlate_Surface::*)() const ) &GeomPlate_Surface::IsVPeriodic, "Is the parametrization of a surface periodic in the direction U ? It is possible only if the surface is closed in this parametric direction and if the following relation is satisfied : for each parameter V the distance between the point P (U, V) and the point P (U + T, V) is lower or equal to Resolution from package gp. T is the parametric period and must be a constant.");
	cls_GeomPlate_Surface.def("VPeriod", (Standard_Real (GeomPlate_Surface::*)() const ) &GeomPlate_Surface::VPeriod, "returns the Vperiod. raises if the surface is not vperiodic.");
	cls_GeomPlate_Surface.def("UIso", (opencascade::handle<Geom_Curve> (GeomPlate_Surface::*)(const Standard_Real) const ) &GeomPlate_Surface::UIso, "Computes the U isoparametric curve.", py::arg("U"));
	cls_GeomPlate_Surface.def("VIso", (opencascade::handle<Geom_Curve> (GeomPlate_Surface::*)(const Standard_Real) const ) &GeomPlate_Surface::VIso, "Computes the V isoparametric curve.", py::arg("V"));
	cls_GeomPlate_Surface.def("Continuity", (GeomAbs_Shape (GeomPlate_Surface::*)() const ) &GeomPlate_Surface::Continuity, "Global Continuity of the surface in direction U and V : C0 : only geometric continuity, C1 : continuity of the first derivative all along the surface, C2 : continuity of the second derivative all along the surface, C3 : continuity of the third derivative all along the surface, G1 : tangency continuity all along the surface, G2 : curvature continuity all along the surface, CN : the order of continuity is infinite. Example : If the surface is C1 in the V parametric direction and C2 in the U parametric direction Shape = C1.");
	cls_GeomPlate_Surface.def("IsCNu", (Standard_Boolean (GeomPlate_Surface::*)(const Standard_Integer) const ) &GeomPlate_Surface::IsCNu, "Returns the order of continuity of the surface in the U parametric direction. Raised if N < 0.", py::arg("N"));
	cls_GeomPlate_Surface.def("IsCNv", (Standard_Boolean (GeomPlate_Surface::*)(const Standard_Integer) const ) &GeomPlate_Surface::IsCNv, "Returns the order of continuity of the surface in the V parametric direction. Raised if N < 0.", py::arg("N"));
	cls_GeomPlate_Surface.def("D0", (void (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const ) &GeomPlate_Surface::D0, "Computes the point of parameter U,V on the surface.", py::arg("U"), py::arg("V"), py::arg("P"));
	cls_GeomPlate_Surface.def("D1", (void (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &GeomPlate_Surface::D1, "Computes the point P and the first derivatives in the directions U and V at this point. Raised if the continuity of the surface is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
	cls_GeomPlate_Surface.def("D2", (void (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomPlate_Surface::D2, "Computes the point P, the first and the second derivatives in the directions U and V at this point. Raised if the continuity of the surface is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
	cls_GeomPlate_Surface.def("D3", (void (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomPlate_Surface::D3, "Computes the point P, the first,the second and the third derivatives in the directions U and V at this point. Raised if the continuity of the surface is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
	cls_GeomPlate_Surface.def("DN", (gp_Vec (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &GeomPlate_Surface::DN, "---Purpose ; Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V).", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
	cls_GeomPlate_Surface.def("Copy", (opencascade::handle<Geom_Geometry> (GeomPlate_Surface::*)() const ) &GeomPlate_Surface::Copy, "None");
	cls_GeomPlate_Surface.def("Transform", (void (GeomPlate_Surface::*)(const gp_Trsf &)) &GeomPlate_Surface::Transform, "Transformation of a geometric object. This tansformation can be a translation, a rotation, a symmetry, a scaling or a complex transformation obtained by combination of the previous elementaries transformations. (see class Transformation of the package Geom).", py::arg("T"));
	cls_GeomPlate_Surface.def("CallSurfinit", (opencascade::handle<Geom_Surface> (GeomPlate_Surface::*)() const ) &GeomPlate_Surface::CallSurfinit, "None");
	cls_GeomPlate_Surface.def("SetBounds", (void (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomPlate_Surface::SetBounds, "None", py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
	cls_GeomPlate_Surface.def("RealBounds", (void (GeomPlate_Surface::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &GeomPlate_Surface::RealBounds, "None", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
	cls_GeomPlate_Surface.def("Constraints", (void (GeomPlate_Surface::*)(TColgp_SequenceOfXY &) const ) &GeomPlate_Surface::Constraints, "None", py::arg("Seq"));
	cls_GeomPlate_Surface.def_static("get_type_name_", (const char * (*)()) &GeomPlate_Surface::get_type_name, "None");
	cls_GeomPlate_Surface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_Surface::get_type_descriptor, "None");
	cls_GeomPlate_Surface.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_Surface::*)() const ) &GeomPlate_Surface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_BuildPlateSurface.hxx
	py::class_<GeomPlate_BuildPlateSurface, std::unique_ptr<GeomPlate_BuildPlateSurface, Deleter<GeomPlate_BuildPlateSurface>>> cls_GeomPlate_BuildPlateSurface(mod, "GeomPlate_BuildPlateSurface", "This class provides an algorithm for constructing such a plate surface that it conforms to given curve and/or point constraints. The algorithm accepts or constructs an initial surface and looks for a deformation of it satisfying the constraints and minimizing energy input. A BuildPlateSurface object provides a framework for: - defining or setting constraints - implementing the construction algorithm - consulting the result.");
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"), py::arg("Tol2d"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("Anisotropie"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("Surf"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer>(), py::arg("Surf"), py::arg("Degree"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("Anisotropie"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<>());
	cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer>(), py::arg("Degree"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
	cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("Anisotropie"));
	cls_GeomPlate_BuildPlateSurface.def("Init", (void (GeomPlate_BuildPlateSurface::*)()) &GeomPlate_BuildPlateSurface::Init, "Resets all constraints");
	cls_GeomPlate_BuildPlateSurface.def("LoadInitSurface", (void (GeomPlate_BuildPlateSurface::*)(const opencascade::handle<Geom_Surface> &)) &GeomPlate_BuildPlateSurface::LoadInitSurface, "Loads the initial Surface", py::arg("Surf"));
	cls_GeomPlate_BuildPlateSurface.def("Add", (void (GeomPlate_BuildPlateSurface::*)(const opencascade::handle<GeomPlate_CurveConstraint> &)) &GeomPlate_BuildPlateSurface::Add, "Adds the linear constraint cont.", py::arg("Cont"));
	cls_GeomPlate_BuildPlateSurface.def("SetNbBounds", (void (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::SetNbBounds, "None", py::arg("NbBounds"));
	cls_GeomPlate_BuildPlateSurface.def("Add", (void (GeomPlate_BuildPlateSurface::*)(const opencascade::handle<GeomPlate_PointConstraint> &)) &GeomPlate_BuildPlateSurface::Add, "Adds the point constraint cont.", py::arg("Cont"));
	cls_GeomPlate_BuildPlateSurface.def("Perform", (void (GeomPlate_BuildPlateSurface::*)()) &GeomPlate_BuildPlateSurface::Perform, "Calls the algorithm and computes the plate surface using the loaded constraints. If no initial surface is given, the algorithm automatically computes one. Exceptions Standard_RangeError if the value of the constraint is null or if plate is not done.");
	cls_GeomPlate_BuildPlateSurface.def("CurveConstraint", (opencascade::handle<GeomPlate_CurveConstraint> (GeomPlate_BuildPlateSurface::*)(const Standard_Integer) const ) &GeomPlate_BuildPlateSurface::CurveConstraint, "returns the CurveConstraints of order order", py::arg("order"));
	cls_GeomPlate_BuildPlateSurface.def("PointConstraint", (opencascade::handle<GeomPlate_PointConstraint> (GeomPlate_BuildPlateSurface::*)(const Standard_Integer) const ) &GeomPlate_BuildPlateSurface::PointConstraint, "returns the PointConstraint of order order", py::arg("order"));
	cls_GeomPlate_BuildPlateSurface.def("Disc2dContour", (void (GeomPlate_BuildPlateSurface::*)(const Standard_Integer, TColgp_SequenceOfXY &)) &GeomPlate_BuildPlateSurface::Disc2dContour, "None", py::arg("nbp"), py::arg("Seq2d"));
	cls_GeomPlate_BuildPlateSurface.def("Disc3dContour", (void (GeomPlate_BuildPlateSurface::*)(const Standard_Integer, const Standard_Integer, TColgp_SequenceOfXYZ &)) &GeomPlate_BuildPlateSurface::Disc3dContour, "None", py::arg("nbp"), py::arg("iordre"), py::arg("Seq3d"));
	cls_GeomPlate_BuildPlateSurface.def("IsDone", (Standard_Boolean (GeomPlate_BuildPlateSurface::*)() const ) &GeomPlate_BuildPlateSurface::IsDone, "Tests whether computation of the plate has been completed.");
	cls_GeomPlate_BuildPlateSurface.def("Surface", (opencascade::handle<GeomPlate_Surface> (GeomPlate_BuildPlateSurface::*)() const ) &GeomPlate_BuildPlateSurface::Surface, "Returns the result of the computation. This surface can then be used by GeomPlate_MakeApprox for converting the resulting surface into a BSpline.");
	cls_GeomPlate_BuildPlateSurface.def("SurfInit", (opencascade::handle<Geom_Surface> (GeomPlate_BuildPlateSurface::*)() const ) &GeomPlate_BuildPlateSurface::SurfInit, "Returns the initial surface");
	cls_GeomPlate_BuildPlateSurface.def("Sense", (opencascade::handle<TColStd_HArray1OfInteger> (GeomPlate_BuildPlateSurface::*)() const ) &GeomPlate_BuildPlateSurface::Sense, "Allows you to ensure that the array of curves returned by Curves2d has the correct orientation. Returns the orientation of the curves in the the array returned by Curves2d. Computation changes the orientation of these curves. Consequently, this method returns the orientation prior to computation.");
	cls_GeomPlate_BuildPlateSurface.def("Curves2d", (opencascade::handle<TColGeom2d_HArray1OfCurve> (GeomPlate_BuildPlateSurface::*)() const ) &GeomPlate_BuildPlateSurface::Curves2d, "Extracts the array of curves on the plate surface which correspond to the curve constraints set in Add.");
	cls_GeomPlate_BuildPlateSurface.def("Order", (opencascade::handle<TColStd_HArray1OfInteger> (GeomPlate_BuildPlateSurface::*)() const ) &GeomPlate_BuildPlateSurface::Order, "Returns the order of the curves in the array returned by Curves2d. Computation changes this order. Consequently, this method returns the order of the curves prior to computation.");
	cls_GeomPlate_BuildPlateSurface.def("G0Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)() const ) &GeomPlate_BuildPlateSurface::G0Error, "Returns the max distance betwen the result and the constraints");
	cls_GeomPlate_BuildPlateSurface.def("G1Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)() const ) &GeomPlate_BuildPlateSurface::G1Error, "Returns the max angle betwen the result and the constraints");
	cls_GeomPlate_BuildPlateSurface.def("G2Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)() const ) &GeomPlate_BuildPlateSurface::G2Error, "Returns the max difference of curvature betwen the result and the constraints");
	cls_GeomPlate_BuildPlateSurface.def("G0Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::G0Error, "Returns the max distance between the result and the constraint Index", py::arg("Index"));
	cls_GeomPlate_BuildPlateSurface.def("G1Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::G1Error, "Returns the max angle between the result and the constraint Index", py::arg("Index"));
	cls_GeomPlate_BuildPlateSurface.def("G2Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::G2Error, "Returns the max difference of curvature between the result and the constraint Index", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_BuildAveragePlane.hxx
	py::class_<GeomPlate_BuildAveragePlane, std::unique_ptr<GeomPlate_BuildAveragePlane, Deleter<GeomPlate_BuildAveragePlane>>> cls_GeomPlate_BuildAveragePlane(mod, "GeomPlate_BuildAveragePlane", "This class computes an average inertial plane with an array of points. Computes the initial surface (average plane) in the cases when the initial surface is not given.");
	cls_GeomPlate_BuildAveragePlane.def(py::init<const opencascade::handle<TColgp_HArray1OfPnt> &, const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("Pts"), py::arg("NbBoundPoints"), py::arg("Tol"), py::arg("POption"), py::arg("NOption"));
	cls_GeomPlate_BuildAveragePlane.def(py::init<const TColgp_SequenceOfVec &, const opencascade::handle<TColgp_HArray1OfPnt> &>(), py::arg("Normals"), py::arg("Pts"));
	cls_GeomPlate_BuildAveragePlane.def("Plane", (opencascade::handle<Geom_Plane> (GeomPlate_BuildAveragePlane::*)() const ) &GeomPlate_BuildAveragePlane::Plane, "Return the average Plane.");
	cls_GeomPlate_BuildAveragePlane.def("Line", (opencascade::handle<Geom_Line> (GeomPlate_BuildAveragePlane::*)() const ) &GeomPlate_BuildAveragePlane::Line, "Return a Line when 2 eigenvalues are null.");
	cls_GeomPlate_BuildAveragePlane.def("IsPlane", (Standard_Boolean (GeomPlate_BuildAveragePlane::*)() const ) &GeomPlate_BuildAveragePlane::IsPlane, "return OK if is a plane.");
	cls_GeomPlate_BuildAveragePlane.def("IsLine", (Standard_Boolean (GeomPlate_BuildAveragePlane::*)() const ) &GeomPlate_BuildAveragePlane::IsLine, "return OK if is a line.");
	cls_GeomPlate_BuildAveragePlane.def("MinMaxBox", (void (GeomPlate_BuildAveragePlane::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &GeomPlate_BuildAveragePlane::MinMaxBox, "computes the minimal box to include all normal projection points of the initial array on the plane.", py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
	cls_GeomPlate_BuildAveragePlane.def_static("HalfSpace_", (Standard_Boolean (*)(const TColgp_SequenceOfVec &, TColgp_SequenceOfVec &, GeomPlate_SequenceOfAij &, const Standard_Real, const Standard_Real)) &GeomPlate_BuildAveragePlane::HalfSpace, "None", py::arg("NewNormals"), py::arg("Normals"), py::arg("Bset"), py::arg("LinTol"), py::arg("AngTol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_Aij.hxx
	py::class_<GeomPlate_Aij, std::unique_ptr<GeomPlate_Aij, Deleter<GeomPlate_Aij>>> cls_GeomPlate_Aij(mod, "GeomPlate_Aij", "A structure containing indexes of two normals and its cross product");
	cls_GeomPlate_Aij.def(py::init<>());
	cls_GeomPlate_Aij.def(py::init<const Standard_Integer, const Standard_Integer, const gp_Vec &>(), py::arg("anInd1"), py::arg("anInd2"), py::arg("aVec"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_MakeApprox.hxx
	py::class_<GeomPlate_MakeApprox, std::unique_ptr<GeomPlate_MakeApprox, Deleter<GeomPlate_MakeApprox>>> cls_GeomPlate_MakeApprox(mod, "GeomPlate_MakeApprox", "Allows you to convert a GeomPlate surface into a BSpline.");
	cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const AdvApp2Var_Criterion &, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("SurfPlate"), py::arg("PlateCrit"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"));
	cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const AdvApp2Var_Criterion &, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("SurfPlate"), py::arg("PlateCrit"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("Continuity"));
	cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const AdvApp2Var_Criterion &, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("SurfPlate"), py::arg("PlateCrit"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("Continuity"), py::arg("EnlargeCoeff"));
	cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"));
	cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"), py::arg("CritOrder"));
	cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer, const GeomAbs_Shape>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"), py::arg("CritOrder"), py::arg("Continuity"));
	cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"), py::arg("CritOrder"), py::arg("Continuity"), py::arg("EnlargeCoeff"));
	cls_GeomPlate_MakeApprox.def("Surface", (opencascade::handle<Geom_BSplineSurface> (GeomPlate_MakeApprox::*)() const ) &GeomPlate_MakeApprox::Surface, "Returns the BSpline surface extracted from the GeomPlate_MakeApprox object.");
	cls_GeomPlate_MakeApprox.def("ApproxError", (Standard_Real (GeomPlate_MakeApprox::*)() const ) &GeomPlate_MakeApprox::ApproxError, "Returns the error in computation of the approximation surface. This is the distance between the entire target BSpline surface and the entire original surface generated by BuildPlateSurface and converted by GeomPlate_Surface.");
	cls_GeomPlate_MakeApprox.def("CriterionError", (Standard_Real (GeomPlate_MakeApprox::*)() const ) &GeomPlate_MakeApprox::CriterionError, "Returns the criterion error in computation of the approximation surface. This is estimated relative to the curve and point constraints only.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_PlateG0Criterion.hxx
	py::class_<GeomPlate_PlateG0Criterion, std::unique_ptr<GeomPlate_PlateG0Criterion, Deleter<GeomPlate_PlateG0Criterion>>, AdvApp2Var_Criterion> cls_GeomPlate_PlateG0Criterion(mod, "GeomPlate_PlateG0Criterion", "this class contains a specific G0 criterion for GeomPlate_MakeApprox");
	cls_GeomPlate_PlateG0Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real>(), py::arg("Data"), py::arg("G0Data"), py::arg("Maximum"));
	cls_GeomPlate_PlateG0Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real, const AdvApp2Var_CriterionType>(), py::arg("Data"), py::arg("G0Data"), py::arg("Maximum"), py::arg("Type"));
	cls_GeomPlate_PlateG0Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real, const AdvApp2Var_CriterionType, const AdvApp2Var_CriterionRepartition>(), py::arg("Data"), py::arg("G0Data"), py::arg("Maximum"), py::arg("Type"), py::arg("Repart"));
	cls_GeomPlate_PlateG0Criterion.def("Value", (void (GeomPlate_PlateG0Criterion::*)(AdvApp2Var_Patch &, const AdvApp2Var_Context &) const ) &GeomPlate_PlateG0Criterion::Value, "None", py::arg("P"), py::arg("C"));
	cls_GeomPlate_PlateG0Criterion.def("IsSatisfied", (Standard_Boolean (GeomPlate_PlateG0Criterion::*)(const AdvApp2Var_Patch &) const ) &GeomPlate_PlateG0Criterion::IsSatisfied, "None", py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_PlateG1Criterion.hxx
	py::class_<GeomPlate_PlateG1Criterion, std::unique_ptr<GeomPlate_PlateG1Criterion, Deleter<GeomPlate_PlateG1Criterion>>, AdvApp2Var_Criterion> cls_GeomPlate_PlateG1Criterion(mod, "GeomPlate_PlateG1Criterion", "this class contains a specific G1 criterion for GeomPlate_MakeApprox");
	cls_GeomPlate_PlateG1Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real>(), py::arg("Data"), py::arg("G1Data"), py::arg("Maximum"));
	cls_GeomPlate_PlateG1Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real, const AdvApp2Var_CriterionType>(), py::arg("Data"), py::arg("G1Data"), py::arg("Maximum"), py::arg("Type"));
	cls_GeomPlate_PlateG1Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real, const AdvApp2Var_CriterionType, const AdvApp2Var_CriterionRepartition>(), py::arg("Data"), py::arg("G1Data"), py::arg("Maximum"), py::arg("Type"), py::arg("Repart"));
	cls_GeomPlate_PlateG1Criterion.def("Value", (void (GeomPlate_PlateG1Criterion::*)(AdvApp2Var_Patch &, const AdvApp2Var_Context &) const ) &GeomPlate_PlateG1Criterion::Value, "None", py::arg("P"), py::arg("C"));
	cls_GeomPlate_PlateG1Criterion.def("IsSatisfied", (Standard_Boolean (GeomPlate_PlateG1Criterion::*)(const AdvApp2Var_Patch &) const ) &GeomPlate_PlateG1Criterion::IsSatisfied, "None", py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_HSequenceOfCurveConstraint.hxx
	py::class_<GeomPlate_HSequenceOfCurveConstraint, opencascade::handle<GeomPlate_HSequenceOfCurveConstraint>, GeomPlate_SequenceOfCurveConstraint, Standard_Transient> cls_GeomPlate_HSequenceOfCurveConstraint(mod, "GeomPlate_HSequenceOfCurveConstraint", "None");
	cls_GeomPlate_HSequenceOfCurveConstraint.def(py::init<>());
	cls_GeomPlate_HSequenceOfCurveConstraint.def(py::init<const GeomPlate_SequenceOfCurveConstraint &>(), py::arg("theOther"));
	cls_GeomPlate_HSequenceOfCurveConstraint.def("Sequence", (const GeomPlate_SequenceOfCurveConstraint & (GeomPlate_HSequenceOfCurveConstraint::*)() const ) &GeomPlate_HSequenceOfCurveConstraint::Sequence, "None");
	cls_GeomPlate_HSequenceOfCurveConstraint.def("Append", (void (GeomPlate_HSequenceOfCurveConstraint::*)(const GeomPlate_SequenceOfCurveConstraint::value_type &)) &GeomPlate_HSequenceOfCurveConstraint::Append, "None", py::arg("theItem"));
	cls_GeomPlate_HSequenceOfCurveConstraint.def("Append", (void (GeomPlate_HSequenceOfCurveConstraint::*)(GeomPlate_SequenceOfCurveConstraint &)) &GeomPlate_HSequenceOfCurveConstraint::Append, "None", py::arg("theSequence"));
	cls_GeomPlate_HSequenceOfCurveConstraint.def("ChangeSequence", (GeomPlate_SequenceOfCurveConstraint & (GeomPlate_HSequenceOfCurveConstraint::*)()) &GeomPlate_HSequenceOfCurveConstraint::ChangeSequence, "None");
	cls_GeomPlate_HSequenceOfCurveConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_HSequenceOfCurveConstraint::get_type_name, "None");
	cls_GeomPlate_HSequenceOfCurveConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_HSequenceOfCurveConstraint::get_type_descriptor, "None");
	cls_GeomPlate_HSequenceOfCurveConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_HSequenceOfCurveConstraint::*)() const ) &GeomPlate_HSequenceOfCurveConstraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_HArray1OfSequenceOfReal.hxx
	py::class_<GeomPlate_HArray1OfSequenceOfReal, opencascade::handle<GeomPlate_HArray1OfSequenceOfReal>, GeomPlate_Array1OfSequenceOfReal, Standard_Transient> cls_GeomPlate_HArray1OfSequenceOfReal(mod, "GeomPlate_HArray1OfSequenceOfReal", "None");
	cls_GeomPlate_HArray1OfSequenceOfReal.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_GeomPlate_HArray1OfSequenceOfReal.def(py::init<const Standard_Integer, const Standard_Integer, const GeomPlate_Array1OfSequenceOfReal::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_GeomPlate_HArray1OfSequenceOfReal.def(py::init<const GeomPlate_Array1OfSequenceOfReal &>(), py::arg("theOther"));
	cls_GeomPlate_HArray1OfSequenceOfReal.def("Array1", (const GeomPlate_Array1OfSequenceOfReal & (GeomPlate_HArray1OfSequenceOfReal::*)() const ) &GeomPlate_HArray1OfSequenceOfReal::Array1, "None");
	cls_GeomPlate_HArray1OfSequenceOfReal.def("ChangeArray1", (GeomPlate_Array1OfSequenceOfReal & (GeomPlate_HArray1OfSequenceOfReal::*)()) &GeomPlate_HArray1OfSequenceOfReal::ChangeArray1, "None");
	cls_GeomPlate_HArray1OfSequenceOfReal.def_static("get_type_name_", (const char * (*)()) &GeomPlate_HArray1OfSequenceOfReal::get_type_name, "None");
	cls_GeomPlate_HArray1OfSequenceOfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_HArray1OfSequenceOfReal::get_type_descriptor, "None");
	cls_GeomPlate_HArray1OfSequenceOfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_HArray1OfSequenceOfReal::*)() const ) &GeomPlate_HArray1OfSequenceOfReal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_HSequenceOfPointConstraint.hxx
	py::class_<GeomPlate_HSequenceOfPointConstraint, opencascade::handle<GeomPlate_HSequenceOfPointConstraint>, GeomPlate_SequenceOfPointConstraint, Standard_Transient> cls_GeomPlate_HSequenceOfPointConstraint(mod, "GeomPlate_HSequenceOfPointConstraint", "None");
	cls_GeomPlate_HSequenceOfPointConstraint.def(py::init<>());
	cls_GeomPlate_HSequenceOfPointConstraint.def(py::init<const GeomPlate_SequenceOfPointConstraint &>(), py::arg("theOther"));
	cls_GeomPlate_HSequenceOfPointConstraint.def("Sequence", (const GeomPlate_SequenceOfPointConstraint & (GeomPlate_HSequenceOfPointConstraint::*)() const ) &GeomPlate_HSequenceOfPointConstraint::Sequence, "None");
	cls_GeomPlate_HSequenceOfPointConstraint.def("Append", (void (GeomPlate_HSequenceOfPointConstraint::*)(const GeomPlate_SequenceOfPointConstraint::value_type &)) &GeomPlate_HSequenceOfPointConstraint::Append, "None", py::arg("theItem"));
	cls_GeomPlate_HSequenceOfPointConstraint.def("Append", (void (GeomPlate_HSequenceOfPointConstraint::*)(GeomPlate_SequenceOfPointConstraint &)) &GeomPlate_HSequenceOfPointConstraint::Append, "None", py::arg("theSequence"));
	cls_GeomPlate_HSequenceOfPointConstraint.def("ChangeSequence", (GeomPlate_SequenceOfPointConstraint & (GeomPlate_HSequenceOfPointConstraint::*)()) &GeomPlate_HSequenceOfPointConstraint::ChangeSequence, "None");
	cls_GeomPlate_HSequenceOfPointConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_HSequenceOfPointConstraint::get_type_name, "None");
	cls_GeomPlate_HSequenceOfPointConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_HSequenceOfPointConstraint::get_type_descriptor, "None");
	cls_GeomPlate_HSequenceOfPointConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_HSequenceOfPointConstraint::*)() const ) &GeomPlate_HSequenceOfPointConstraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomPlate_HArray1OfHCurve.hxx
	py::class_<GeomPlate_HArray1OfHCurve, opencascade::handle<GeomPlate_HArray1OfHCurve>, GeomPlate_Array1OfHCurve, Standard_Transient> cls_GeomPlate_HArray1OfHCurve(mod, "GeomPlate_HArray1OfHCurve", "None");
	cls_GeomPlate_HArray1OfHCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_GeomPlate_HArray1OfHCurve.def(py::init<const Standard_Integer, const Standard_Integer, const GeomPlate_Array1OfHCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_GeomPlate_HArray1OfHCurve.def(py::init<const GeomPlate_Array1OfHCurve &>(), py::arg("theOther"));
	cls_GeomPlate_HArray1OfHCurve.def("Array1", (const GeomPlate_Array1OfHCurve & (GeomPlate_HArray1OfHCurve::*)() const ) &GeomPlate_HArray1OfHCurve::Array1, "None");
	cls_GeomPlate_HArray1OfHCurve.def("ChangeArray1", (GeomPlate_Array1OfHCurve & (GeomPlate_HArray1OfHCurve::*)()) &GeomPlate_HArray1OfHCurve::ChangeArray1, "None");
	cls_GeomPlate_HArray1OfHCurve.def_static("get_type_name_", (const char * (*)()) &GeomPlate_HArray1OfHCurve::get_type_name, "None");
	cls_GeomPlate_HArray1OfHCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_HArray1OfHCurve::get_type_descriptor, "None");
	cls_GeomPlate_HArray1OfHCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_HArray1OfHCurve::*)() const ) &GeomPlate_HArray1OfHCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<GeomPlate_SequenceOfAij, std::unique_ptr<GeomPlate_SequenceOfAij, Deleter<GeomPlate_SequenceOfAij>>, NCollection_BaseSequence> cls_GeomPlate_SequenceOfAij(mod, "GeomPlate_SequenceOfAij", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_GeomPlate_SequenceOfAij.def(py::init<>());
	cls_GeomPlate_SequenceOfAij.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_GeomPlate_SequenceOfAij.def(py::init([] (const GeomPlate_SequenceOfAij &other) {return new GeomPlate_SequenceOfAij(other);}), "Copy constructor", py::arg("other"));
	cls_GeomPlate_SequenceOfAij.def("begin", (GeomPlate_SequenceOfAij::iterator (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_GeomPlate_SequenceOfAij.def("end", (GeomPlate_SequenceOfAij::iterator (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_GeomPlate_SequenceOfAij.def("cbegin", (GeomPlate_SequenceOfAij::const_iterator (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_GeomPlate_SequenceOfAij.def("cend", (GeomPlate_SequenceOfAij::const_iterator (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_GeomPlate_SequenceOfAij.def("Size", (Standard_Integer (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::Size, "Number of items");
	cls_GeomPlate_SequenceOfAij.def("Length", (Standard_Integer (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::Length, "Number of items");
	cls_GeomPlate_SequenceOfAij.def("Lower", (Standard_Integer (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::Lower, "Method for consistency with other collections.");
	cls_GeomPlate_SequenceOfAij.def("Upper", (Standard_Integer (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::Upper, "Method for consistency with other collections.");
	cls_GeomPlate_SequenceOfAij.def("IsEmpty", (Standard_Boolean (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::IsEmpty, "Empty query");
	cls_GeomPlate_SequenceOfAij.def("Reverse", (void (GeomPlate_SequenceOfAij::*)()) &GeomPlate_SequenceOfAij::Reverse, "Reverse sequence");
	cls_GeomPlate_SequenceOfAij.def("Exchange", (void (GeomPlate_SequenceOfAij::*)(const Standard_Integer, const Standard_Integer)) &GeomPlate_SequenceOfAij::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_GeomPlate_SequenceOfAij.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_SequenceOfAij::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_GeomPlate_SequenceOfAij.def("Clear", [](GeomPlate_SequenceOfAij &self) -> void { return self.Clear(); });
	cls_GeomPlate_SequenceOfAij.def("Clear", (void (GeomPlate_SequenceOfAij::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_SequenceOfAij::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_GeomPlate_SequenceOfAij.def("Assign", (GeomPlate_SequenceOfAij & (GeomPlate_SequenceOfAij::*)(const GeomPlate_SequenceOfAij &)) &GeomPlate_SequenceOfAij::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_GeomPlate_SequenceOfAij.def("assign", (GeomPlate_SequenceOfAij & (GeomPlate_SequenceOfAij::*)(const GeomPlate_SequenceOfAij &)) &GeomPlate_SequenceOfAij::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_GeomPlate_SequenceOfAij.def("Remove", (void (GeomPlate_SequenceOfAij::*)(GeomPlate_SequenceOfAij::Iterator &)) &GeomPlate_SequenceOfAij::Remove, "Remove one item", py::arg("thePosition"));
	cls_GeomPlate_SequenceOfAij.def("Remove", (void (GeomPlate_SequenceOfAij::*)(const Standard_Integer)) &GeomPlate_SequenceOfAij::Remove, "Remove one item", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfAij.def("Remove", (void (GeomPlate_SequenceOfAij::*)(const Standard_Integer, const Standard_Integer)) &GeomPlate_SequenceOfAij::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_GeomPlate_SequenceOfAij.def("Append", (void (GeomPlate_SequenceOfAij::*)(const GeomPlate_Aij &)) &GeomPlate_SequenceOfAij::Append, "Append one item", py::arg("theItem"));
	cls_GeomPlate_SequenceOfAij.def("Append", (void (GeomPlate_SequenceOfAij::*)(GeomPlate_SequenceOfAij &)) &GeomPlate_SequenceOfAij::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_GeomPlate_SequenceOfAij.def("Prepend", (void (GeomPlate_SequenceOfAij::*)(const GeomPlate_Aij &)) &GeomPlate_SequenceOfAij::Prepend, "Prepend one item", py::arg("theItem"));
	cls_GeomPlate_SequenceOfAij.def("Prepend", (void (GeomPlate_SequenceOfAij::*)(GeomPlate_SequenceOfAij &)) &GeomPlate_SequenceOfAij::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_GeomPlate_SequenceOfAij.def("InsertBefore", (void (GeomPlate_SequenceOfAij::*)(const Standard_Integer, const GeomPlate_Aij &)) &GeomPlate_SequenceOfAij::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfAij.def("InsertBefore", (void (GeomPlate_SequenceOfAij::*)(const Standard_Integer, GeomPlate_SequenceOfAij &)) &GeomPlate_SequenceOfAij::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_GeomPlate_SequenceOfAij.def("InsertAfter", (void (GeomPlate_SequenceOfAij::*)(GeomPlate_SequenceOfAij::Iterator &, const GeomPlate_Aij &)) &GeomPlate_SequenceOfAij::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfAij.def("InsertAfter", (void (GeomPlate_SequenceOfAij::*)(const Standard_Integer, GeomPlate_SequenceOfAij &)) &GeomPlate_SequenceOfAij::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_GeomPlate_SequenceOfAij.def("InsertAfter", (void (GeomPlate_SequenceOfAij::*)(const Standard_Integer, const GeomPlate_Aij &)) &GeomPlate_SequenceOfAij::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfAij.def("Split", (void (GeomPlate_SequenceOfAij::*)(const Standard_Integer, GeomPlate_SequenceOfAij &)) &GeomPlate_SequenceOfAij::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_GeomPlate_SequenceOfAij.def("First", (const GeomPlate_Aij & (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::First, "First item access");
	cls_GeomPlate_SequenceOfAij.def("ChangeFirst", (GeomPlate_Aij & (GeomPlate_SequenceOfAij::*)()) &GeomPlate_SequenceOfAij::ChangeFirst, "First item access");
	cls_GeomPlate_SequenceOfAij.def("Last", (const GeomPlate_Aij & (GeomPlate_SequenceOfAij::*)() const ) &GeomPlate_SequenceOfAij::Last, "Last item access");
	cls_GeomPlate_SequenceOfAij.def("ChangeLast", (GeomPlate_Aij & (GeomPlate_SequenceOfAij::*)()) &GeomPlate_SequenceOfAij::ChangeLast, "Last item access");
	cls_GeomPlate_SequenceOfAij.def("Value", (const GeomPlate_Aij & (GeomPlate_SequenceOfAij::*)(const Standard_Integer) const ) &GeomPlate_SequenceOfAij::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfAij.def("__call__", (const GeomPlate_Aij & (GeomPlate_SequenceOfAij::*)(const Standard_Integer) const ) &GeomPlate_SequenceOfAij::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfAij.def("ChangeValue", (GeomPlate_Aij & (GeomPlate_SequenceOfAij::*)(const Standard_Integer)) &GeomPlate_SequenceOfAij::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfAij.def("__call__", (GeomPlate_Aij & (GeomPlate_SequenceOfAij::*)(const Standard_Integer)) &GeomPlate_SequenceOfAij::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_GeomPlate_SequenceOfAij.def("SetValue", (void (GeomPlate_SequenceOfAij::*)(const Standard_Integer, const GeomPlate_Aij &)) &GeomPlate_SequenceOfAij::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_GeomPlate_SequenceOfAij.def("__iter__", [](const GeomPlate_SequenceOfAij &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
