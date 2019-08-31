/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
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
#include <GeomPlate_CurveConstraint.hxx>
#include <Standard_Type.hxx>
#include <Adaptor3d_HCurveOnSurface.hxx>
#include <NCollection_Sequence.hxx>
#include <GeomPlate_SequenceOfCurveConstraint.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <GeomPlate_HSequenceOfCurveConstraint.hxx>
#include <NCollection_Array1.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <GeomPlate_Array1OfSequenceOfReal.hxx>
#include <GeomPlate_HArray1OfSequenceOfReal.hxx>
#include <Geom_Surface.hxx>
#include <gp_Pnt2d.hxx>
#include <GeomPlate_PointConstraint.hxx>
#include <GeomPlate_SequenceOfPointConstraint.hxx>
#include <GeomPlate_HSequenceOfPointConstraint.hxx>
#include <GeomPlate_Array1OfHCurve.hxx>
#include <GeomPlate_HArray1OfHCurve.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <TColgp_SequenceOfXYZ.hxx>
#include <GeomPlate_Surface.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Plate_Plate.hxx>
#include <Extrema_ExtPS.hxx>
#include <GeomPlate_BuildPlateSurface.hxx>
#include <GeomPlate_BuildAveragePlane.hxx>
#include <GeomPlate_Aij.hxx>
#include <GeomPlate_SequenceOfAij.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_SequenceOfVec.hxx>
#include <Geom_Plane.hxx>
#include <Geom_Line.hxx>
#include <AdvApp2Var_Criterion.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_BSplineSurface.hxx>
#include <GeomPlate_MakeApprox.hxx>
#include <AdvApp2Var_CriterionType.hxx>
#include <AdvApp2Var_CriterionRepartition.hxx>
#include <AdvApp2Var_Patch.hxx>
#include <AdvApp2Var_Context.hxx>
#include <GeomPlate_PlateG0Criterion.hxx>
#include <GeomPlate_PlateG1Criterion.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf2d.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Geometry.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Array1.hxx>

PYBIND11_MODULE(GeomPlate, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Law");
py::module::import("OCCT.GeomLProp");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColGeom2d");
py::module::import("OCCT.Plate");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.AdvApp2Var");
py::module::import("OCCT.GeomAbs");

// CLASS: GEOMPLATE_CURVECONSTRAINT
py::class_<GeomPlate_CurveConstraint, opencascade::handle<GeomPlate_CurveConstraint>, Standard_Transient> cls_GeomPlate_CurveConstraint(mod, "GeomPlate_CurveConstraint", "Defines curves as constraints to be used to deform a surface.");

// Constructors
cls_GeomPlate_CurveConstraint.def(py::init<>());
cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer>(), py::arg("Boundary"), py::arg("Order"));
cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"));
cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"));
cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"), py::arg("TolAng"));
cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"), py::arg("TolAng"), py::arg("TolCurv"));

// Methods
cls_GeomPlate_CurveConstraint.def("SetOrder", (void (GeomPlate_CurveConstraint::*)(const Standard_Integer)) &GeomPlate_CurveConstraint::SetOrder, "Allows you to set the order of continuity required for the constraints: G0, G1, and G2, controlled respectively by G0Criterion G1Criterion and G2Criterion.", py::arg("Order"));
cls_GeomPlate_CurveConstraint.def("Order", (Standard_Integer (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::Order, "Returns the order of constraint, one of G0, G1 or G2.");
cls_GeomPlate_CurveConstraint.def("NbPoints", (Standard_Integer (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::NbPoints, "Returns the number of points on the curve used as a constraint. The default setting is 10. This parameter affects computation time, which increases by the cube of the number of points.");
cls_GeomPlate_CurveConstraint.def("SetNbPoints", (void (GeomPlate_CurveConstraint::*)(const Standard_Integer)) &GeomPlate_CurveConstraint::SetNbPoints, "Allows you to set the number of points on the curve constraint. The default setting is 10. This parameter affects computation time, which increases by the cube of the number of points.", py::arg("NewNb"));
cls_GeomPlate_CurveConstraint.def("SetG0Criterion", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Law_Function> &)) &GeomPlate_CurveConstraint::SetG0Criterion, "Allows you to set the G0 criterion. This is the law defining the greatest distance allowed between the constraint and the target surface for each point of the constraint. If this criterion is not set, TolDist, the distance tolerance from the constructor, is used.", py::arg("G0Crit"));
cls_GeomPlate_CurveConstraint.def("SetG1Criterion", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Law_Function> &)) &GeomPlate_CurveConstraint::SetG1Criterion, "Allows you to set the G1 criterion. This is the law defining the greatest angle allowed between the constraint and the target surface. If this criterion is not set, TolAng, the angular tolerance from the constructor, is used. Raises ConstructionError if the curve is not on a surface", py::arg("G1Crit"));
cls_GeomPlate_CurveConstraint.def("SetG2Criterion", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Law_Function> &)) &GeomPlate_CurveConstraint::SetG2Criterion, "None", py::arg("G2Crit"));
cls_GeomPlate_CurveConstraint.def("G0Criterion", (Standard_Real (GeomPlate_CurveConstraint::*)(const Standard_Real) const) &GeomPlate_CurveConstraint::G0Criterion, "Returns the G0 criterion at the parametric point U on the curve. This is the greatest distance allowed between the constraint and the target surface at U.", py::arg("U"));
cls_GeomPlate_CurveConstraint.def("G1Criterion", (Standard_Real (GeomPlate_CurveConstraint::*)(const Standard_Real) const) &GeomPlate_CurveConstraint::G1Criterion, "Returns the G1 criterion at the parametric point U on the curve. This is the greatest angle allowed between the constraint and the target surface at U. Raises ConstructionError if the curve is not on a surface", py::arg("U"));
cls_GeomPlate_CurveConstraint.def("G2Criterion", (Standard_Real (GeomPlate_CurveConstraint::*)(const Standard_Real) const) &GeomPlate_CurveConstraint::G2Criterion, "Returns the G2 criterion at the parametric point U on the curve. This is the greatest difference in curvature allowed between the constraint and the target surface at U. Raises ConstructionError if the curve is not on a surface", py::arg("U"));
cls_GeomPlate_CurveConstraint.def("FirstParameter", (Standard_Real (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::FirstParameter, "None");
cls_GeomPlate_CurveConstraint.def("LastParameter", (Standard_Real (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::LastParameter, "None");
cls_GeomPlate_CurveConstraint.def("Length", (Standard_Real (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::Length, "None");
cls_GeomPlate_CurveConstraint.def("LPropSurf", (GeomLProp_SLProps & (GeomPlate_CurveConstraint::*)(const Standard_Real)) &GeomPlate_CurveConstraint::LPropSurf, "None", py::arg("U"));
cls_GeomPlate_CurveConstraint.def("D0", (void (GeomPlate_CurveConstraint::*)(const Standard_Real, gp_Pnt &) const) &GeomPlate_CurveConstraint::D0, "None", py::arg("U"), py::arg("P"));
cls_GeomPlate_CurveConstraint.def("D1", (void (GeomPlate_CurveConstraint::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomPlate_CurveConstraint::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_GeomPlate_CurveConstraint.def("D2", (void (GeomPlate_CurveConstraint::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomPlate_CurveConstraint::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("V5"));
cls_GeomPlate_CurveConstraint.def("Curve3d", (opencascade::handle<Adaptor3d_HCurve> (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::Curve3d, "None");
cls_GeomPlate_CurveConstraint.def("SetCurve2dOnSurf", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Geom2d_Curve> &)) &GeomPlate_CurveConstraint::SetCurve2dOnSurf, "loads a 2d curve associated the surface resulting of the constraints", py::arg("Curve2d"));
cls_GeomPlate_CurveConstraint.def("Curve2dOnSurf", (opencascade::handle<Geom2d_Curve> (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::Curve2dOnSurf, "Returns a 2d curve associated the surface resulting of the constraints");
cls_GeomPlate_CurveConstraint.def("SetProjectedCurve", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Real)) &GeomPlate_CurveConstraint::SetProjectedCurve, "loads a 2d curve resulting from the normal projection of the curve on the initial surface", py::arg("Curve2d"), py::arg("TolU"), py::arg("TolV"));
cls_GeomPlate_CurveConstraint.def("ProjectedCurve", (opencascade::handle<Adaptor2d_HCurve2d> (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::ProjectedCurve, "Returns the projected curve resulting from the normal projection of the curve on the initial surface");
cls_GeomPlate_CurveConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_CurveConstraint::get_type_name, "None");
cls_GeomPlate_CurveConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_CurveConstraint::get_type_descriptor, "None");
cls_GeomPlate_CurveConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::DynamicType, "None");

// TYPEDEF: GEOMPLATE_SEQUENCEOFCURVECONSTRAINT
bind_NCollection_Sequence<opencascade::handle<GeomPlate_CurveConstraint> >(mod, "GeomPlate_SequenceOfCurveConstraint", py::module_local(false));

// CLASS: GEOMPLATE_HSEQUENCEOFCURVECONSTRAINT
py::class_<GeomPlate_HSequenceOfCurveConstraint, opencascade::handle<GeomPlate_HSequenceOfCurveConstraint>, Standard_Transient> cls_GeomPlate_HSequenceOfCurveConstraint(mod, "GeomPlate_HSequenceOfCurveConstraint", "None", py::multiple_inheritance());

// Constructors
cls_GeomPlate_HSequenceOfCurveConstraint.def(py::init<>());
cls_GeomPlate_HSequenceOfCurveConstraint.def(py::init<const GeomPlate_SequenceOfCurveConstraint &>(), py::arg("theOther"));

// Methods
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_HSequenceOfCurveConstraint::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator delete_", (void (*)(void *)) &GeomPlate_HSequenceOfCurveConstraint::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_HSequenceOfCurveConstraint::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_HSequenceOfCurveConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_HSequenceOfCurveConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_HSequenceOfCurveConstraint::operator delete, "None", py::arg(""), py::arg(""));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HSequenceOfCurveConstraint::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HSequenceOfCurveConstraint::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_GeomPlate_HSequenceOfCurveConstraint.def("Sequence", (const GeomPlate_SequenceOfCurveConstraint & (GeomPlate_HSequenceOfCurveConstraint::*)() const) &GeomPlate_HSequenceOfCurveConstraint::Sequence, "None");
cls_GeomPlate_HSequenceOfCurveConstraint.def("Append", (void (GeomPlate_HSequenceOfCurveConstraint::*)(const GeomPlate_SequenceOfCurveConstraint::value_type &)) &GeomPlate_HSequenceOfCurveConstraint::Append, "None", py::arg("theItem"));
cls_GeomPlate_HSequenceOfCurveConstraint.def("Append", (void (GeomPlate_HSequenceOfCurveConstraint::*)(GeomPlate_SequenceOfCurveConstraint &)) &GeomPlate_HSequenceOfCurveConstraint::Append, "None", py::arg("theSequence"));
cls_GeomPlate_HSequenceOfCurveConstraint.def("ChangeSequence", (GeomPlate_SequenceOfCurveConstraint & (GeomPlate_HSequenceOfCurveConstraint::*)()) &GeomPlate_HSequenceOfCurveConstraint::ChangeSequence, "None");
cls_GeomPlate_HSequenceOfCurveConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_HSequenceOfCurveConstraint::get_type_name, "None");
cls_GeomPlate_HSequenceOfCurveConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_HSequenceOfCurveConstraint::get_type_descriptor, "None");
cls_GeomPlate_HSequenceOfCurveConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_HSequenceOfCurveConstraint::*)() const) &GeomPlate_HSequenceOfCurveConstraint::DynamicType, "None");

// TYPEDEF: GEOMPLATE_ARRAY1OFSEQUENCEOFREAL
bind_NCollection_Array1<NCollection_Sequence<double> >(mod, "GeomPlate_Array1OfSequenceOfReal", py::module_local(false));

// CLASS: GEOMPLATE_HARRAY1OFSEQUENCEOFREAL
py::class_<GeomPlate_HArray1OfSequenceOfReal, opencascade::handle<GeomPlate_HArray1OfSequenceOfReal>, Standard_Transient> cls_GeomPlate_HArray1OfSequenceOfReal(mod, "GeomPlate_HArray1OfSequenceOfReal", "None", py::multiple_inheritance());

// Constructors
cls_GeomPlate_HArray1OfSequenceOfReal.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_GeomPlate_HArray1OfSequenceOfReal.def(py::init<const Standard_Integer, const Standard_Integer, const GeomPlate_Array1OfSequenceOfReal::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_GeomPlate_HArray1OfSequenceOfReal.def(py::init<const GeomPlate_Array1OfSequenceOfReal &>(), py::arg("theOther"));

// Methods
// cls_GeomPlate_HArray1OfSequenceOfReal.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_HArray1OfSequenceOfReal::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_HArray1OfSequenceOfReal.def_static("operator delete_", (void (*)(void *)) &GeomPlate_HArray1OfSequenceOfReal::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_HArray1OfSequenceOfReal.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_HArray1OfSequenceOfReal::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_HArray1OfSequenceOfReal.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_HArray1OfSequenceOfReal::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_HArray1OfSequenceOfReal.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_HArray1OfSequenceOfReal::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_HArray1OfSequenceOfReal.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_HArray1OfSequenceOfReal::operator delete, "None", py::arg(""), py::arg(""));
// cls_GeomPlate_HArray1OfSequenceOfReal.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HArray1OfSequenceOfReal::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_GeomPlate_HArray1OfSequenceOfReal.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HArray1OfSequenceOfReal::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_GeomPlate_HArray1OfSequenceOfReal.def("Array1", (const GeomPlate_Array1OfSequenceOfReal & (GeomPlate_HArray1OfSequenceOfReal::*)() const) &GeomPlate_HArray1OfSequenceOfReal::Array1, "None");
cls_GeomPlate_HArray1OfSequenceOfReal.def("ChangeArray1", (GeomPlate_Array1OfSequenceOfReal & (GeomPlate_HArray1OfSequenceOfReal::*)()) &GeomPlate_HArray1OfSequenceOfReal::ChangeArray1, "None");
cls_GeomPlate_HArray1OfSequenceOfReal.def_static("get_type_name_", (const char * (*)()) &GeomPlate_HArray1OfSequenceOfReal::get_type_name, "None");
cls_GeomPlate_HArray1OfSequenceOfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_HArray1OfSequenceOfReal::get_type_descriptor, "None");
cls_GeomPlate_HArray1OfSequenceOfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_HArray1OfSequenceOfReal::*)() const) &GeomPlate_HArray1OfSequenceOfReal::DynamicType, "None");

// CLASS: GEOMPLATE_POINTCONSTRAINT
py::class_<GeomPlate_PointConstraint, opencascade::handle<GeomPlate_PointConstraint>, Standard_Transient> cls_GeomPlate_PointConstraint(mod, "GeomPlate_PointConstraint", "Defines points as constraints to be used to deform a surface.");

// Constructors
cls_GeomPlate_PointConstraint.def(py::init<const gp_Pnt &, const Standard_Integer>(), py::arg("Pt"), py::arg("Order"));
cls_GeomPlate_PointConstraint.def(py::init<const gp_Pnt &, const Standard_Integer, const Standard_Real>(), py::arg("Pt"), py::arg("Order"), py::arg("TolDist"));
cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"));
cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"), py::arg("TolDist"));
cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"), py::arg("TolDist"), py::arg("TolAng"));
cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"), py::arg("TolDist"), py::arg("TolAng"), py::arg("TolCurv"));

// Methods
cls_GeomPlate_PointConstraint.def("SetOrder", (void (GeomPlate_PointConstraint::*)(const Standard_Integer)) &GeomPlate_PointConstraint::SetOrder, "None", py::arg("Order"));
cls_GeomPlate_PointConstraint.def("Order", (Standard_Integer (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::Order, "Returns the order of constraint: G0, G1, and G2, controlled respectively by G0Criterion G1Criterion and G2Criterion.");
cls_GeomPlate_PointConstraint.def("SetG0Criterion", (void (GeomPlate_PointConstraint::*)(const Standard_Real)) &GeomPlate_PointConstraint::SetG0Criterion, "Allows you to set the G0 criterion. This is the law defining the greatest distance allowed between the constraint and the target surface. If this criterion is not set, {TolDist, the distance tolerance from the constructor, is used", py::arg("TolDist"));
cls_GeomPlate_PointConstraint.def("SetG1Criterion", (void (GeomPlate_PointConstraint::*)(const Standard_Real)) &GeomPlate_PointConstraint::SetG1Criterion, "Allows you to set the G1 criterion. This is the law defining the greatest angle allowed between the constraint and the target surface. If this criterion is not set, TolAng, the angular tolerance from the constructor, is used. Raises ConstructionError if the point is not on the surface", py::arg("TolAng"));
cls_GeomPlate_PointConstraint.def("SetG2Criterion", (void (GeomPlate_PointConstraint::*)(const Standard_Real)) &GeomPlate_PointConstraint::SetG2Criterion, "Allows you to set the G2 criterion. This is the law defining the greatest difference in curvature allowed between the constraint and the target surface. If this criterion is not set, TolCurv, the curvature tolerance from the constructor, is used. Raises ConstructionError if the point is not on the surface", py::arg("TolCurv"));
cls_GeomPlate_PointConstraint.def("G0Criterion", (Standard_Real (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::G0Criterion, "Returns the G0 criterion. This is the greatest distance allowed between the constraint and the target surface.");
cls_GeomPlate_PointConstraint.def("G1Criterion", (Standard_Real (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::G1Criterion, "Returns the G1 criterion. This is the greatest angle allowed between the constraint and the target surface. Raises ConstructionError if the point is not on the surface.");
cls_GeomPlate_PointConstraint.def("G2Criterion", (Standard_Real (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::G2Criterion, "Returns the G2 criterion. This is the greatest difference in curvature allowed between the constraint and the target surface. Raises ConstructionError if the point is not on the surface");
cls_GeomPlate_PointConstraint.def("D0", (void (GeomPlate_PointConstraint::*)(gp_Pnt &) const) &GeomPlate_PointConstraint::D0, "None", py::arg("P"));
cls_GeomPlate_PointConstraint.def("D1", (void (GeomPlate_PointConstraint::*)(gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomPlate_PointConstraint::D1, "None", py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_GeomPlate_PointConstraint.def("D2", (void (GeomPlate_PointConstraint::*)(gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomPlate_PointConstraint::D2, "None", py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("V5"));
cls_GeomPlate_PointConstraint.def("HasPnt2dOnSurf", (Standard_Boolean (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::HasPnt2dOnSurf, "None");
cls_GeomPlate_PointConstraint.def("SetPnt2dOnSurf", (void (GeomPlate_PointConstraint::*)(const gp_Pnt2d &)) &GeomPlate_PointConstraint::SetPnt2dOnSurf, "None", py::arg("Pnt"));
cls_GeomPlate_PointConstraint.def("Pnt2dOnSurf", (gp_Pnt2d (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::Pnt2dOnSurf, "None");
cls_GeomPlate_PointConstraint.def("LPropSurf", (GeomLProp_SLProps & (GeomPlate_PointConstraint::*)()) &GeomPlate_PointConstraint::LPropSurf, "None");
cls_GeomPlate_PointConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_PointConstraint::get_type_name, "None");
cls_GeomPlate_PointConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_PointConstraint::get_type_descriptor, "None");
cls_GeomPlate_PointConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::DynamicType, "None");

// TYPEDEF: GEOMPLATE_SEQUENCEOFPOINTCONSTRAINT
bind_NCollection_Sequence<opencascade::handle<GeomPlate_PointConstraint> >(mod, "GeomPlate_SequenceOfPointConstraint", py::module_local(false));

// CLASS: GEOMPLATE_HSEQUENCEOFPOINTCONSTRAINT
py::class_<GeomPlate_HSequenceOfPointConstraint, opencascade::handle<GeomPlate_HSequenceOfPointConstraint>, Standard_Transient> cls_GeomPlate_HSequenceOfPointConstraint(mod, "GeomPlate_HSequenceOfPointConstraint", "None", py::multiple_inheritance());

// Constructors
cls_GeomPlate_HSequenceOfPointConstraint.def(py::init<>());
cls_GeomPlate_HSequenceOfPointConstraint.def(py::init<const GeomPlate_SequenceOfPointConstraint &>(), py::arg("theOther"));

// Methods
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_HSequenceOfPointConstraint::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator delete_", (void (*)(void *)) &GeomPlate_HSequenceOfPointConstraint::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_HSequenceOfPointConstraint::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_HSequenceOfPointConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_HSequenceOfPointConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_HSequenceOfPointConstraint::operator delete, "None", py::arg(""), py::arg(""));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HSequenceOfPointConstraint::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HSequenceOfPointConstraint::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_GeomPlate_HSequenceOfPointConstraint.def("Sequence", (const GeomPlate_SequenceOfPointConstraint & (GeomPlate_HSequenceOfPointConstraint::*)() const) &GeomPlate_HSequenceOfPointConstraint::Sequence, "None");
cls_GeomPlate_HSequenceOfPointConstraint.def("Append", (void (GeomPlate_HSequenceOfPointConstraint::*)(const GeomPlate_SequenceOfPointConstraint::value_type &)) &GeomPlate_HSequenceOfPointConstraint::Append, "None", py::arg("theItem"));
cls_GeomPlate_HSequenceOfPointConstraint.def("Append", (void (GeomPlate_HSequenceOfPointConstraint::*)(GeomPlate_SequenceOfPointConstraint &)) &GeomPlate_HSequenceOfPointConstraint::Append, "None", py::arg("theSequence"));
cls_GeomPlate_HSequenceOfPointConstraint.def("ChangeSequence", (GeomPlate_SequenceOfPointConstraint & (GeomPlate_HSequenceOfPointConstraint::*)()) &GeomPlate_HSequenceOfPointConstraint::ChangeSequence, "None");
cls_GeomPlate_HSequenceOfPointConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_HSequenceOfPointConstraint::get_type_name, "None");
cls_GeomPlate_HSequenceOfPointConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_HSequenceOfPointConstraint::get_type_descriptor, "None");
cls_GeomPlate_HSequenceOfPointConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_HSequenceOfPointConstraint::*)() const) &GeomPlate_HSequenceOfPointConstraint::DynamicType, "None");

// TYPEDEF: GEOMPLATE_ARRAY1OFHCURVE
bind_NCollection_Array1<opencascade::handle<Adaptor3d_HCurve> >(mod, "GeomPlate_Array1OfHCurve", py::module_local(false));

// CLASS: GEOMPLATE_HARRAY1OFHCURVE
py::class_<GeomPlate_HArray1OfHCurve, opencascade::handle<GeomPlate_HArray1OfHCurve>, Standard_Transient> cls_GeomPlate_HArray1OfHCurve(mod, "GeomPlate_HArray1OfHCurve", "None", py::multiple_inheritance());

// Constructors
cls_GeomPlate_HArray1OfHCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_GeomPlate_HArray1OfHCurve.def(py::init<const Standard_Integer, const Standard_Integer, const GeomPlate_Array1OfHCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_GeomPlate_HArray1OfHCurve.def(py::init<const GeomPlate_Array1OfHCurve &>(), py::arg("theOther"));

// Methods
// cls_GeomPlate_HArray1OfHCurve.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_HArray1OfHCurve::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_HArray1OfHCurve.def_static("operator delete_", (void (*)(void *)) &GeomPlate_HArray1OfHCurve::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_HArray1OfHCurve.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_HArray1OfHCurve::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_HArray1OfHCurve.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_HArray1OfHCurve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_HArray1OfHCurve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_HArray1OfHCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_HArray1OfHCurve.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_HArray1OfHCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_GeomPlate_HArray1OfHCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HArray1OfHCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_GeomPlate_HArray1OfHCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HArray1OfHCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_GeomPlate_HArray1OfHCurve.def("Array1", (const GeomPlate_Array1OfHCurve & (GeomPlate_HArray1OfHCurve::*)() const) &GeomPlate_HArray1OfHCurve::Array1, "None");
cls_GeomPlate_HArray1OfHCurve.def("ChangeArray1", (GeomPlate_Array1OfHCurve & (GeomPlate_HArray1OfHCurve::*)()) &GeomPlate_HArray1OfHCurve::ChangeArray1, "None");
cls_GeomPlate_HArray1OfHCurve.def_static("get_type_name_", (const char * (*)()) &GeomPlate_HArray1OfHCurve::get_type_name, "None");
cls_GeomPlate_HArray1OfHCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_HArray1OfHCurve::get_type_descriptor, "None");
cls_GeomPlate_HArray1OfHCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_HArray1OfHCurve::*)() const) &GeomPlate_HArray1OfHCurve::DynamicType, "None");

// CLASS: GEOMPLATE_BUILDPLATESURFACE
py::class_<GeomPlate_BuildPlateSurface> cls_GeomPlate_BuildPlateSurface(mod, "GeomPlate_BuildPlateSurface", "This class provides an algorithm for constructing such a plate surface that it conforms to given curve and/or point constraints. The algorithm accepts or constructs an initial surface and looks for a deformation of it satisfying the constraints and minimizing energy input. A BuildPlateSurface object provides a framework for: - defining or setting constraints - implementing the construction algorithm - consulting the result.");

// Constructors
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

// Methods
// cls_GeomPlate_BuildPlateSurface.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_BuildPlateSurface::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_BuildPlateSurface.def_static("operator delete_", (void (*)(void *)) &GeomPlate_BuildPlateSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_BuildPlateSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_BuildPlateSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_BuildPlateSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_BuildPlateSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_BuildPlateSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_BuildPlateSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_BuildPlateSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_BuildPlateSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomPlate_BuildPlateSurface.def("Init", (void (GeomPlate_BuildPlateSurface::*)()) &GeomPlate_BuildPlateSurface::Init, "Resets all constraints");
cls_GeomPlate_BuildPlateSurface.def("LoadInitSurface", (void (GeomPlate_BuildPlateSurface::*)(const opencascade::handle<Geom_Surface> &)) &GeomPlate_BuildPlateSurface::LoadInitSurface, "Loads the initial Surface", py::arg("Surf"));
cls_GeomPlate_BuildPlateSurface.def("Add", (void (GeomPlate_BuildPlateSurface::*)(const opencascade::handle<GeomPlate_CurveConstraint> &)) &GeomPlate_BuildPlateSurface::Add, "Adds the linear constraint cont.", py::arg("Cont"));
cls_GeomPlate_BuildPlateSurface.def("SetNbBounds", (void (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::SetNbBounds, "None", py::arg("NbBounds"));
cls_GeomPlate_BuildPlateSurface.def("Add", (void (GeomPlate_BuildPlateSurface::*)(const opencascade::handle<GeomPlate_PointConstraint> &)) &GeomPlate_BuildPlateSurface::Add, "Adds the point constraint cont.", py::arg("Cont"));
cls_GeomPlate_BuildPlateSurface.def("Perform", (void (GeomPlate_BuildPlateSurface::*)()) &GeomPlate_BuildPlateSurface::Perform, "Calls the algorithm and computes the plate surface using the loaded constraints. If no initial surface is given, the algorithm automatically computes one. Exceptions Standard_RangeError if the value of the constraint is null or if plate is not done.");
cls_GeomPlate_BuildPlateSurface.def("CurveConstraint", (opencascade::handle<GeomPlate_CurveConstraint> (GeomPlate_BuildPlateSurface::*)(const Standard_Integer) const) &GeomPlate_BuildPlateSurface::CurveConstraint, "returns the CurveConstraints of order order", py::arg("order"));
cls_GeomPlate_BuildPlateSurface.def("PointConstraint", (opencascade::handle<GeomPlate_PointConstraint> (GeomPlate_BuildPlateSurface::*)(const Standard_Integer) const) &GeomPlate_BuildPlateSurface::PointConstraint, "returns the PointConstraint of order order", py::arg("order"));
cls_GeomPlate_BuildPlateSurface.def("Disc2dContour", (void (GeomPlate_BuildPlateSurface::*)(const Standard_Integer, TColgp_SequenceOfXY &)) &GeomPlate_BuildPlateSurface::Disc2dContour, "None", py::arg("nbp"), py::arg("Seq2d"));
cls_GeomPlate_BuildPlateSurface.def("Disc3dContour", (void (GeomPlate_BuildPlateSurface::*)(const Standard_Integer, const Standard_Integer, TColgp_SequenceOfXYZ &)) &GeomPlate_BuildPlateSurface::Disc3dContour, "None", py::arg("nbp"), py::arg("iordre"), py::arg("Seq3d"));
cls_GeomPlate_BuildPlateSurface.def("IsDone", (Standard_Boolean (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::IsDone, "Tests whether computation of the plate has been completed.");
cls_GeomPlate_BuildPlateSurface.def("Surface", (opencascade::handle<GeomPlate_Surface> (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::Surface, "Returns the result of the computation. This surface can then be used by GeomPlate_MakeApprox for converting the resulting surface into a BSpline.");
cls_GeomPlate_BuildPlateSurface.def("SurfInit", (opencascade::handle<Geom_Surface> (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::SurfInit, "Returns the initial surface");
cls_GeomPlate_BuildPlateSurface.def("Sense", (opencascade::handle<TColStd_HArray1OfInteger> (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::Sense, "Allows you to ensure that the array of curves returned by Curves2d has the correct orientation. Returns the orientation of the curves in the the array returned by Curves2d. Computation changes the orientation of these curves. Consequently, this method returns the orientation prior to computation.");
cls_GeomPlate_BuildPlateSurface.def("Curves2d", (opencascade::handle<TColGeom2d_HArray1OfCurve> (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::Curves2d, "Extracts the array of curves on the plate surface which correspond to the curve constraints set in Add.");
cls_GeomPlate_BuildPlateSurface.def("Order", (opencascade::handle<TColStd_HArray1OfInteger> (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::Order, "Returns the order of the curves in the array returned by Curves2d. Computation changes this order. Consequently, this method returns the order of the curves prior to computation.");
cls_GeomPlate_BuildPlateSurface.def("G0Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::G0Error, "Returns the max distance betwen the result and the constraints");
cls_GeomPlate_BuildPlateSurface.def("G1Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::G1Error, "Returns the max angle betwen the result and the constraints");
cls_GeomPlate_BuildPlateSurface.def("G2Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::G2Error, "Returns the max difference of curvature betwen the result and the constraints");
cls_GeomPlate_BuildPlateSurface.def("G0Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::G0Error, "Returns the max distance between the result and the constraint Index", py::arg("Index"));
cls_GeomPlate_BuildPlateSurface.def("G1Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::G1Error, "Returns the max angle between the result and the constraint Index", py::arg("Index"));
cls_GeomPlate_BuildPlateSurface.def("G2Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::G2Error, "Returns the max difference of curvature between the result and the constraint Index", py::arg("Index"));

// CLASS: GEOMPLATE_AIJ
py::class_<GeomPlate_Aij> cls_GeomPlate_Aij(mod, "GeomPlate_Aij", "A structure containing indexes of two normals and its cross product");

// Constructors
cls_GeomPlate_Aij.def(py::init<>());
cls_GeomPlate_Aij.def(py::init<const Standard_Integer, const Standard_Integer, const gp_Vec &>(), py::arg("anInd1"), py::arg("anInd2"), py::arg("aVec"));

// Methods
// cls_GeomPlate_Aij.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_Aij::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_Aij.def_static("operator delete_", (void (*)(void *)) &GeomPlate_Aij::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_Aij.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_Aij::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_Aij.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_Aij::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_Aij.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_Aij::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_Aij.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_Aij::operator delete, "None", py::arg(""), py::arg(""));

// TYPEDEF: GEOMPLATE_SEQUENCEOFAIJ
bind_NCollection_Sequence<GeomPlate_Aij>(mod, "GeomPlate_SequenceOfAij", py::module_local(false));

// CLASS: GEOMPLATE_BUILDAVERAGEPLANE
py::class_<GeomPlate_BuildAveragePlane> cls_GeomPlate_BuildAveragePlane(mod, "GeomPlate_BuildAveragePlane", "This class computes an average inertial plane with an array of points. Computes the initial surface (average plane) in the cases when the initial surface is not given.");

// Constructors
cls_GeomPlate_BuildAveragePlane.def(py::init<const opencascade::handle<TColgp_HArray1OfPnt> &, const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("Pts"), py::arg("NbBoundPoints"), py::arg("Tol"), py::arg("POption"), py::arg("NOption"));
cls_GeomPlate_BuildAveragePlane.def(py::init<const TColgp_SequenceOfVec &, const opencascade::handle<TColgp_HArray1OfPnt> &>(), py::arg("Normals"), py::arg("Pts"));

// Methods
// cls_GeomPlate_BuildAveragePlane.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_BuildAveragePlane::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_BuildAveragePlane.def_static("operator delete_", (void (*)(void *)) &GeomPlate_BuildAveragePlane::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_BuildAveragePlane.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_BuildAveragePlane::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_BuildAveragePlane.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_BuildAveragePlane::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_BuildAveragePlane.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_BuildAveragePlane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_BuildAveragePlane.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_BuildAveragePlane::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomPlate_BuildAveragePlane.def("Plane", (opencascade::handle<Geom_Plane> (GeomPlate_BuildAveragePlane::*)() const) &GeomPlate_BuildAveragePlane::Plane, "Return the average Plane.");
cls_GeomPlate_BuildAveragePlane.def("Line", (opencascade::handle<Geom_Line> (GeomPlate_BuildAveragePlane::*)() const) &GeomPlate_BuildAveragePlane::Line, "Return a Line when 2 eigenvalues are null.");
cls_GeomPlate_BuildAveragePlane.def("IsPlane", (Standard_Boolean (GeomPlate_BuildAveragePlane::*)() const) &GeomPlate_BuildAveragePlane::IsPlane, "return OK if is a plane.");
cls_GeomPlate_BuildAveragePlane.def("IsLine", (Standard_Boolean (GeomPlate_BuildAveragePlane::*)() const) &GeomPlate_BuildAveragePlane::IsLine, "return OK if is a line.");
cls_GeomPlate_BuildAveragePlane.def("MinMaxBox", [](GeomPlate_BuildAveragePlane &self, Standard_Real & Umin, Standard_Real & Umax, Standard_Real & Vmin, Standard_Real & Vmax){ self.MinMaxBox(Umin, Umax, Vmin, Vmax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(Umin, Umax, Vmin, Vmax); }, "computes the minimal box to include all normal projection points of the initial array on the plane.", py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
cls_GeomPlate_BuildAveragePlane.def_static("HalfSpace_", (Standard_Boolean (*)(const TColgp_SequenceOfVec &, TColgp_SequenceOfVec &, GeomPlate_SequenceOfAij &, const Standard_Real, const Standard_Real)) &GeomPlate_BuildAveragePlane::HalfSpace, "None", py::arg("NewNormals"), py::arg("Normals"), py::arg("Bset"), py::arg("LinTol"), py::arg("AngTol"));

// CLASS: GEOMPLATE_MAKEAPPROX
py::class_<GeomPlate_MakeApprox> cls_GeomPlate_MakeApprox(mod, "GeomPlate_MakeApprox", "Allows you to convert a GeomPlate surface into a BSpline.");

// Constructors
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const AdvApp2Var_Criterion &, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("SurfPlate"), py::arg("PlateCrit"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const AdvApp2Var_Criterion &, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("SurfPlate"), py::arg("PlateCrit"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("Continuity"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const AdvApp2Var_Criterion &, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("SurfPlate"), py::arg("PlateCrit"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("Continuity"), py::arg("EnlargeCoeff"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"), py::arg("CritOrder"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer, const GeomAbs_Shape>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"), py::arg("CritOrder"), py::arg("Continuity"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"), py::arg("CritOrder"), py::arg("Continuity"), py::arg("EnlargeCoeff"));

// Methods
// cls_GeomPlate_MakeApprox.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_MakeApprox::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_MakeApprox.def_static("operator delete_", (void (*)(void *)) &GeomPlate_MakeApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_MakeApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_MakeApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_MakeApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_MakeApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_MakeApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_MakeApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_MakeApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_MakeApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomPlate_MakeApprox.def("Surface", (opencascade::handle<Geom_BSplineSurface> (GeomPlate_MakeApprox::*)() const) &GeomPlate_MakeApprox::Surface, "Returns the BSpline surface extracted from the GeomPlate_MakeApprox object.");
cls_GeomPlate_MakeApprox.def("ApproxError", (Standard_Real (GeomPlate_MakeApprox::*)() const) &GeomPlate_MakeApprox::ApproxError, "Returns the error in computation of the approximation surface. This is the distance between the entire target BSpline surface and the entire original surface generated by BuildPlateSurface and converted by GeomPlate_Surface.");
cls_GeomPlate_MakeApprox.def("CriterionError", (Standard_Real (GeomPlate_MakeApprox::*)() const) &GeomPlate_MakeApprox::CriterionError, "Returns the criterion error in computation of the approximation surface. This is estimated relative to the curve and point constraints only.");

// CLASS: GEOMPLATE_PLATEG0CRITERION
py::class_<GeomPlate_PlateG0Criterion, AdvApp2Var_Criterion> cls_GeomPlate_PlateG0Criterion(mod, "GeomPlate_PlateG0Criterion", "this class contains a specific G0 criterion for GeomPlate_MakeApprox");

// Constructors
cls_GeomPlate_PlateG0Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real>(), py::arg("Data"), py::arg("G0Data"), py::arg("Maximum"));
cls_GeomPlate_PlateG0Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real, const AdvApp2Var_CriterionType>(), py::arg("Data"), py::arg("G0Data"), py::arg("Maximum"), py::arg("Type"));
cls_GeomPlate_PlateG0Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real, const AdvApp2Var_CriterionType, const AdvApp2Var_CriterionRepartition>(), py::arg("Data"), py::arg("G0Data"), py::arg("Maximum"), py::arg("Type"), py::arg("Repart"));

// Methods
// cls_GeomPlate_PlateG0Criterion.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_PlateG0Criterion::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_PlateG0Criterion.def_static("operator delete_", (void (*)(void *)) &GeomPlate_PlateG0Criterion::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_PlateG0Criterion.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_PlateG0Criterion::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_PlateG0Criterion.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_PlateG0Criterion::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_PlateG0Criterion.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_PlateG0Criterion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_PlateG0Criterion.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_PlateG0Criterion::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomPlate_PlateG0Criterion.def("Value", (void (GeomPlate_PlateG0Criterion::*)(AdvApp2Var_Patch &, const AdvApp2Var_Context &) const) &GeomPlate_PlateG0Criterion::Value, "None", py::arg("P"), py::arg("C"));
cls_GeomPlate_PlateG0Criterion.def("IsSatisfied", (Standard_Boolean (GeomPlate_PlateG0Criterion::*)(const AdvApp2Var_Patch &) const) &GeomPlate_PlateG0Criterion::IsSatisfied, "None", py::arg("P"));

// CLASS: GEOMPLATE_PLATEG1CRITERION
py::class_<GeomPlate_PlateG1Criterion, AdvApp2Var_Criterion> cls_GeomPlate_PlateG1Criterion(mod, "GeomPlate_PlateG1Criterion", "this class contains a specific G1 criterion for GeomPlate_MakeApprox");

// Constructors
cls_GeomPlate_PlateG1Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real>(), py::arg("Data"), py::arg("G1Data"), py::arg("Maximum"));
cls_GeomPlate_PlateG1Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real, const AdvApp2Var_CriterionType>(), py::arg("Data"), py::arg("G1Data"), py::arg("Maximum"), py::arg("Type"));
cls_GeomPlate_PlateG1Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real, const AdvApp2Var_CriterionType, const AdvApp2Var_CriterionRepartition>(), py::arg("Data"), py::arg("G1Data"), py::arg("Maximum"), py::arg("Type"), py::arg("Repart"));

// Methods
// cls_GeomPlate_PlateG1Criterion.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_PlateG1Criterion::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_PlateG1Criterion.def_static("operator delete_", (void (*)(void *)) &GeomPlate_PlateG1Criterion::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_PlateG1Criterion.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_PlateG1Criterion::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_PlateG1Criterion.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_PlateG1Criterion::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_PlateG1Criterion.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_PlateG1Criterion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_PlateG1Criterion.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_PlateG1Criterion::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomPlate_PlateG1Criterion.def("Value", (void (GeomPlate_PlateG1Criterion::*)(AdvApp2Var_Patch &, const AdvApp2Var_Context &) const) &GeomPlate_PlateG1Criterion::Value, "None", py::arg("P"), py::arg("C"));
cls_GeomPlate_PlateG1Criterion.def("IsSatisfied", (Standard_Boolean (GeomPlate_PlateG1Criterion::*)(const AdvApp2Var_Patch &) const) &GeomPlate_PlateG1Criterion::IsSatisfied, "None", py::arg("P"));

// CLASS: GEOMPLATE_SURFACE
py::class_<GeomPlate_Surface, opencascade::handle<GeomPlate_Surface>, Geom_Surface> cls_GeomPlate_Surface(mod, "GeomPlate_Surface", "Describes the characteristics of plate surface objects returned by BuildPlateSurface::Surface. These can be used to verify the quality of the resulting surface before approximating it to a Geom_BSpline surface generated by MakeApprox. This proves necessary in cases where you want to use the resulting surface as the support for a shape. The algorithmically generated surface cannot fill this function as is, and as a result must be converted first.");

// Constructors
cls_GeomPlate_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Plate_Plate &>(), py::arg("Surfinit"), py::arg("Surfinter"));

// Methods
cls_GeomPlate_Surface.def("UReverse", (void (GeomPlate_Surface::*)()) &GeomPlate_Surface::UReverse, "Reverses the U direction of parametrization of <me>. The bounds of the surface are not modified.");
cls_GeomPlate_Surface.def("UReversedParameter", (Standard_Real (GeomPlate_Surface::*)(const Standard_Real) const) &GeomPlate_Surface::UReversedParameter, "Return the parameter on the Ureversed surface for the point of parameter U on <me>.", py::arg("U"));
cls_GeomPlate_Surface.def("VReverse", (void (GeomPlate_Surface::*)()) &GeomPlate_Surface::VReverse, "Reverses the V direction of parametrization of <me>. The bounds of the surface are not modified.");
cls_GeomPlate_Surface.def("VReversedParameter", (Standard_Real (GeomPlate_Surface::*)(const Standard_Real) const) &GeomPlate_Surface::VReversedParameter, "Return the parameter on the Vreversed surface for the point of parameter V on <me>.", py::arg("V"));
cls_GeomPlate_Surface.def("TransformParameters", [](GeomPlate_Surface &self, Standard_Real & U, Standard_Real & V, const gp_Trsf & T){ self.TransformParameters(U, V, T); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Computes the parameters on the transformed surface for the transform of the point of parameters U,V on <me>.", py::arg("U"), py::arg("V"), py::arg("T"));
cls_GeomPlate_Surface.def("ParametricTransformation", (gp_GTrsf2d (GeomPlate_Surface::*)(const gp_Trsf &) const) &GeomPlate_Surface::ParametricTransformation, "Returns a 2d transformation used to find the new parameters of a point on the transformed surface.", py::arg("T"));
cls_GeomPlate_Surface.def("Bounds", [](GeomPlate_Surface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "None", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_GeomPlate_Surface.def("IsUClosed", (Standard_Boolean (GeomPlate_Surface::*)() const) &GeomPlate_Surface::IsUClosed, "Is the surface closed in the parametric direction U ? Returns True if for each parameter V the distance between the point P (UFirst, V) and P (ULast, V) is lower or equal to Resolution from gp. UFirst and ULast are the parametric bounds in the U direction.");
cls_GeomPlate_Surface.def("IsVClosed", (Standard_Boolean (GeomPlate_Surface::*)() const) &GeomPlate_Surface::IsVClosed, "Is the surface closed in the parametric direction V ? Returns True if for each parameter U the distance between the point P (U, VFirst) and P (U, VLast) is lower or equal to Resolution from gp. VFirst and VLast are the parametric bounds in the V direction.");
cls_GeomPlate_Surface.def("IsUPeriodic", (Standard_Boolean (GeomPlate_Surface::*)() const) &GeomPlate_Surface::IsUPeriodic, "Is the parametrization of a surface periodic in the direction U ? It is possible only if the surface is closed in this parametric direction and if the following relation is satisfied : for each parameter V the distance between the point P (U, V) and the point P (U + T, V) is lower or equal to Resolution from package gp. T is the parametric period and must be a constant.");
cls_GeomPlate_Surface.def("UPeriod", (Standard_Real (GeomPlate_Surface::*)() const) &GeomPlate_Surface::UPeriod, "returns the Uperiod. raises if the surface is not uperiodic.");
cls_GeomPlate_Surface.def("IsVPeriodic", (Standard_Boolean (GeomPlate_Surface::*)() const) &GeomPlate_Surface::IsVPeriodic, "Is the parametrization of a surface periodic in the direction U ? It is possible only if the surface is closed in this parametric direction and if the following relation is satisfied : for each parameter V the distance between the point P (U, V) and the point P (U + T, V) is lower or equal to Resolution from package gp. T is the parametric period and must be a constant.");
cls_GeomPlate_Surface.def("VPeriod", (Standard_Real (GeomPlate_Surface::*)() const) &GeomPlate_Surface::VPeriod, "returns the Vperiod. raises if the surface is not vperiodic.");
cls_GeomPlate_Surface.def("UIso", (opencascade::handle<Geom_Curve> (GeomPlate_Surface::*)(const Standard_Real) const) &GeomPlate_Surface::UIso, "Computes the U isoparametric curve.", py::arg("U"));
cls_GeomPlate_Surface.def("VIso", (opencascade::handle<Geom_Curve> (GeomPlate_Surface::*)(const Standard_Real) const) &GeomPlate_Surface::VIso, "Computes the V isoparametric curve.", py::arg("V"));
cls_GeomPlate_Surface.def("Continuity", (GeomAbs_Shape (GeomPlate_Surface::*)() const) &GeomPlate_Surface::Continuity, "Global Continuity of the surface in direction U and V : C0 : only geometric continuity, C1 : continuity of the first derivative all along the surface, C2 : continuity of the second derivative all along the surface, C3 : continuity of the third derivative all along the surface, G1 : tangency continuity all along the surface, G2 : curvature continuity all along the surface, CN : the order of continuity is infinite. Example : If the surface is C1 in the V parametric direction and C2 in the U parametric direction Shape = C1.");
cls_GeomPlate_Surface.def("IsCNu", (Standard_Boolean (GeomPlate_Surface::*)(const Standard_Integer) const) &GeomPlate_Surface::IsCNu, "Returns the order of continuity of the surface in the U parametric direction. Raised if N < 0.", py::arg("N"));
cls_GeomPlate_Surface.def("IsCNv", (Standard_Boolean (GeomPlate_Surface::*)(const Standard_Integer) const) &GeomPlate_Surface::IsCNv, "Returns the order of continuity of the surface in the V parametric direction. Raised if N < 0.", py::arg("N"));
cls_GeomPlate_Surface.def("D0", (void (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &GeomPlate_Surface::D0, "Computes the point of parameter U,V on the surface.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_GeomPlate_Surface.def("D1", (void (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomPlate_Surface::D1, "Computes the point P and the first derivatives in the directions U and V at this point. Raised if the continuity of the surface is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_GeomPlate_Surface.def("D2", (void (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomPlate_Surface::D2, "Computes the point P, the first and the second derivatives in the directions U and V at this point. Raised if the continuity of the surface is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_GeomPlate_Surface.def("D3", (void (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomPlate_Surface::D3, "Computes the point P, the first,the second and the third derivatives in the directions U and V at this point. Raised if the continuity of the surface is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_GeomPlate_Surface.def("DN", (gp_Vec (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &GeomPlate_Surface::DN, "---Purpose ; Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V).", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_GeomPlate_Surface.def("Copy", (opencascade::handle<Geom_Geometry> (GeomPlate_Surface::*)() const) &GeomPlate_Surface::Copy, "None");
cls_GeomPlate_Surface.def("Transform", (void (GeomPlate_Surface::*)(const gp_Trsf &)) &GeomPlate_Surface::Transform, "Transformation of a geometric object. This tansformation can be a translation, a rotation, a symmetry, a scaling or a complex transformation obtained by combination of the previous elementaries transformations. (see class Transformation of the package Geom).", py::arg("T"));
cls_GeomPlate_Surface.def("CallSurfinit", (opencascade::handle<Geom_Surface> (GeomPlate_Surface::*)() const) &GeomPlate_Surface::CallSurfinit, "None");
cls_GeomPlate_Surface.def("SetBounds", (void (GeomPlate_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomPlate_Surface::SetBounds, "None", py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
cls_GeomPlate_Surface.def("RealBounds", [](GeomPlate_Surface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.RealBounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "None", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_GeomPlate_Surface.def("Constraints", (void (GeomPlate_Surface::*)(TColgp_SequenceOfXY &) const) &GeomPlate_Surface::Constraints, "None", py::arg("Seq"));
cls_GeomPlate_Surface.def_static("get_type_name_", (const char * (*)()) &GeomPlate_Surface::get_type_name, "None");
cls_GeomPlate_Surface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_Surface::get_type_descriptor, "None");
cls_GeomPlate_Surface.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_Surface::*)() const) &GeomPlate_Surface::DynamicType, "None");


}
