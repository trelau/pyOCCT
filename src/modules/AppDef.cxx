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
#include <AppParCurves_MultiPoint.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <AppDef_MultiPointConstraint.hxx>
#include <NCollection_Array1.hxx>
#include <AppDef_Array1OfMultiPointConstraint.hxx>
#include <math_BFGS.hxx>
#include <math_MultipleVarFunctionWithGradient.hxx>
#include <math_Vector.hxx>
#include <AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.hxx>
#include <AppDef_MultiLine.hxx>
#include <Approx_ParametrizationType.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <AppParCurves_Constraint.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <AppDef_BSplineCompute.hxx>
#include <Standard_Transient.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Std.hxx>
#include <AppDef_HArray1OfMultiPointConstraint.hxx>
#include <Standard_Type.hxx>
#include <math_Matrix.hxx>
#include <math_IntegerVector.hxx>
#include <AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.hxx>
#include <AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.hxx>
#include <AppParCurves_SequenceOfMultiCurve.hxx>
#include <Approx_SequenceOfHArray1OfReal.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <AppDef_Compute.hxx>
#include <AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute.hxx>
#include <AppDef_Gradient_BFGSOfMyGradientOfCompute.hxx>
#include <AppDef_Gradient_BFGSOfTheGradient.hxx>
#include <FEmTool_Curve.hxx>
#include <FEmTool_HAssemblyTable.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <AppDef_SmoothCriterion.hxx>
#include <AppDef_LinearCriteria.hxx>
#include <FEmTool_ElementaryCriterion.hxx>
#include <AppDef_MyBSplGradientOfBSplineCompute.hxx>
#include <AppDef_MyGradientbisOfBSplineCompute.hxx>
#include <AppDef_MyGradientOfCompute.hxx>
#include <Approx_Status.hxx>
#include <AppDef_MyLineTool.hxx>
#include <AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.hxx>
#include <AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.hxx>
#include <AppDef_ParLeastSquareOfMyGradientOfCompute.hxx>
#include <AppDef_ParFunctionOfMyGradientOfCompute.hxx>
#include <AppDef_ParLeastSquareOfTheGradient.hxx>
#include <AppDef_ParFunctionOfTheGradient.hxx>
#include <AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.hxx>
#include <AppDef_ResConstraintOfMyGradientOfCompute.hxx>
#include <AppDef_ResConstraintOfTheGradient.hxx>
#include <AppDef_TheLeastSquares.hxx>
#include <AppDef_TheFunction.hxx>
#include <AppDef_TheGradient.hxx>
#include <AppDef_TheResol.hxx>
#include <GeomAbs_Shape.hxx>
#include <FEmTool_Assembly.hxx>
#include <PLib_Base.hxx>
#include <AppDef_Variational.hxx>
#include <bind_NCollection_Array1.hxx>

PYBIND11_MODULE(AppDef, mod) {

py::module::import("OCCT.AppParCurves");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.math");
py::module::import("OCCT.Approx");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.FEmTool");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.PLib");

// CLASS: APPDEF_MULTIPOINTCONSTRAINT
py::class_<AppDef_MultiPointConstraint, AppParCurves_MultiPoint> cls_AppDef_MultiPointConstraint(mod, "AppDef_MultiPointConstraint", "Describes a MultiPointConstraint used in a Multiline. MultiPointConstraints are composed of several two or three-dimensional points. The purpose is to define the corresponding points that share a common constraint in order to compute the approximation of several lines in parallel. Notes: - The order of points of a MultiPointConstraints is very important. Users must give 3D points first, and then 2D points. - The constraints for the points included in a MultiPointConstraint are always identical for all points, including the parameter. - If a MultiPointConstraint is a 'tangency' point, the point is also a 'passing' point.");

// Constructors
cls_AppDef_MultiPointConstraint.def(py::init<>());
cls_AppDef_MultiPointConstraint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("NbPoints"), py::arg("NbPoints2d"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("tabP"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("tabP"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &>(), py::arg("tabP"), py::arg("tabP2d"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &, const TColgp_Array1OfVec &, const TColgp_Array1OfVec2d &, const TColgp_Array1OfVec &, const TColgp_Array1OfVec2d &>(), py::arg("tabP"), py::arg("tabP2d"), py::arg("tabVec"), py::arg("tabVec2d"), py::arg("tabCur"), py::arg("tabCur2d"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &, const TColgp_Array1OfVec &, const TColgp_Array1OfVec2d &>(), py::arg("tabP"), py::arg("tabP2d"), py::arg("tabVec"), py::arg("tabVec2d"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfVec &, const TColgp_Array1OfVec &>(), py::arg("tabP"), py::arg("tabVec"), py::arg("tabCur"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfVec &>(), py::arg("tabP"), py::arg("tabVec"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt2d &, const TColgp_Array1OfVec2d &>(), py::arg("tabP2d"), py::arg("tabVec2d"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt2d &, const TColgp_Array1OfVec2d &, const TColgp_Array1OfVec2d &>(), py::arg("tabP2d"), py::arg("tabVec2d"), py::arg("tabCur2d"));

// Methods
// cls_AppDef_MultiPointConstraint.def_static("operator new_", (void * (*)(size_t)) &AppDef_MultiPointConstraint::operator new, "None", py::arg("theSize"));
// cls_AppDef_MultiPointConstraint.def_static("operator delete_", (void (*)(void *)) &AppDef_MultiPointConstraint::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_MultiPointConstraint.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_MultiPointConstraint::operator new[], "None", py::arg("theSize"));
// cls_AppDef_MultiPointConstraint.def_static("operator delete[]_", (void (*)(void *)) &AppDef_MultiPointConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_MultiPointConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_MultiPointConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_MultiPointConstraint.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_MultiPointConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_MultiPointConstraint.def("SetTang", (void (AppDef_MultiPointConstraint::*)(const Standard_Integer, const gp_Vec &)) &AppDef_MultiPointConstraint::SetTang, "sets the value of the tangency of the point of range Index. An exception is raised if Index <0 or if Index > number of 3d points. An exception is raised if Tang has an incorrect number of dimensions.", py::arg("Index"), py::arg("Tang"));
cls_AppDef_MultiPointConstraint.def("Tang", (gp_Vec (AppDef_MultiPointConstraint::*)(const Standard_Integer) const) &AppDef_MultiPointConstraint::Tang, "returns the tangency value of the point of range Index. An exception is raised if Index < 0 or if Index > number of 3d points.", py::arg("Index"));
cls_AppDef_MultiPointConstraint.def("SetTang2d", (void (AppDef_MultiPointConstraint::*)(const Standard_Integer, const gp_Vec2d &)) &AppDef_MultiPointConstraint::SetTang2d, "sets the value of the tangency of the point of range Index. An exception is raised if Index <number of 3d points or if Index > total number of Points An exception is raised if Tang has an incorrect number of dimensions.", py::arg("Index"), py::arg("Tang2d"));
cls_AppDef_MultiPointConstraint.def("Tang2d", (gp_Vec2d (AppDef_MultiPointConstraint::*)(const Standard_Integer) const) &AppDef_MultiPointConstraint::Tang2d, "returns the tangency value of the point of range Index. An exception is raised if Index < number of 3d points or if Index > total number of points.", py::arg("Index"));
cls_AppDef_MultiPointConstraint.def("SetCurv", (void (AppDef_MultiPointConstraint::*)(const Standard_Integer, const gp_Vec &)) &AppDef_MultiPointConstraint::SetCurv, "Vec sets the value of the normal vector at the point of index Index. The norm of the normal vector at the point of position Index is set to the normal curvature. An exception is raised if Index <0 or if Index > number of 3d points. An exception is raised if Curv has an incorrect number of dimensions.", py::arg("Index"), py::arg("Curv"));
cls_AppDef_MultiPointConstraint.def("Curv", (gp_Vec (AppDef_MultiPointConstraint::*)(const Standard_Integer) const) &AppDef_MultiPointConstraint::Curv, "returns the normal vector at the point of range Index. An exception is raised if Index < 0 or if Index > number of 3d points.", py::arg("Index"));
cls_AppDef_MultiPointConstraint.def("SetCurv2d", (void (AppDef_MultiPointConstraint::*)(const Standard_Integer, const gp_Vec2d &)) &AppDef_MultiPointConstraint::SetCurv2d, "Vec sets the value of the normal vector at the point of index Index. The norm of the normal vector at the point of position Index is set to the normal curvature. An exception is raised if Index <0 or if Index > number of 3d points. An exception is raised if Curv has an incorrect number of dimensions.", py::arg("Index"), py::arg("Curv2d"));
cls_AppDef_MultiPointConstraint.def("Curv2d", (gp_Vec2d (AppDef_MultiPointConstraint::*)(const Standard_Integer) const) &AppDef_MultiPointConstraint::Curv2d, "returns the normal vector at the point of range Index. An exception is raised if Index < 0 or if Index > number of 3d points.", py::arg("Index"));
cls_AppDef_MultiPointConstraint.def("IsTangencyPoint", (Standard_Boolean (AppDef_MultiPointConstraint::*)() const) &AppDef_MultiPointConstraint::IsTangencyPoint, "returns True if the MultiPoint has a tangency value.");
cls_AppDef_MultiPointConstraint.def("IsCurvaturePoint", (Standard_Boolean (AppDef_MultiPointConstraint::*)() const) &AppDef_MultiPointConstraint::IsCurvaturePoint, "returns True if the MultiPoint has a curvature value.");
cls_AppDef_MultiPointConstraint.def("Dump", (void (AppDef_MultiPointConstraint::*)(Standard_OStream &) const) &AppDef_MultiPointConstraint::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// TYPEDEF: APPDEF_ARRAY1OFMULTIPOINTCONSTRAINT
bind_NCollection_Array1<AppDef_MultiPointConstraint>(mod, "AppDef_Array1OfMultiPointConstraint", py::module_local(false));

// CLASS: APPDEF_BSPGRADIENT_BFGSOFMYBSPLGRADIENTOFBSPLINECOMPUTE
py::class_<AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute, math_BFGS> cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute(mod, "AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute", "None");

// Constructors
cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"));
cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"), py::arg("NbIterations"));

// Methods
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def("IsSolutionReached", (Standard_Boolean (AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::*)(math_MultipleVarFunctionWithGradient &) const) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::IsSolutionReached, "None", py::arg("F"));

// CLASS: APPDEF_BSPLINECOMPUTE
py::class_<AppDef_BSplineCompute> cls_AppDef_BSplineCompute(mod, "AppDef_BSplineCompute", "None");

// Constructors
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &>(), py::arg("Line"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &>(), py::arg("Line"), py::arg("Parameters"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &>(), py::arg("Parameters"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_AppDef_BSplineCompute.def(py::init<>());
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));

// Methods
// cls_AppDef_BSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_BSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_BSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_BSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_BSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_BSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_BSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_BSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_BSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_BSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_BSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_BSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_BSplineCompute.def("Interpol", (void (AppDef_BSplineCompute::*)(const AppDef_MultiLine &)) &AppDef_BSplineCompute::Interpol, "Constructs an interpolation of the MultiLine <Line> The result will be a C2 curve of degree 3.", py::arg("Line"));
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self) -> void { return self.Init(); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0) -> void { return self.Init(a0); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5, const Approx_ParametrizationType a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_AppDef_BSplineCompute.def("Init", (void (AppDef_BSplineCompute::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean)) &AppDef_BSplineCompute::Init, "Initializes the fields of the algorithm.", py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_AppDef_BSplineCompute.def("Perform", (void (AppDef_BSplineCompute::*)(const AppDef_MultiLine &)) &AppDef_BSplineCompute::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
cls_AppDef_BSplineCompute.def("SetParameters", (void (AppDef_BSplineCompute::*)(const math_Vector &)) &AppDef_BSplineCompute::SetParameters, "The approximation will begin with the set of parameters <ThePar>.", py::arg("ThePar"));
cls_AppDef_BSplineCompute.def("SetKnots", (void (AppDef_BSplineCompute::*)(const TColStd_Array1OfReal &)) &AppDef_BSplineCompute::SetKnots, "The approximation will be done with the set of knots <Knots>. The multiplicities will be set with the degree and the desired continuity.", py::arg("Knots"));
cls_AppDef_BSplineCompute.def("SetKnotsAndMultiplicities", (void (AppDef_BSplineCompute::*)(const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &)) &AppDef_BSplineCompute::SetKnotsAndMultiplicities, "The approximation will be done with the set of knots <Knots> and the multiplicities <Mults>.", py::arg("Knots"), py::arg("Mults"));
cls_AppDef_BSplineCompute.def("SetDegrees", (void (AppDef_BSplineCompute::*)(const Standard_Integer, const Standard_Integer)) &AppDef_BSplineCompute::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_BSplineCompute.def("SetTolerances", (void (AppDef_BSplineCompute::*)(const Standard_Real, const Standard_Real)) &AppDef_BSplineCompute::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_BSplineCompute.def("SetContinuity", (void (AppDef_BSplineCompute::*)(const Standard_Integer)) &AppDef_BSplineCompute::SetContinuity, "sets the continuity of the spline. if C = 2, the spline will be C2.", py::arg("C"));
cls_AppDef_BSplineCompute.def("SetConstraints", (void (AppDef_BSplineCompute::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &AppDef_BSplineCompute::SetConstraints, "changes the first and the last constraint points.", py::arg("firstC"), py::arg("lastC"));
cls_AppDef_BSplineCompute.def("SetPeriodic", (void (AppDef_BSplineCompute::*)(const Standard_Boolean)) &AppDef_BSplineCompute::SetPeriodic, "Sets periodic flag. If thePeriodic = Standard_True, algorith tries to build periodic multicurve using corresponding C1 boundary condition for first and last multipoints. Multiline must be closed.", py::arg("thePeriodic"));
cls_AppDef_BSplineCompute.def("IsAllApproximated", (Standard_Boolean (AppDef_BSplineCompute::*)() const) &AppDef_BSplineCompute::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
cls_AppDef_BSplineCompute.def("IsToleranceReached", (Standard_Boolean (AppDef_BSplineCompute::*)() const) &AppDef_BSplineCompute::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
cls_AppDef_BSplineCompute.def("Error", [](AppDef_BSplineCompute &self, Standard_Real & tol3d, Standard_Real & tol2d){ self.Error(tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "returns the tolerances 2d and 3d of the MultiBSpCurve.", py::arg("tol3d"), py::arg("tol2d"));
cls_AppDef_BSplineCompute.def("Value", (const AppParCurves_MultiBSpCurve & (AppDef_BSplineCompute::*)() const) &AppDef_BSplineCompute::Value, "returns the result of the approximation.");
cls_AppDef_BSplineCompute.def("ChangeValue", (AppParCurves_MultiBSpCurve & (AppDef_BSplineCompute::*)()) &AppDef_BSplineCompute::ChangeValue, "returns the result of the approximation.");
cls_AppDef_BSplineCompute.def("Parameters", (const TColStd_Array1OfReal & (AppDef_BSplineCompute::*)() const) &AppDef_BSplineCompute::Parameters, "returns the new parameters of the approximation corresponding to the points of the MultiBSpCurve.");

// CLASS: APPDEF_HARRAY1OFMULTIPOINTCONSTRAINT
py::class_<AppDef_HArray1OfMultiPointConstraint, opencascade::handle<AppDef_HArray1OfMultiPointConstraint>, Standard_Transient> cls_AppDef_HArray1OfMultiPointConstraint(mod, "AppDef_HArray1OfMultiPointConstraint", "None", py::multiple_inheritance());

// Constructors
cls_AppDef_HArray1OfMultiPointConstraint.def(py::init<>());
cls_AppDef_HArray1OfMultiPointConstraint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_AppDef_HArray1OfMultiPointConstraint.def(py::init<const Standard_Integer, const Standard_Integer, const AppDef_Array1OfMultiPointConstraint::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_AppDef_HArray1OfMultiPointConstraint.def(py::init<const AppDef_Array1OfMultiPointConstraint &>(), py::arg("theOther"));

// Methods
// cls_AppDef_HArray1OfMultiPointConstraint.def_static("operator new_", (void * (*)(size_t)) &AppDef_HArray1OfMultiPointConstraint::operator new, "None", py::arg("theSize"));
// cls_AppDef_HArray1OfMultiPointConstraint.def_static("operator delete_", (void (*)(void *)) &AppDef_HArray1OfMultiPointConstraint::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_HArray1OfMultiPointConstraint.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_HArray1OfMultiPointConstraint::operator new[], "None", py::arg("theSize"));
// cls_AppDef_HArray1OfMultiPointConstraint.def_static("operator delete[]_", (void (*)(void *)) &AppDef_HArray1OfMultiPointConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_HArray1OfMultiPointConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_HArray1OfMultiPointConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_HArray1OfMultiPointConstraint.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_HArray1OfMultiPointConstraint::operator delete, "None", py::arg(""), py::arg(""));
// cls_AppDef_HArray1OfMultiPointConstraint.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &AppDef_HArray1OfMultiPointConstraint::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_AppDef_HArray1OfMultiPointConstraint.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &AppDef_HArray1OfMultiPointConstraint::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_AppDef_HArray1OfMultiPointConstraint.def("Array1", (const AppDef_Array1OfMultiPointConstraint & (AppDef_HArray1OfMultiPointConstraint::*)() const) &AppDef_HArray1OfMultiPointConstraint::Array1, "None");
cls_AppDef_HArray1OfMultiPointConstraint.def("ChangeArray1", (AppDef_Array1OfMultiPointConstraint & (AppDef_HArray1OfMultiPointConstraint::*)()) &AppDef_HArray1OfMultiPointConstraint::ChangeArray1, "None");
cls_AppDef_HArray1OfMultiPointConstraint.def_static("get_type_name_", (const char * (*)()) &AppDef_HArray1OfMultiPointConstraint::get_type_name, "None");
cls_AppDef_HArray1OfMultiPointConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppDef_HArray1OfMultiPointConstraint::get_type_descriptor, "None");
cls_AppDef_HArray1OfMultiPointConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppDef_HArray1OfMultiPointConstraint::*)() const) &AppDef_HArray1OfMultiPointConstraint::DynamicType, "None");

// CLASS: APPDEF_MULTILINE
py::class_<AppDef_MultiLine> cls_AppDef_MultiLine(mod, "AppDef_MultiLine", "This class describes the organized set of points used in the approximations. A MultiLine is composed of n MultiPointConstraints. The approximation of the MultiLine will be done in the order of the given n MultiPointConstraints.");

// Constructors
cls_AppDef_MultiLine.def(py::init<>());
cls_AppDef_MultiLine.def(py::init<const Standard_Integer>(), py::arg("NbMult"));
cls_AppDef_MultiLine.def(py::init<const AppDef_Array1OfMultiPointConstraint &>(), py::arg("tabMultiP"));
cls_AppDef_MultiLine.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("tabP3d"));
cls_AppDef_MultiLine.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("tabP2d"));

// Methods
// cls_AppDef_MultiLine.def_static("operator new_", (void * (*)(size_t)) &AppDef_MultiLine::operator new, "None", py::arg("theSize"));
// cls_AppDef_MultiLine.def_static("operator delete_", (void (*)(void *)) &AppDef_MultiLine::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_MultiLine.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_MultiLine::operator new[], "None", py::arg("theSize"));
// cls_AppDef_MultiLine.def_static("operator delete[]_", (void (*)(void *)) &AppDef_MultiLine::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_MultiLine.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_MultiLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_MultiLine.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_MultiLine::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_MultiLine.def("NbMultiPoints", (Standard_Integer (AppDef_MultiLine::*)() const) &AppDef_MultiLine::NbMultiPoints, "returns the number of MultiPointConstraints of the MultiLine.");
cls_AppDef_MultiLine.def("NbPoints", (Standard_Integer (AppDef_MultiLine::*)() const) &AppDef_MultiLine::NbPoints, "returns the number of Points from MultiPoints composing the MultiLine.");
// cls_AppDef_MultiLine.def("SetParameter", (void (AppDef_MultiLine::*)(const Standard_Integer, const Standard_Real)) &AppDef_MultiLine::SetParameter, "Sets the value of the parameter for the MultiPointConstraint at position Index. Exceptions - Standard_OutOfRange if Index is less than 0 or Index is greater than the number of Multipoint constraints in the MultiLine.", py::arg("Index"), py::arg("U"));
cls_AppDef_MultiLine.def("SetValue", (void (AppDef_MultiLine::*)(const Standard_Integer, const AppDef_MultiPointConstraint &)) &AppDef_MultiLine::SetValue, "It sets the MultiPointConstraint of range Index to the value MPoint. An exception is raised if Index < 0 or Index> MPoint. An exception is raised if the dimensions of the MultiPoints are different.", py::arg("Index"), py::arg("MPoint"));
cls_AppDef_MultiLine.def("Value", (AppDef_MultiPointConstraint (AppDef_MultiLine::*)(const Standard_Integer) const) &AppDef_MultiLine::Value, "returns the MultiPointConstraint of range Index An exception is raised if Index<0 or Index>MPoint.", py::arg("Index"));
cls_AppDef_MultiLine.def("Dump", (void (AppDef_MultiLine::*)(Standard_OStream &) const) &AppDef_MultiLine::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// CLASS: APPDEF_BSPPARLEASTSQUAREOFMYBSPLGRADIENTOFBSPLINECOMPUTE
py::class_<AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute> cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute(mod, "AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute", "None");

// Constructors
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));

// Methods
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Perform", (void (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)(const math_Vector &)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Perform, "Is used after having initialized the fields. The case 'CurvaturePoint' is not treated in this method.", py::arg("Parameters"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Perform", (void (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)(const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Perform, "Is used after having initialized the fields.", py::arg("Parameters"), py::arg("l1"), py::arg("l2"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Perform", (void (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)(const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("l1"), py::arg("l2"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Perform", (void (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)(const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point. <V1c> is the tangent vector at the first point. <V2c> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("V1c"), py::arg("V2c"), py::arg("l1"), py::arg("l2"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("IsDone", (Standard_Boolean (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::IsDone, "returns True if all has been correctly done.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("BezierValue", (AppParCurves_MultiCurve (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)()) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::BezierValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("BSplineValue", (const AppParCurves_MultiBSpCurve & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)()) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::BSplineValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("FunctionMatrix", (const math_Matrix & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::FunctionMatrix, "returns the function matrix used to approximate the set.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("DerivativeFunctionMatrix", (const math_Matrix & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::DerivativeFunctionMatrix, "returns the derivative function matrix used to approximate the set.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("ErrorGradient", [](AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute &self, math_Vector & Grad, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.ErrorGradient(Grad, F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances. Grad is the derivative vector of the function F.", py::arg("Grad"), py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Distance", (const math_Matrix & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)()) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Distance, "returns the distances between the points of the multiline and the approximation curves.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Error", [](AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute &self, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.Error(F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances.", py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("FirstLambda", (Standard_Real (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::FirstLambda, "returns the value (P2 - P1)/ V1 if the first point was a tangency point.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("LastLambda", (Standard_Real (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::LastLambda, "returns the value (PN - PN-1)/ VN if the last point was a tangency point.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Points", (const math_Matrix & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Points, "returns the matrix of points value.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Poles", (const math_Matrix & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Poles, "returns the matrix of resulting control points value.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("KIndex", (const math_IntegerVector & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::KIndex, "Returns the indexes of the first non null values of A and DA. The values are non null from Index(ieme point) +1 to Index(ieme point) + degree +1.");

// CLASS: APPDEF_BSPPARFUNCTIONOFMYBSPLGRADIENTOFBSPLINECOMPUTE
py::class_<AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute, math_MultipleVarFunctionWithGradient> cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute(mod, "AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute", "None");

// Constructors
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Vector &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Knots"), py::arg("Mults"), py::arg("NbPol"));

// Methods
// cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("NbVariables", (Standard_Integer (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::NbVariables, "returns the number of variables of the function. It corresponds to the number of MultiPoints.");
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("Value", [](AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "this method computes the new approximation of the MultiLine SSP and calculates F = sum (||Pui - Bi*Pi||2) for each point of the MultiLine.", py::arg("X"), py::arg("F"));
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("Gradient", (Standard_Boolean (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)(const math_Vector &, math_Vector &)) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::Gradient, "returns the gradient G of the sum above for the parameters Xi.", py::arg("X"), py::arg("G"));
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("Values", [](AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "returns the value F=sum(||Pui - Bi*Pi||)2. returns the value G = grad(F) for the parameters Xi.", py::arg("X"), py::arg("F"), py::arg("G"));
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("NewParameters", (const math_Vector & (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::NewParameters, "returns the new parameters of the MultiLine.");
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("CurveValue", (AppParCurves_MultiBSpCurve (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)()) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::CurveValue, "returns the MultiBSpCurve approximating the set after computing the value F or Grad(F).");
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("Error", (Standard_Real (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)(const Standard_Integer, const Standard_Integer)) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::Error, "returns the distance between the MultiPoint of range IPoint and the curve CurveIndex.", py::arg("IPoint"), py::arg("CurveIndex"));
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("MaxError3d", (Standard_Real (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::MaxError3d, "returns the maximum distance between the points and the MultiBSpCurve.");
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("MaxError2d", (Standard_Real (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::MaxError2d, "returns the maximum distance between the points and the MultiBSpCurve.");
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("FunctionMatrix", (const math_Matrix & (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::FunctionMatrix, "returns the function matrix used to approximate the multiline.");
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("DerivativeFunctionMatrix", (const math_Matrix & (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::DerivativeFunctionMatrix, "returns the derivative function matrix used to approximate the multiline.");
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("Index", (const math_IntegerVector & (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::Index, "Returns the indexes of the first non null values of A and DA. The values are non null from Index(ieme point) +1 to Index(ieme point) + degree +1.");
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("FirstConstraint", (AppParCurves_Constraint (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::FirstConstraint, "None", py::arg("TheConstraints"), py::arg("FirstPoint"));
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("LastConstraint", (AppParCurves_Constraint (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::LastConstraint, "None", py::arg("TheConstraints"), py::arg("LastPoint"));
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("SetFirstLambda", (void (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)(const Standard_Real)) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::SetFirstLambda, "None", py::arg("l1"));
cls_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute.def("SetLastLambda", (void (AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::*)(const Standard_Real)) &AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute::SetLastLambda, "None", py::arg("l2"));

// CLASS: APPDEF_COMPUTE
py::class_<AppDef_Compute> cls_AppDef_Compute(mod, "AppDef_Compute", "None");

// Constructors
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &>(), py::arg("Line"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &>(), py::arg("Line"), py::arg("Parameters"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_AppDef_Compute.def(py::init<const math_Vector &>(), py::arg("Parameters"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_AppDef_Compute.def(py::init<>());
cls_AppDef_Compute.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));

// Methods
// cls_AppDef_Compute.def_static("operator new_", (void * (*)(size_t)) &AppDef_Compute::operator new, "None", py::arg("theSize"));
// cls_AppDef_Compute.def_static("operator delete_", (void (*)(void *)) &AppDef_Compute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_Compute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_Compute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_Compute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_Compute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_Compute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_Compute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_Compute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_Compute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self) -> void { return self.Init(); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0) -> void { return self.Init(a0); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5, const Approx_ParametrizationType a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_AppDef_Compute.def("Init", (void (AppDef_Compute::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean)) &AppDef_Compute::Init, "Initializes the fields of the algorithm.", py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_AppDef_Compute.def("Perform", (void (AppDef_Compute::*)(const AppDef_MultiLine &)) &AppDef_Compute::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
cls_AppDef_Compute.def("SetDegrees", (void (AppDef_Compute::*)(const Standard_Integer, const Standard_Integer)) &AppDef_Compute::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_Compute.def("SetTolerances", (void (AppDef_Compute::*)(const Standard_Real, const Standard_Real)) &AppDef_Compute::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_Compute.def("SetConstraints", (void (AppDef_Compute::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &AppDef_Compute::SetConstraints, "changes the first and the last constraint points.", py::arg("firstC"), py::arg("lastC"));
cls_AppDef_Compute.def("IsAllApproximated", (Standard_Boolean (AppDef_Compute::*)() const) &AppDef_Compute::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
cls_AppDef_Compute.def("IsToleranceReached", (Standard_Boolean (AppDef_Compute::*)() const) &AppDef_Compute::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
cls_AppDef_Compute.def("Error", [](AppDef_Compute &self, const Standard_Integer Index, Standard_Real & tol3d, Standard_Real & tol2d){ self.Error(Index, tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "returns the tolerances 2d and 3d of the <Index> MultiCurve.", py::arg("Index"), py::arg("tol3d"), py::arg("tol2d"));
cls_AppDef_Compute.def("NbMultiCurves", (Standard_Integer (AppDef_Compute::*)() const) &AppDef_Compute::NbMultiCurves, "Returns the number of MultiCurve doing the approximation of the MultiLine.");
cls_AppDef_Compute.def("Value", [](AppDef_Compute &self) -> const AppParCurves_MultiCurve & { return self.Value(); });
cls_AppDef_Compute.def("Value", (const AppParCurves_MultiCurve & (AppDef_Compute::*)(const Standard_Integer) const) &AppDef_Compute::Value, "returns the result of the approximation.", py::arg("Index"));
cls_AppDef_Compute.def("ChangeValue", [](AppDef_Compute &self) -> AppParCurves_MultiCurve & { return self.ChangeValue(); });
cls_AppDef_Compute.def("ChangeValue", (AppParCurves_MultiCurve & (AppDef_Compute::*)(const Standard_Integer)) &AppDef_Compute::ChangeValue, "returns the result of the approximation.", py::arg("Index"));
cls_AppDef_Compute.def("SplineValue", (const AppParCurves_MultiBSpCurve & (AppDef_Compute::*)()) &AppDef_Compute::SplineValue, "returns the result of the approximation.");
cls_AppDef_Compute.def("Parametrization", (Approx_ParametrizationType (AppDef_Compute::*)() const) &AppDef_Compute::Parametrization, "returns the type of parametrization");
cls_AppDef_Compute.def("Parameters", [](AppDef_Compute &self) -> const TColStd_Array1OfReal & { return self.Parameters(); });
cls_AppDef_Compute.def("Parameters", (const TColStd_Array1OfReal & (AppDef_Compute::*)(const Standard_Integer) const) &AppDef_Compute::Parameters, "returns the new parameters of the approximation corresponding to the points of the multicurve <Index>.", py::arg("Index"));

// CLASS: APPDEF_GRADIENT_BFGSOFMYGRADIENTBISOFBSPLINECOMPUTE
py::class_<AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute, math_BFGS> cls_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute(mod, "AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute", "None");

// Constructors
cls_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"));
cls_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"), py::arg("NbIterations"));

// Methods
// cls_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute.def("IsSolutionReached", (Standard_Boolean (AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute::*)(math_MultipleVarFunctionWithGradient &) const) &AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute::IsSolutionReached, "None", py::arg("F"));

// CLASS: APPDEF_GRADIENT_BFGSOFMYGRADIENTOFCOMPUTE
py::class_<AppDef_Gradient_BFGSOfMyGradientOfCompute, math_BFGS> cls_AppDef_Gradient_BFGSOfMyGradientOfCompute(mod, "AppDef_Gradient_BFGSOfMyGradientOfCompute", "None");

// Constructors
cls_AppDef_Gradient_BFGSOfMyGradientOfCompute.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"));
cls_AppDef_Gradient_BFGSOfMyGradientOfCompute.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"), py::arg("NbIterations"));

// Methods
// cls_AppDef_Gradient_BFGSOfMyGradientOfCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_Gradient_BFGSOfMyGradientOfCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_Gradient_BFGSOfMyGradientOfCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_Gradient_BFGSOfMyGradientOfCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_Gradient_BFGSOfMyGradientOfCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_Gradient_BFGSOfMyGradientOfCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_Gradient_BFGSOfMyGradientOfCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_Gradient_BFGSOfMyGradientOfCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_Gradient_BFGSOfMyGradientOfCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_Gradient_BFGSOfMyGradientOfCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_Gradient_BFGSOfMyGradientOfCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_Gradient_BFGSOfMyGradientOfCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_Gradient_BFGSOfMyGradientOfCompute.def("IsSolutionReached", (Standard_Boolean (AppDef_Gradient_BFGSOfMyGradientOfCompute::*)(math_MultipleVarFunctionWithGradient &) const) &AppDef_Gradient_BFGSOfMyGradientOfCompute::IsSolutionReached, "None", py::arg("F"));

// CLASS: APPDEF_GRADIENT_BFGSOFTHEGRADIENT
py::class_<AppDef_Gradient_BFGSOfTheGradient, math_BFGS> cls_AppDef_Gradient_BFGSOfTheGradient(mod, "AppDef_Gradient_BFGSOfTheGradient", "None");

// Constructors
cls_AppDef_Gradient_BFGSOfTheGradient.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"));
cls_AppDef_Gradient_BFGSOfTheGradient.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"), py::arg("NbIterations"));

// Methods
// cls_AppDef_Gradient_BFGSOfTheGradient.def_static("operator new_", (void * (*)(size_t)) &AppDef_Gradient_BFGSOfTheGradient::operator new, "None", py::arg("theSize"));
// cls_AppDef_Gradient_BFGSOfTheGradient.def_static("operator delete_", (void (*)(void *)) &AppDef_Gradient_BFGSOfTheGradient::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_Gradient_BFGSOfTheGradient.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_Gradient_BFGSOfTheGradient::operator new[], "None", py::arg("theSize"));
// cls_AppDef_Gradient_BFGSOfTheGradient.def_static("operator delete[]_", (void (*)(void *)) &AppDef_Gradient_BFGSOfTheGradient::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_Gradient_BFGSOfTheGradient.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_Gradient_BFGSOfTheGradient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_Gradient_BFGSOfTheGradient.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_Gradient_BFGSOfTheGradient::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_Gradient_BFGSOfTheGradient.def("IsSolutionReached", (Standard_Boolean (AppDef_Gradient_BFGSOfTheGradient::*)(math_MultipleVarFunctionWithGradient &) const) &AppDef_Gradient_BFGSOfTheGradient::IsSolutionReached, "None", py::arg("F"));

// CLASS: APPDEF_SMOOTHCRITERION
py::class_<AppDef_SmoothCriterion, opencascade::handle<AppDef_SmoothCriterion>, Standard_Transient> cls_AppDef_SmoothCriterion(mod, "AppDef_SmoothCriterion", "defined criterion to smooth points in curve");

// Methods
cls_AppDef_SmoothCriterion.def("SetParameters", (void (AppDef_SmoothCriterion::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &AppDef_SmoothCriterion::SetParameters, "None", py::arg("Parameters"));
cls_AppDef_SmoothCriterion.def("SetCurve", (void (AppDef_SmoothCriterion::*)(const opencascade::handle<FEmTool_Curve> &)) &AppDef_SmoothCriterion::SetCurve, "None", py::arg("C"));
cls_AppDef_SmoothCriterion.def("GetCurve", (void (AppDef_SmoothCriterion::*)(opencascade::handle<FEmTool_Curve> &) const) &AppDef_SmoothCriterion::GetCurve, "None", py::arg("C"));
cls_AppDef_SmoothCriterion.def("SetEstimation", (void (AppDef_SmoothCriterion::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &AppDef_SmoothCriterion::SetEstimation, "None", py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_AppDef_SmoothCriterion.def("EstLength", (Standard_Real & (AppDef_SmoothCriterion::*)()) &AppDef_SmoothCriterion::EstLength, "None");
cls_AppDef_SmoothCriterion.def("GetEstimation", [](AppDef_SmoothCriterion &self, Standard_Real & E1, Standard_Real & E2, Standard_Real & E3){ self.GetEstimation(E1, E2, E3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(E1, E2, E3); }, "None", py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_AppDef_SmoothCriterion.def("AssemblyTable", (opencascade::handle<FEmTool_HAssemblyTable> (AppDef_SmoothCriterion::*)() const) &AppDef_SmoothCriterion::AssemblyTable, "None");
cls_AppDef_SmoothCriterion.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (AppDef_SmoothCriterion::*)() const) &AppDef_SmoothCriterion::DependenceTable, "None");
cls_AppDef_SmoothCriterion.def("QualityValues", [](AppDef_SmoothCriterion &self, const Standard_Real J1min, const Standard_Real J2min, const Standard_Real J3min, Standard_Real & J1, Standard_Real & J2, Standard_Real & J3){ Standard_Integer rv = self.QualityValues(J1min, J2min, J3min, J1, J2, J3); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &>(rv, J1, J2, J3); }, "None", py::arg("J1min"), py::arg("J2min"), py::arg("J3min"), py::arg("J1"), py::arg("J2"), py::arg("J3"));
cls_AppDef_SmoothCriterion.def("ErrorValues", [](AppDef_SmoothCriterion &self, Standard_Real & MaxError, Standard_Real & QuadraticError, Standard_Real & AverageError){ self.ErrorValues(MaxError, QuadraticError, AverageError); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(MaxError, QuadraticError, AverageError); }, "None", py::arg("MaxError"), py::arg("QuadraticError"), py::arg("AverageError"));
cls_AppDef_SmoothCriterion.def("Hessian", (void (AppDef_SmoothCriterion::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, math_Matrix &)) &AppDef_SmoothCriterion::Hessian, "None", py::arg("Element"), py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
cls_AppDef_SmoothCriterion.def("Gradient", (void (AppDef_SmoothCriterion::*)(const Standard_Integer, const Standard_Integer, math_Vector &)) &AppDef_SmoothCriterion::Gradient, "None", py::arg("Element"), py::arg("Dimension"), py::arg("G"));
cls_AppDef_SmoothCriterion.def("InputVector", (void (AppDef_SmoothCriterion::*)(const math_Vector &, const opencascade::handle<FEmTool_HAssemblyTable> &)) &AppDef_SmoothCriterion::InputVector, "Convert the assembly Vector in an Curve;", py::arg("X"), py::arg("AssTable"));
cls_AppDef_SmoothCriterion.def("SetWeight", (void (AppDef_SmoothCriterion::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppDef_SmoothCriterion::SetWeight, "None", py::arg("QuadraticWeight"), py::arg("QualityWeight"), py::arg("percentJ1"), py::arg("percentJ2"), py::arg("percentJ3"));
cls_AppDef_SmoothCriterion.def("GetWeight", [](AppDef_SmoothCriterion &self, Standard_Real & QuadraticWeight, Standard_Real & QualityWeight){ self.GetWeight(QuadraticWeight, QualityWeight); return std::tuple<Standard_Real &, Standard_Real &>(QuadraticWeight, QualityWeight); }, "None", py::arg("QuadraticWeight"), py::arg("QualityWeight"));
cls_AppDef_SmoothCriterion.def("SetWeight", (void (AppDef_SmoothCriterion::*)(const TColStd_Array1OfReal &)) &AppDef_SmoothCriterion::SetWeight, "None", py::arg("Weight"));
cls_AppDef_SmoothCriterion.def_static("get_type_name_", (const char * (*)()) &AppDef_SmoothCriterion::get_type_name, "None");
cls_AppDef_SmoothCriterion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppDef_SmoothCriterion::get_type_descriptor, "None");
cls_AppDef_SmoothCriterion.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppDef_SmoothCriterion::*)() const) &AppDef_SmoothCriterion::DynamicType, "None");

// CLASS: APPDEF_LINEARCRITERIA
py::class_<AppDef_LinearCriteria, opencascade::handle<AppDef_LinearCriteria>, AppDef_SmoothCriterion> cls_AppDef_LinearCriteria(mod, "AppDef_LinearCriteria", "defined an Linear Criteria to used in variational Smoothing of points.");

// Constructors
cls_AppDef_LinearCriteria.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"));

// Methods
cls_AppDef_LinearCriteria.def("SetParameters", (void (AppDef_LinearCriteria::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &AppDef_LinearCriteria::SetParameters, "None", py::arg("Parameters"));
cls_AppDef_LinearCriteria.def("SetCurve", (void (AppDef_LinearCriteria::*)(const opencascade::handle<FEmTool_Curve> &)) &AppDef_LinearCriteria::SetCurve, "None", py::arg("C"));
cls_AppDef_LinearCriteria.def("GetCurve", (void (AppDef_LinearCriteria::*)(opencascade::handle<FEmTool_Curve> &) const) &AppDef_LinearCriteria::GetCurve, "None", py::arg("C"));
cls_AppDef_LinearCriteria.def("SetEstimation", (void (AppDef_LinearCriteria::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &AppDef_LinearCriteria::SetEstimation, "None", py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_AppDef_LinearCriteria.def("EstLength", (Standard_Real & (AppDef_LinearCriteria::*)()) &AppDef_LinearCriteria::EstLength, "None");
cls_AppDef_LinearCriteria.def("GetEstimation", [](AppDef_LinearCriteria &self, Standard_Real & E1, Standard_Real & E2, Standard_Real & E3){ self.GetEstimation(E1, E2, E3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(E1, E2, E3); }, "None", py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_AppDef_LinearCriteria.def("AssemblyTable", (opencascade::handle<FEmTool_HAssemblyTable> (AppDef_LinearCriteria::*)() const) &AppDef_LinearCriteria::AssemblyTable, "None");
cls_AppDef_LinearCriteria.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (AppDef_LinearCriteria::*)() const) &AppDef_LinearCriteria::DependenceTable, "None");
cls_AppDef_LinearCriteria.def("QualityValues", [](AppDef_LinearCriteria &self, const Standard_Real J1min, const Standard_Real J2min, const Standard_Real J3min, Standard_Real & J1, Standard_Real & J2, Standard_Real & J3){ Standard_Integer rv = self.QualityValues(J1min, J2min, J3min, J1, J2, J3); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &>(rv, J1, J2, J3); }, "None", py::arg("J1min"), py::arg("J2min"), py::arg("J3min"), py::arg("J1"), py::arg("J2"), py::arg("J3"));
cls_AppDef_LinearCriteria.def("ErrorValues", [](AppDef_LinearCriteria &self, Standard_Real & MaxError, Standard_Real & QuadraticError, Standard_Real & AverageError){ self.ErrorValues(MaxError, QuadraticError, AverageError); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(MaxError, QuadraticError, AverageError); }, "None", py::arg("MaxError"), py::arg("QuadraticError"), py::arg("AverageError"));
cls_AppDef_LinearCriteria.def("Hessian", (void (AppDef_LinearCriteria::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, math_Matrix &)) &AppDef_LinearCriteria::Hessian, "None", py::arg("Element"), py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
cls_AppDef_LinearCriteria.def("Gradient", (void (AppDef_LinearCriteria::*)(const Standard_Integer, const Standard_Integer, math_Vector &)) &AppDef_LinearCriteria::Gradient, "None", py::arg("Element"), py::arg("Dimension"), py::arg("G"));
cls_AppDef_LinearCriteria.def("InputVector", (void (AppDef_LinearCriteria::*)(const math_Vector &, const opencascade::handle<FEmTool_HAssemblyTable> &)) &AppDef_LinearCriteria::InputVector, "Convert the assembly Vector in an Curve;", py::arg("X"), py::arg("AssTable"));
cls_AppDef_LinearCriteria.def("SetWeight", (void (AppDef_LinearCriteria::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppDef_LinearCriteria::SetWeight, "None", py::arg("QuadraticWeight"), py::arg("QualityWeight"), py::arg("percentJ1"), py::arg("percentJ2"), py::arg("percentJ3"));
cls_AppDef_LinearCriteria.def("GetWeight", [](AppDef_LinearCriteria &self, Standard_Real & QuadraticWeight, Standard_Real & QualityWeight){ self.GetWeight(QuadraticWeight, QualityWeight); return std::tuple<Standard_Real &, Standard_Real &>(QuadraticWeight, QualityWeight); }, "None", py::arg("QuadraticWeight"), py::arg("QualityWeight"));
cls_AppDef_LinearCriteria.def("SetWeight", (void (AppDef_LinearCriteria::*)(const TColStd_Array1OfReal &)) &AppDef_LinearCriteria::SetWeight, "None", py::arg("Weight"));
cls_AppDef_LinearCriteria.def_static("get_type_name_", (const char * (*)()) &AppDef_LinearCriteria::get_type_name, "None");
cls_AppDef_LinearCriteria.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppDef_LinearCriteria::get_type_descriptor, "None");
cls_AppDef_LinearCriteria.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppDef_LinearCriteria::*)() const) &AppDef_LinearCriteria::DynamicType, "None");

// CLASS: APPDEF_MYBSPLGRADIENTOFBSPLINECOMPUTE
py::class_<AppDef_MyBSplGradientOfBSplineCompute> cls_AppDef_MyBSplGradientOfBSplineCompute(mod, "AppDef_MyBSplGradientOfBSplineCompute", "None");

// Constructors
cls_AppDef_MyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Knots"), py::arg("Mults"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"));
cls_AppDef_MyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Knots"), py::arg("Mults"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIterations"));
cls_AppDef_MyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Knots"), py::arg("Mults"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIterations"), py::arg("lambda1"), py::arg("lambda2"));

// Methods
// cls_AppDef_MyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_MyBSplGradientOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_MyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_MyBSplGradientOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_MyBSplGradientOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_MyBSplGradientOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_MyBSplGradientOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_MyBSplGradientOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_MyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_MyBSplGradientOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_MyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_MyBSplGradientOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_MyBSplGradientOfBSplineCompute.def("IsDone", (Standard_Boolean (AppDef_MyBSplGradientOfBSplineCompute::*)() const) &AppDef_MyBSplGradientOfBSplineCompute::IsDone, "returns True if all has been correctly done.");
cls_AppDef_MyBSplGradientOfBSplineCompute.def("Value", (AppParCurves_MultiBSpCurve (AppDef_MyBSplGradientOfBSplineCompute::*)() const) &AppDef_MyBSplGradientOfBSplineCompute::Value, "returns all the BSpline curves approximating the MultiLine SSP after minimization of the parameter.");
cls_AppDef_MyBSplGradientOfBSplineCompute.def("Error", (Standard_Real (AppDef_MyBSplGradientOfBSplineCompute::*)(const Standard_Integer) const) &AppDef_MyBSplGradientOfBSplineCompute::Error, "returns the difference between the old and the new approximation. An exception is raised if NotDone. An exception is raised if Index<1 or Index>NbParameters.", py::arg("Index"));
cls_AppDef_MyBSplGradientOfBSplineCompute.def("MaxError3d", (Standard_Real (AppDef_MyBSplGradientOfBSplineCompute::*)() const) &AppDef_MyBSplGradientOfBSplineCompute::MaxError3d, "returns the maximum difference between the old and the new approximation.");
cls_AppDef_MyBSplGradientOfBSplineCompute.def("MaxError2d", (Standard_Real (AppDef_MyBSplGradientOfBSplineCompute::*)() const) &AppDef_MyBSplGradientOfBSplineCompute::MaxError2d, "returns the maximum difference between the old and the new approximation.");
cls_AppDef_MyBSplGradientOfBSplineCompute.def("AverageError", (Standard_Real (AppDef_MyBSplGradientOfBSplineCompute::*)() const) &AppDef_MyBSplGradientOfBSplineCompute::AverageError, "returns the average error between the old and the new approximation.");

// CLASS: APPDEF_MYGRADIENTBISOFBSPLINECOMPUTE
py::class_<AppDef_MyGradientbisOfBSplineCompute> cls_AppDef_MyGradientbisOfBSplineCompute(mod, "AppDef_MyGradientbisOfBSplineCompute", "None");

// Constructors
cls_AppDef_MyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"));
cls_AppDef_MyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIterations"));

// Methods
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_MyGradientbisOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_MyGradientbisOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_MyGradientbisOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_MyGradientbisOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_MyGradientbisOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_MyGradientbisOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_MyGradientbisOfBSplineCompute.def("IsDone", (Standard_Boolean (AppDef_MyGradientbisOfBSplineCompute::*)() const) &AppDef_MyGradientbisOfBSplineCompute::IsDone, "returns True if all has been correctly done.");
cls_AppDef_MyGradientbisOfBSplineCompute.def("Value", (AppParCurves_MultiCurve (AppDef_MyGradientbisOfBSplineCompute::*)() const) &AppDef_MyGradientbisOfBSplineCompute::Value, "returns all the Bezier curves approximating the MultiLine SSP after minimization of the parameter.");
cls_AppDef_MyGradientbisOfBSplineCompute.def("Error", (Standard_Real (AppDef_MyGradientbisOfBSplineCompute::*)(const Standard_Integer) const) &AppDef_MyGradientbisOfBSplineCompute::Error, "returns the difference between the old and the new approximation. An exception is raised if NotDone. An exception is raised if Index<1 or Index>NbParameters.", py::arg("Index"));
cls_AppDef_MyGradientbisOfBSplineCompute.def("MaxError3d", (Standard_Real (AppDef_MyGradientbisOfBSplineCompute::*)() const) &AppDef_MyGradientbisOfBSplineCompute::MaxError3d, "returns the maximum difference between the old and the new approximation.");
cls_AppDef_MyGradientbisOfBSplineCompute.def("MaxError2d", (Standard_Real (AppDef_MyGradientbisOfBSplineCompute::*)() const) &AppDef_MyGradientbisOfBSplineCompute::MaxError2d, "returns the maximum difference between the old and the new approximation.");
cls_AppDef_MyGradientbisOfBSplineCompute.def("AverageError", (Standard_Real (AppDef_MyGradientbisOfBSplineCompute::*)() const) &AppDef_MyGradientbisOfBSplineCompute::AverageError, "returns the average error between the old and the new approximation.");

// CLASS: APPDEF_MYGRADIENTOFCOMPUTE
py::class_<AppDef_MyGradientOfCompute> cls_AppDef_MyGradientOfCompute(mod, "AppDef_MyGradientOfCompute", "None");

// Constructors
cls_AppDef_MyGradientOfCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"));
cls_AppDef_MyGradientOfCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIterations"));

// Methods
// cls_AppDef_MyGradientOfCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_MyGradientOfCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_MyGradientOfCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_MyGradientOfCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_MyGradientOfCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_MyGradientOfCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_MyGradientOfCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_MyGradientOfCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_MyGradientOfCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_MyGradientOfCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_MyGradientOfCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_MyGradientOfCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_MyGradientOfCompute.def("IsDone", (Standard_Boolean (AppDef_MyGradientOfCompute::*)() const) &AppDef_MyGradientOfCompute::IsDone, "returns True if all has been correctly done.");
cls_AppDef_MyGradientOfCompute.def("Value", (AppParCurves_MultiCurve (AppDef_MyGradientOfCompute::*)() const) &AppDef_MyGradientOfCompute::Value, "returns all the Bezier curves approximating the MultiLine SSP after minimization of the parameter.");
cls_AppDef_MyGradientOfCompute.def("Error", (Standard_Real (AppDef_MyGradientOfCompute::*)(const Standard_Integer) const) &AppDef_MyGradientOfCompute::Error, "returns the difference between the old and the new approximation. An exception is raised if NotDone. An exception is raised if Index<1 or Index>NbParameters.", py::arg("Index"));
cls_AppDef_MyGradientOfCompute.def("MaxError3d", (Standard_Real (AppDef_MyGradientOfCompute::*)() const) &AppDef_MyGradientOfCompute::MaxError3d, "returns the maximum difference between the old and the new approximation.");
cls_AppDef_MyGradientOfCompute.def("MaxError2d", (Standard_Real (AppDef_MyGradientOfCompute::*)() const) &AppDef_MyGradientOfCompute::MaxError2d, "returns the maximum difference between the old and the new approximation.");
cls_AppDef_MyGradientOfCompute.def("AverageError", (Standard_Real (AppDef_MyGradientOfCompute::*)() const) &AppDef_MyGradientOfCompute::AverageError, "returns the average error between the old and the new approximation.");

// CLASS: APPDEF_MYLINETOOL
py::class_<AppDef_MyLineTool> cls_AppDef_MyLineTool(mod, "AppDef_MyLineTool", "example of MultiLine tool corresponding to the tools of the packages AppParCurves and Approx. For Approx, the tool will not addd points if the algorithms want some.");

// Methods
// cls_AppDef_MyLineTool.def_static("operator new_", (void * (*)(size_t)) &AppDef_MyLineTool::operator new, "None", py::arg("theSize"));
// cls_AppDef_MyLineTool.def_static("operator delete_", (void (*)(void *)) &AppDef_MyLineTool::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_MyLineTool.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_MyLineTool::operator new[], "None", py::arg("theSize"));
// cls_AppDef_MyLineTool.def_static("operator delete[]_", (void (*)(void *)) &AppDef_MyLineTool::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_MyLineTool.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_MyLineTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_MyLineTool.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_MyLineTool::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_MyLineTool.def_static("FirstPoint_", (Standard_Integer (*)(const AppDef_MultiLine &)) &AppDef_MyLineTool::FirstPoint, "Returns the first index of multipoints of the MultiLine.", py::arg("ML"));
cls_AppDef_MyLineTool.def_static("LastPoint_", (Standard_Integer (*)(const AppDef_MultiLine &)) &AppDef_MyLineTool::LastPoint, "Returns the last index of multipoints of the MultiLine.", py::arg("ML"));
cls_AppDef_MyLineTool.def_static("NbP2d_", (Standard_Integer (*)(const AppDef_MultiLine &)) &AppDef_MyLineTool::NbP2d, "Returns the number of 2d points of a MultiLine.", py::arg("ML"));
cls_AppDef_MyLineTool.def_static("NbP3d_", (Standard_Integer (*)(const AppDef_MultiLine &)) &AppDef_MyLineTool::NbP3d, "Returns the number of 3d points of a MultiLine.", py::arg("ML"));
cls_AppDef_MyLineTool.def_static("Value_", (void (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfPnt &)) &AppDef_MyLineTool::Value, "returns the 3d points of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt"));
cls_AppDef_MyLineTool.def_static("Value_", (void (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfPnt2d &)) &AppDef_MyLineTool::Value, "returns the 2d points of the multipoint <MPointIndex> when only 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt2d"));
cls_AppDef_MyLineTool.def_static("Value_", (void (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &)) &AppDef_MyLineTool::Value, "returns the 3d and 2d points of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt"), py::arg("tabPt2d"));
cls_AppDef_MyLineTool.def_static("Tangency_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec &)) &AppDef_MyLineTool::Tangency, "returns the 3d points of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"));
cls_AppDef_MyLineTool.def_static("Tangency_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec2d &)) &AppDef_MyLineTool::Tangency, "returns the 2d tangency points of the multipoint <MPointIndex> only when 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV2d"));
cls_AppDef_MyLineTool.def_static("Tangency_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec &, TColgp_Array1OfVec2d &)) &AppDef_MyLineTool::Tangency, "returns the 3d and 2d points of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"), py::arg("tabV2d"));
cls_AppDef_MyLineTool.def_static("Curvature_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec &)) &AppDef_MyLineTool::Curvature, "returns the 3d curvatures of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"));
cls_AppDef_MyLineTool.def_static("Curvature_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec2d &)) &AppDef_MyLineTool::Curvature, "returns the 2d curvatures of the multipoint <MPointIndex> only when 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV2d"));
cls_AppDef_MyLineTool.def_static("Curvature_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec &, TColgp_Array1OfVec2d &)) &AppDef_MyLineTool::Curvature, "returns the 3d and 2d curvatures of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"), py::arg("tabV2d"));
cls_AppDef_MyLineTool.def_static("WhatStatus_", (Approx_Status (*)(const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer)) &AppDef_MyLineTool::WhatStatus, "returns NoPointsAdded", py::arg("ML"), py::arg("I1"), py::arg("I2"));
cls_AppDef_MyLineTool.def_static("MakeMLBetween_", (AppDef_MultiLine (*)(const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &AppDef_MyLineTool::MakeMLBetween, "Is never called in the algorithms. Nothing is done.", py::arg("ML"), py::arg("I1"), py::arg("I2"), py::arg("NbPMin"));
cls_AppDef_MyLineTool.def_static("MakeMLOneMorePoint_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Integer, AppDef_MultiLine &)) &AppDef_MyLineTool::MakeMLOneMorePoint, "Is never called in the algorithms. Nothing is done.", py::arg("ML"), py::arg("I1"), py::arg("I2"), py::arg("indbad"), py::arg("OtherLine"));

// CLASS: APPDEF_PARLEASTSQUAREOFMYGRADIENTBISOFBSPLINECOMPUTE
py::class_<AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute> cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute(mod, "AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute", "None");

// Constructors
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));

// Methods
// cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("Perform", (void (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)(const math_Vector &)) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::Perform, "Is used after having initialized the fields. The case 'CurvaturePoint' is not treated in this method.", py::arg("Parameters"));
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("Perform", (void (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)(const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::Perform, "Is used after having initialized the fields.", py::arg("Parameters"), py::arg("l1"), py::arg("l2"));
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("Perform", (void (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)(const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("l1"), py::arg("l2"));
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("Perform", (void (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)(const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point. <V1c> is the tangent vector at the first point. <V2c> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("V1c"), py::arg("V2c"), py::arg("l1"), py::arg("l2"));
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("IsDone", (Standard_Boolean (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::IsDone, "returns True if all has been correctly done.");
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("BezierValue", (AppParCurves_MultiCurve (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)()) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::BezierValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("BSplineValue", (const AppParCurves_MultiBSpCurve & (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)()) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::BSplineValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("FunctionMatrix", (const math_Matrix & (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::FunctionMatrix, "returns the function matrix used to approximate the set.");
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("DerivativeFunctionMatrix", (const math_Matrix & (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::DerivativeFunctionMatrix, "returns the derivative function matrix used to approximate the set.");
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("ErrorGradient", [](AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute &self, math_Vector & Grad, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.ErrorGradient(Grad, F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances. Grad is the derivative vector of the function F.", py::arg("Grad"), py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("Distance", (const math_Matrix & (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)()) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::Distance, "returns the distances between the points of the multiline and the approximation curves.");
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("Error", [](AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute &self, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.Error(F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances.", py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("FirstLambda", (Standard_Real (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::FirstLambda, "returns the value (P2 - P1)/ V1 if the first point was a tangency point.");
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("LastLambda", (Standard_Real (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::LastLambda, "returns the value (PN - PN-1)/ VN if the last point was a tangency point.");
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("Points", (const math_Matrix & (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::Points, "returns the matrix of points value.");
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("Poles", (const math_Matrix & (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::Poles, "returns the matrix of resulting control points value.");
cls_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute.def("KIndex", (const math_IntegerVector & (AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute::KIndex, "Returns the indexes of the first non null values of A and DA. The values are non null from Index(ieme point) +1 to Index(ieme point) + degree +1.");

// CLASS: APPDEF_PARFUNCTIONOFMYGRADIENTBISOFBSPLINECOMPUTE
py::class_<AppDef_ParFunctionOfMyGradientbisOfBSplineCompute, math_MultipleVarFunctionWithGradient> cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute(mod, "AppDef_ParFunctionOfMyGradientbisOfBSplineCompute", "None");

// Constructors
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"));

// Methods
// cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("NbVariables", (Standard_Integer (AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::NbVariables, "returns the number of variables of the function. It corresponds to the number of MultiPoints.");
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("Value", [](AppDef_ParFunctionOfMyGradientbisOfBSplineCompute &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "this method computes the new approximation of the MultiLine SSP and calculates F = sum (||Pui - Bi*Pi||2) for each point of the MultiLine.", py::arg("X"), py::arg("F"));
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("Gradient", (Standard_Boolean (AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::*)(const math_Vector &, math_Vector &)) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::Gradient, "returns the gradient G of the sum above for the parameters Xi.", py::arg("X"), py::arg("G"));
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("Values", [](AppDef_ParFunctionOfMyGradientbisOfBSplineCompute &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "returns the value F=sum(||Pui - Bi*Pi||)2. returns the value G = grad(F) for the parameters Xi.", py::arg("X"), py::arg("F"), py::arg("G"));
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("NewParameters", (const math_Vector & (AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::NewParameters, "returns the new parameters of the MultiLine.");
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("CurveValue", (const AppParCurves_MultiCurve & (AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::*)()) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::CurveValue, "returns the MultiCurve approximating the set after computing the value F or Grad(F).");
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("Error", (Standard_Real (AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::*)(const Standard_Integer, const Standard_Integer) const) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::Error, "returns the distance between the MultiPoint of range IPoint and the curve CurveIndex.", py::arg("IPoint"), py::arg("CurveIndex"));
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("MaxError3d", (Standard_Real (AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::MaxError3d, "returns the maximum distance between the points and the MultiCurve.");
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("MaxError2d", (Standard_Real (AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::MaxError2d, "returns the maximum distance between the points and the MultiCurve.");
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("FirstConstraint", (AppParCurves_Constraint (AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::FirstConstraint, "None", py::arg("TheConstraints"), py::arg("FirstPoint"));
cls_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute.def("LastConstraint", (AppParCurves_Constraint (AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_ParFunctionOfMyGradientbisOfBSplineCompute::LastConstraint, "None", py::arg("TheConstraints"), py::arg("LastPoint"));

// CLASS: APPDEF_PARLEASTSQUAREOFMYGRADIENTOFCOMPUTE
py::class_<AppDef_ParLeastSquareOfMyGradientOfCompute> cls_AppDef_ParLeastSquareOfMyGradientOfCompute(mod, "AppDef_ParLeastSquareOfMyGradientOfCompute", "None");

// Constructors
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));

// Methods
// cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_ParLeastSquareOfMyGradientOfCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_ParLeastSquareOfMyGradientOfCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ParLeastSquareOfMyGradientOfCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ParLeastSquareOfMyGradientOfCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ParLeastSquareOfMyGradientOfCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ParLeastSquareOfMyGradientOfCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("Perform", (void (AppDef_ParLeastSquareOfMyGradientOfCompute::*)(const math_Vector &)) &AppDef_ParLeastSquareOfMyGradientOfCompute::Perform, "Is used after having initialized the fields. The case 'CurvaturePoint' is not treated in this method.", py::arg("Parameters"));
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("Perform", (void (AppDef_ParLeastSquareOfMyGradientOfCompute::*)(const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_ParLeastSquareOfMyGradientOfCompute::Perform, "Is used after having initialized the fields.", py::arg("Parameters"), py::arg("l1"), py::arg("l2"));
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("Perform", (void (AppDef_ParLeastSquareOfMyGradientOfCompute::*)(const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_ParLeastSquareOfMyGradientOfCompute::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("l1"), py::arg("l2"));
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("Perform", (void (AppDef_ParLeastSquareOfMyGradientOfCompute::*)(const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_ParLeastSquareOfMyGradientOfCompute::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point. <V1c> is the tangent vector at the first point. <V2c> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("V1c"), py::arg("V2c"), py::arg("l1"), py::arg("l2"));
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("IsDone", (Standard_Boolean (AppDef_ParLeastSquareOfMyGradientOfCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientOfCompute::IsDone, "returns True if all has been correctly done.");
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("BezierValue", (AppParCurves_MultiCurve (AppDef_ParLeastSquareOfMyGradientOfCompute::*)()) &AppDef_ParLeastSquareOfMyGradientOfCompute::BezierValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("BSplineValue", (const AppParCurves_MultiBSpCurve & (AppDef_ParLeastSquareOfMyGradientOfCompute::*)()) &AppDef_ParLeastSquareOfMyGradientOfCompute::BSplineValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("FunctionMatrix", (const math_Matrix & (AppDef_ParLeastSquareOfMyGradientOfCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientOfCompute::FunctionMatrix, "returns the function matrix used to approximate the set.");
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("DerivativeFunctionMatrix", (const math_Matrix & (AppDef_ParLeastSquareOfMyGradientOfCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientOfCompute::DerivativeFunctionMatrix, "returns the derivative function matrix used to approximate the set.");
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("ErrorGradient", [](AppDef_ParLeastSquareOfMyGradientOfCompute &self, math_Vector & Grad, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.ErrorGradient(Grad, F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances. Grad is the derivative vector of the function F.", py::arg("Grad"), py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("Distance", (const math_Matrix & (AppDef_ParLeastSquareOfMyGradientOfCompute::*)()) &AppDef_ParLeastSquareOfMyGradientOfCompute::Distance, "returns the distances between the points of the multiline and the approximation curves.");
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("Error", [](AppDef_ParLeastSquareOfMyGradientOfCompute &self, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.Error(F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances.", py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("FirstLambda", (Standard_Real (AppDef_ParLeastSquareOfMyGradientOfCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientOfCompute::FirstLambda, "returns the value (P2 - P1)/ V1 if the first point was a tangency point.");
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("LastLambda", (Standard_Real (AppDef_ParLeastSquareOfMyGradientOfCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientOfCompute::LastLambda, "returns the value (PN - PN-1)/ VN if the last point was a tangency point.");
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("Points", (const math_Matrix & (AppDef_ParLeastSquareOfMyGradientOfCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientOfCompute::Points, "returns the matrix of points value.");
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("Poles", (const math_Matrix & (AppDef_ParLeastSquareOfMyGradientOfCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientOfCompute::Poles, "returns the matrix of resulting control points value.");
cls_AppDef_ParLeastSquareOfMyGradientOfCompute.def("KIndex", (const math_IntegerVector & (AppDef_ParLeastSquareOfMyGradientOfCompute::*)() const) &AppDef_ParLeastSquareOfMyGradientOfCompute::KIndex, "Returns the indexes of the first non null values of A and DA. The values are non null from Index(ieme point) +1 to Index(ieme point) + degree +1.");

// CLASS: APPDEF_PARFUNCTIONOFMYGRADIENTOFCOMPUTE
py::class_<AppDef_ParFunctionOfMyGradientOfCompute, math_MultipleVarFunctionWithGradient> cls_AppDef_ParFunctionOfMyGradientOfCompute(mod, "AppDef_ParFunctionOfMyGradientOfCompute", "None");

// Constructors
cls_AppDef_ParFunctionOfMyGradientOfCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"));

// Methods
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_ParFunctionOfMyGradientOfCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_ParFunctionOfMyGradientOfCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ParFunctionOfMyGradientOfCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ParFunctionOfMyGradientOfCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ParFunctionOfMyGradientOfCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ParFunctionOfMyGradientOfCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("NbVariables", (Standard_Integer (AppDef_ParFunctionOfMyGradientOfCompute::*)() const) &AppDef_ParFunctionOfMyGradientOfCompute::NbVariables, "returns the number of variables of the function. It corresponds to the number of MultiPoints.");
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("Value", [](AppDef_ParFunctionOfMyGradientOfCompute &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "this method computes the new approximation of the MultiLine SSP and calculates F = sum (||Pui - Bi*Pi||2) for each point of the MultiLine.", py::arg("X"), py::arg("F"));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("Gradient", (Standard_Boolean (AppDef_ParFunctionOfMyGradientOfCompute::*)(const math_Vector &, math_Vector &)) &AppDef_ParFunctionOfMyGradientOfCompute::Gradient, "returns the gradient G of the sum above for the parameters Xi.", py::arg("X"), py::arg("G"));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("Values", [](AppDef_ParFunctionOfMyGradientOfCompute &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "returns the value F=sum(||Pui - Bi*Pi||)2. returns the value G = grad(F) for the parameters Xi.", py::arg("X"), py::arg("F"), py::arg("G"));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("NewParameters", (const math_Vector & (AppDef_ParFunctionOfMyGradientOfCompute::*)() const) &AppDef_ParFunctionOfMyGradientOfCompute::NewParameters, "returns the new parameters of the MultiLine.");
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("CurveValue", (const AppParCurves_MultiCurve & (AppDef_ParFunctionOfMyGradientOfCompute::*)()) &AppDef_ParFunctionOfMyGradientOfCompute::CurveValue, "returns the MultiCurve approximating the set after computing the value F or Grad(F).");
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("Error", (Standard_Real (AppDef_ParFunctionOfMyGradientOfCompute::*)(const Standard_Integer, const Standard_Integer) const) &AppDef_ParFunctionOfMyGradientOfCompute::Error, "returns the distance between the MultiPoint of range IPoint and the curve CurveIndex.", py::arg("IPoint"), py::arg("CurveIndex"));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("MaxError3d", (Standard_Real (AppDef_ParFunctionOfMyGradientOfCompute::*)() const) &AppDef_ParFunctionOfMyGradientOfCompute::MaxError3d, "returns the maximum distance between the points and the MultiCurve.");
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("MaxError2d", (Standard_Real (AppDef_ParFunctionOfMyGradientOfCompute::*)() const) &AppDef_ParFunctionOfMyGradientOfCompute::MaxError2d, "returns the maximum distance between the points and the MultiCurve.");
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("FirstConstraint", (AppParCurves_Constraint (AppDef_ParFunctionOfMyGradientOfCompute::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_ParFunctionOfMyGradientOfCompute::FirstConstraint, "None", py::arg("TheConstraints"), py::arg("FirstPoint"));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("LastConstraint", (AppParCurves_Constraint (AppDef_ParFunctionOfMyGradientOfCompute::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_ParFunctionOfMyGradientOfCompute::LastConstraint, "None", py::arg("TheConstraints"), py::arg("LastPoint"));

// CLASS: APPDEF_PARLEASTSQUAREOFTHEGRADIENT
py::class_<AppDef_ParLeastSquareOfTheGradient> cls_AppDef_ParLeastSquareOfTheGradient(mod, "AppDef_ParLeastSquareOfTheGradient", "None");

// Constructors
cls_AppDef_ParLeastSquareOfTheGradient.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_ParLeastSquareOfTheGradient.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));
cls_AppDef_ParLeastSquareOfTheGradient.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_ParLeastSquareOfTheGradient.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));

// Methods
// cls_AppDef_ParLeastSquareOfTheGradient.def_static("operator new_", (void * (*)(size_t)) &AppDef_ParLeastSquareOfTheGradient::operator new, "None", py::arg("theSize"));
// cls_AppDef_ParLeastSquareOfTheGradient.def_static("operator delete_", (void (*)(void *)) &AppDef_ParLeastSquareOfTheGradient::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ParLeastSquareOfTheGradient.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ParLeastSquareOfTheGradient::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ParLeastSquareOfTheGradient.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ParLeastSquareOfTheGradient::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ParLeastSquareOfTheGradient.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ParLeastSquareOfTheGradient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ParLeastSquareOfTheGradient.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ParLeastSquareOfTheGradient::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ParLeastSquareOfTheGradient.def("Perform", (void (AppDef_ParLeastSquareOfTheGradient::*)(const math_Vector &)) &AppDef_ParLeastSquareOfTheGradient::Perform, "Is used after having initialized the fields. The case 'CurvaturePoint' is not treated in this method.", py::arg("Parameters"));
cls_AppDef_ParLeastSquareOfTheGradient.def("Perform", (void (AppDef_ParLeastSquareOfTheGradient::*)(const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_ParLeastSquareOfTheGradient::Perform, "Is used after having initialized the fields.", py::arg("Parameters"), py::arg("l1"), py::arg("l2"));
cls_AppDef_ParLeastSquareOfTheGradient.def("Perform", (void (AppDef_ParLeastSquareOfTheGradient::*)(const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_ParLeastSquareOfTheGradient::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("l1"), py::arg("l2"));
cls_AppDef_ParLeastSquareOfTheGradient.def("Perform", (void (AppDef_ParLeastSquareOfTheGradient::*)(const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_ParLeastSquareOfTheGradient::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point. <V1c> is the tangent vector at the first point. <V2c> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("V1c"), py::arg("V2c"), py::arg("l1"), py::arg("l2"));
cls_AppDef_ParLeastSquareOfTheGradient.def("IsDone", (Standard_Boolean (AppDef_ParLeastSquareOfTheGradient::*)() const) &AppDef_ParLeastSquareOfTheGradient::IsDone, "returns True if all has been correctly done.");
cls_AppDef_ParLeastSquareOfTheGradient.def("BezierValue", (AppParCurves_MultiCurve (AppDef_ParLeastSquareOfTheGradient::*)()) &AppDef_ParLeastSquareOfTheGradient::BezierValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_ParLeastSquareOfTheGradient.def("BSplineValue", (const AppParCurves_MultiBSpCurve & (AppDef_ParLeastSquareOfTheGradient::*)()) &AppDef_ParLeastSquareOfTheGradient::BSplineValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_ParLeastSquareOfTheGradient.def("FunctionMatrix", (const math_Matrix & (AppDef_ParLeastSquareOfTheGradient::*)() const) &AppDef_ParLeastSquareOfTheGradient::FunctionMatrix, "returns the function matrix used to approximate the set.");
cls_AppDef_ParLeastSquareOfTheGradient.def("DerivativeFunctionMatrix", (const math_Matrix & (AppDef_ParLeastSquareOfTheGradient::*)() const) &AppDef_ParLeastSquareOfTheGradient::DerivativeFunctionMatrix, "returns the derivative function matrix used to approximate the set.");
cls_AppDef_ParLeastSquareOfTheGradient.def("ErrorGradient", [](AppDef_ParLeastSquareOfTheGradient &self, math_Vector & Grad, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.ErrorGradient(Grad, F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances. Grad is the derivative vector of the function F.", py::arg("Grad"), py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_ParLeastSquareOfTheGradient.def("Distance", (const math_Matrix & (AppDef_ParLeastSquareOfTheGradient::*)()) &AppDef_ParLeastSquareOfTheGradient::Distance, "returns the distances between the points of the multiline and the approximation curves.");
cls_AppDef_ParLeastSquareOfTheGradient.def("Error", [](AppDef_ParLeastSquareOfTheGradient &self, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.Error(F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances.", py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_ParLeastSquareOfTheGradient.def("FirstLambda", (Standard_Real (AppDef_ParLeastSquareOfTheGradient::*)() const) &AppDef_ParLeastSquareOfTheGradient::FirstLambda, "returns the value (P2 - P1)/ V1 if the first point was a tangency point.");
cls_AppDef_ParLeastSquareOfTheGradient.def("LastLambda", (Standard_Real (AppDef_ParLeastSquareOfTheGradient::*)() const) &AppDef_ParLeastSquareOfTheGradient::LastLambda, "returns the value (PN - PN-1)/ VN if the last point was a tangency point.");
cls_AppDef_ParLeastSquareOfTheGradient.def("Points", (const math_Matrix & (AppDef_ParLeastSquareOfTheGradient::*)() const) &AppDef_ParLeastSquareOfTheGradient::Points, "returns the matrix of points value.");
cls_AppDef_ParLeastSquareOfTheGradient.def("Poles", (const math_Matrix & (AppDef_ParLeastSquareOfTheGradient::*)() const) &AppDef_ParLeastSquareOfTheGradient::Poles, "returns the matrix of resulting control points value.");
cls_AppDef_ParLeastSquareOfTheGradient.def("KIndex", (const math_IntegerVector & (AppDef_ParLeastSquareOfTheGradient::*)() const) &AppDef_ParLeastSquareOfTheGradient::KIndex, "Returns the indexes of the first non null values of A and DA. The values are non null from Index(ieme point) +1 to Index(ieme point) + degree +1.");

// CLASS: APPDEF_PARFUNCTIONOFTHEGRADIENT
py::class_<AppDef_ParFunctionOfTheGradient, math_MultipleVarFunctionWithGradient> cls_AppDef_ParFunctionOfTheGradient(mod, "AppDef_ParFunctionOfTheGradient", "None");

// Constructors
cls_AppDef_ParFunctionOfTheGradient.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"));

// Methods
// cls_AppDef_ParFunctionOfTheGradient.def_static("operator new_", (void * (*)(size_t)) &AppDef_ParFunctionOfTheGradient::operator new, "None", py::arg("theSize"));
// cls_AppDef_ParFunctionOfTheGradient.def_static("operator delete_", (void (*)(void *)) &AppDef_ParFunctionOfTheGradient::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ParFunctionOfTheGradient.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ParFunctionOfTheGradient::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ParFunctionOfTheGradient.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ParFunctionOfTheGradient::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ParFunctionOfTheGradient.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ParFunctionOfTheGradient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ParFunctionOfTheGradient.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ParFunctionOfTheGradient::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ParFunctionOfTheGradient.def("NbVariables", (Standard_Integer (AppDef_ParFunctionOfTheGradient::*)() const) &AppDef_ParFunctionOfTheGradient::NbVariables, "returns the number of variables of the function. It corresponds to the number of MultiPoints.");
cls_AppDef_ParFunctionOfTheGradient.def("Value", [](AppDef_ParFunctionOfTheGradient &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "this method computes the new approximation of the MultiLine SSP and calculates F = sum (||Pui - Bi*Pi||2) for each point of the MultiLine.", py::arg("X"), py::arg("F"));
cls_AppDef_ParFunctionOfTheGradient.def("Gradient", (Standard_Boolean (AppDef_ParFunctionOfTheGradient::*)(const math_Vector &, math_Vector &)) &AppDef_ParFunctionOfTheGradient::Gradient, "returns the gradient G of the sum above for the parameters Xi.", py::arg("X"), py::arg("G"));
cls_AppDef_ParFunctionOfTheGradient.def("Values", [](AppDef_ParFunctionOfTheGradient &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "returns the value F=sum(||Pui - Bi*Pi||)2. returns the value G = grad(F) for the parameters Xi.", py::arg("X"), py::arg("F"), py::arg("G"));
cls_AppDef_ParFunctionOfTheGradient.def("NewParameters", (const math_Vector & (AppDef_ParFunctionOfTheGradient::*)() const) &AppDef_ParFunctionOfTheGradient::NewParameters, "returns the new parameters of the MultiLine.");
cls_AppDef_ParFunctionOfTheGradient.def("CurveValue", (const AppParCurves_MultiCurve & (AppDef_ParFunctionOfTheGradient::*)()) &AppDef_ParFunctionOfTheGradient::CurveValue, "returns the MultiCurve approximating the set after computing the value F or Grad(F).");
cls_AppDef_ParFunctionOfTheGradient.def("Error", (Standard_Real (AppDef_ParFunctionOfTheGradient::*)(const Standard_Integer, const Standard_Integer) const) &AppDef_ParFunctionOfTheGradient::Error, "returns the distance between the MultiPoint of range IPoint and the curve CurveIndex.", py::arg("IPoint"), py::arg("CurveIndex"));
cls_AppDef_ParFunctionOfTheGradient.def("MaxError3d", (Standard_Real (AppDef_ParFunctionOfTheGradient::*)() const) &AppDef_ParFunctionOfTheGradient::MaxError3d, "returns the maximum distance between the points and the MultiCurve.");
cls_AppDef_ParFunctionOfTheGradient.def("MaxError2d", (Standard_Real (AppDef_ParFunctionOfTheGradient::*)() const) &AppDef_ParFunctionOfTheGradient::MaxError2d, "returns the maximum distance between the points and the MultiCurve.");
cls_AppDef_ParFunctionOfTheGradient.def("FirstConstraint", (AppParCurves_Constraint (AppDef_ParFunctionOfTheGradient::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_ParFunctionOfTheGradient::FirstConstraint, "None", py::arg("TheConstraints"), py::arg("FirstPoint"));
cls_AppDef_ParFunctionOfTheGradient.def("LastConstraint", (AppParCurves_Constraint (AppDef_ParFunctionOfTheGradient::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_ParFunctionOfTheGradient::LastConstraint, "None", py::arg("TheConstraints"), py::arg("LastPoint"));

// CLASS: APPDEF_RESCONSTRAINTOFMYGRADIENTBISOFBSPLINECOMPUTE
py::class_<AppDef_ResConstraintOfMyGradientbisOfBSplineCompute> cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute(mod, "AppDef_ResConstraintOfMyGradientbisOfBSplineCompute", "None");

// Constructors
cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"));
cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &, const Standard_Real>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"), py::arg("Tolerance"));

// Methods
// cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def("IsDone", (Standard_Boolean (AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::IsDone, "returns True if all has been correctly done.");
// cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def("Error", (Standard_Real (AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::Error, "returns the maximum difference value between the curve and the given points.");
cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def("ConstraintMatrix", (const math_Matrix & (AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::ConstraintMatrix, "None");
cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def("Duale", (const math_Vector & (AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::Duale, "returns the duale variables of the system.");
cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def("ConstraintDerivative", (const math_Matrix & (AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::*)(const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const math_Matrix &)) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::ConstraintDerivative, "Returns the derivative of the constraint matrix.", py::arg("SSP"), py::arg("Parameters"), py::arg("Deg"), py::arg("DA"));
cls_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute.def("InverseMatrix", (const math_Matrix & (AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::*)() const) &AppDef_ResConstraintOfMyGradientbisOfBSplineCompute::InverseMatrix, "returns the Inverse of Cont*Transposed(Cont), where Cont is the constraint matrix for the algorithm.");

// CLASS: APPDEF_RESCONSTRAINTOFMYGRADIENTOFCOMPUTE
py::class_<AppDef_ResConstraintOfMyGradientOfCompute> cls_AppDef_ResConstraintOfMyGradientOfCompute(mod, "AppDef_ResConstraintOfMyGradientOfCompute", "None");

// Constructors
cls_AppDef_ResConstraintOfMyGradientOfCompute.def(py::init<const AppDef_MultiLine &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"));
cls_AppDef_ResConstraintOfMyGradientOfCompute.def(py::init<const AppDef_MultiLine &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &, const Standard_Real>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"), py::arg("Tolerance"));

// Methods
// cls_AppDef_ResConstraintOfMyGradientOfCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_ResConstraintOfMyGradientOfCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_ResConstraintOfMyGradientOfCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_ResConstraintOfMyGradientOfCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ResConstraintOfMyGradientOfCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ResConstraintOfMyGradientOfCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ResConstraintOfMyGradientOfCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ResConstraintOfMyGradientOfCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ResConstraintOfMyGradientOfCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ResConstraintOfMyGradientOfCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ResConstraintOfMyGradientOfCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ResConstraintOfMyGradientOfCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ResConstraintOfMyGradientOfCompute.def("IsDone", (Standard_Boolean (AppDef_ResConstraintOfMyGradientOfCompute::*)() const) &AppDef_ResConstraintOfMyGradientOfCompute::IsDone, "returns True if all has been correctly done.");
// cls_AppDef_ResConstraintOfMyGradientOfCompute.def("Error", (Standard_Real (AppDef_ResConstraintOfMyGradientOfCompute::*)() const) &AppDef_ResConstraintOfMyGradientOfCompute::Error, "returns the maximum difference value between the curve and the given points.");
cls_AppDef_ResConstraintOfMyGradientOfCompute.def("ConstraintMatrix", (const math_Matrix & (AppDef_ResConstraintOfMyGradientOfCompute::*)() const) &AppDef_ResConstraintOfMyGradientOfCompute::ConstraintMatrix, "None");
cls_AppDef_ResConstraintOfMyGradientOfCompute.def("Duale", (const math_Vector & (AppDef_ResConstraintOfMyGradientOfCompute::*)() const) &AppDef_ResConstraintOfMyGradientOfCompute::Duale, "returns the duale variables of the system.");
cls_AppDef_ResConstraintOfMyGradientOfCompute.def("ConstraintDerivative", (const math_Matrix & (AppDef_ResConstraintOfMyGradientOfCompute::*)(const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const math_Matrix &)) &AppDef_ResConstraintOfMyGradientOfCompute::ConstraintDerivative, "Returns the derivative of the constraint matrix.", py::arg("SSP"), py::arg("Parameters"), py::arg("Deg"), py::arg("DA"));
cls_AppDef_ResConstraintOfMyGradientOfCompute.def("InverseMatrix", (const math_Matrix & (AppDef_ResConstraintOfMyGradientOfCompute::*)() const) &AppDef_ResConstraintOfMyGradientOfCompute::InverseMatrix, "returns the Inverse of Cont*Transposed(Cont), where Cont is the constraint matrix for the algorithm.");

// CLASS: APPDEF_RESCONSTRAINTOFTHEGRADIENT
py::class_<AppDef_ResConstraintOfTheGradient> cls_AppDef_ResConstraintOfTheGradient(mod, "AppDef_ResConstraintOfTheGradient", "None");

// Constructors
cls_AppDef_ResConstraintOfTheGradient.def(py::init<const AppDef_MultiLine &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"));
cls_AppDef_ResConstraintOfTheGradient.def(py::init<const AppDef_MultiLine &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &, const Standard_Real>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"), py::arg("Tolerance"));

// Methods
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator new_", (void * (*)(size_t)) &AppDef_ResConstraintOfTheGradient::operator new, "None", py::arg("theSize"));
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator delete_", (void (*)(void *)) &AppDef_ResConstraintOfTheGradient::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ResConstraintOfTheGradient::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ResConstraintOfTheGradient::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ResConstraintOfTheGradient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ResConstraintOfTheGradient.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ResConstraintOfTheGradient::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ResConstraintOfTheGradient.def("IsDone", (Standard_Boolean (AppDef_ResConstraintOfTheGradient::*)() const) &AppDef_ResConstraintOfTheGradient::IsDone, "returns True if all has been correctly done.");
// cls_AppDef_ResConstraintOfTheGradient.def("Error", (Standard_Real (AppDef_ResConstraintOfTheGradient::*)() const) &AppDef_ResConstraintOfTheGradient::Error, "returns the maximum difference value between the curve and the given points.");
cls_AppDef_ResConstraintOfTheGradient.def("ConstraintMatrix", (const math_Matrix & (AppDef_ResConstraintOfTheGradient::*)() const) &AppDef_ResConstraintOfTheGradient::ConstraintMatrix, "None");
cls_AppDef_ResConstraintOfTheGradient.def("Duale", (const math_Vector & (AppDef_ResConstraintOfTheGradient::*)() const) &AppDef_ResConstraintOfTheGradient::Duale, "returns the duale variables of the system.");
cls_AppDef_ResConstraintOfTheGradient.def("ConstraintDerivative", (const math_Matrix & (AppDef_ResConstraintOfTheGradient::*)(const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const math_Matrix &)) &AppDef_ResConstraintOfTheGradient::ConstraintDerivative, "Returns the derivative of the constraint matrix.", py::arg("SSP"), py::arg("Parameters"), py::arg("Deg"), py::arg("DA"));
cls_AppDef_ResConstraintOfTheGradient.def("InverseMatrix", (const math_Matrix & (AppDef_ResConstraintOfTheGradient::*)() const) &AppDef_ResConstraintOfTheGradient::InverseMatrix, "returns the Inverse of Cont*Transposed(Cont), where Cont is the constraint matrix for the algorithm.");

// CLASS: APPDEF_THELEASTSQUARES
py::class_<AppDef_TheLeastSquares> cls_AppDef_TheLeastSquares(mod, "AppDef_TheLeastSquares", "None");

// Constructors
cls_AppDef_TheLeastSquares.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_TheLeastSquares.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));
cls_AppDef_TheLeastSquares.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_TheLeastSquares.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));

// Methods
// cls_AppDef_TheLeastSquares.def_static("operator new_", (void * (*)(size_t)) &AppDef_TheLeastSquares::operator new, "None", py::arg("theSize"));
// cls_AppDef_TheLeastSquares.def_static("operator delete_", (void (*)(void *)) &AppDef_TheLeastSquares::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_TheLeastSquares.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_TheLeastSquares::operator new[], "None", py::arg("theSize"));
// cls_AppDef_TheLeastSquares.def_static("operator delete[]_", (void (*)(void *)) &AppDef_TheLeastSquares::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_TheLeastSquares.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_TheLeastSquares::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_TheLeastSquares.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_TheLeastSquares::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_TheLeastSquares.def("Perform", (void (AppDef_TheLeastSquares::*)(const math_Vector &)) &AppDef_TheLeastSquares::Perform, "Is used after having initialized the fields. The case 'CurvaturePoint' is not treated in this method.", py::arg("Parameters"));
cls_AppDef_TheLeastSquares.def("Perform", (void (AppDef_TheLeastSquares::*)(const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_TheLeastSquares::Perform, "Is used after having initialized the fields.", py::arg("Parameters"), py::arg("l1"), py::arg("l2"));
cls_AppDef_TheLeastSquares.def("Perform", (void (AppDef_TheLeastSquares::*)(const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_TheLeastSquares::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("l1"), py::arg("l2"));
cls_AppDef_TheLeastSquares.def("Perform", (void (AppDef_TheLeastSquares::*)(const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_TheLeastSquares::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point. <V1c> is the tangent vector at the first point. <V2c> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("V1c"), py::arg("V2c"), py::arg("l1"), py::arg("l2"));
cls_AppDef_TheLeastSquares.def("IsDone", (Standard_Boolean (AppDef_TheLeastSquares::*)() const) &AppDef_TheLeastSquares::IsDone, "returns True if all has been correctly done.");
cls_AppDef_TheLeastSquares.def("BezierValue", (AppParCurves_MultiCurve (AppDef_TheLeastSquares::*)()) &AppDef_TheLeastSquares::BezierValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_TheLeastSquares.def("BSplineValue", (const AppParCurves_MultiBSpCurve & (AppDef_TheLeastSquares::*)()) &AppDef_TheLeastSquares::BSplineValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_TheLeastSquares.def("FunctionMatrix", (const math_Matrix & (AppDef_TheLeastSquares::*)() const) &AppDef_TheLeastSquares::FunctionMatrix, "returns the function matrix used to approximate the set.");
cls_AppDef_TheLeastSquares.def("DerivativeFunctionMatrix", (const math_Matrix & (AppDef_TheLeastSquares::*)() const) &AppDef_TheLeastSquares::DerivativeFunctionMatrix, "returns the derivative function matrix used to approximate the set.");
cls_AppDef_TheLeastSquares.def("ErrorGradient", [](AppDef_TheLeastSquares &self, math_Vector & Grad, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.ErrorGradient(Grad, F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances. Grad is the derivative vector of the function F.", py::arg("Grad"), py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_TheLeastSquares.def("Distance", (const math_Matrix & (AppDef_TheLeastSquares::*)()) &AppDef_TheLeastSquares::Distance, "returns the distances between the points of the multiline and the approximation curves.");
cls_AppDef_TheLeastSquares.def("Error", [](AppDef_TheLeastSquares &self, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.Error(F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances.", py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_TheLeastSquares.def("FirstLambda", (Standard_Real (AppDef_TheLeastSquares::*)() const) &AppDef_TheLeastSquares::FirstLambda, "returns the value (P2 - P1)/ V1 if the first point was a tangency point.");
cls_AppDef_TheLeastSquares.def("LastLambda", (Standard_Real (AppDef_TheLeastSquares::*)() const) &AppDef_TheLeastSquares::LastLambda, "returns the value (PN - PN-1)/ VN if the last point was a tangency point.");
cls_AppDef_TheLeastSquares.def("Points", (const math_Matrix & (AppDef_TheLeastSquares::*)() const) &AppDef_TheLeastSquares::Points, "returns the matrix of points value.");
cls_AppDef_TheLeastSquares.def("Poles", (const math_Matrix & (AppDef_TheLeastSquares::*)() const) &AppDef_TheLeastSquares::Poles, "returns the matrix of resulting control points value.");
cls_AppDef_TheLeastSquares.def("KIndex", (const math_IntegerVector & (AppDef_TheLeastSquares::*)() const) &AppDef_TheLeastSquares::KIndex, "Returns the indexes of the first non null values of A and DA. The values are non null from Index(ieme point) +1 to Index(ieme point) + degree +1.");

// CLASS: APPDEF_THEFUNCTION
py::class_<AppDef_TheFunction, math_MultipleVarFunctionWithGradient> cls_AppDef_TheFunction(mod, "AppDef_TheFunction", "None");

// Constructors
cls_AppDef_TheFunction.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"));

// Methods
// cls_AppDef_TheFunction.def_static("operator new_", (void * (*)(size_t)) &AppDef_TheFunction::operator new, "None", py::arg("theSize"));
// cls_AppDef_TheFunction.def_static("operator delete_", (void (*)(void *)) &AppDef_TheFunction::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_TheFunction.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_TheFunction::operator new[], "None", py::arg("theSize"));
// cls_AppDef_TheFunction.def_static("operator delete[]_", (void (*)(void *)) &AppDef_TheFunction::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_TheFunction.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_TheFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_TheFunction.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_TheFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_TheFunction.def("NbVariables", (Standard_Integer (AppDef_TheFunction::*)() const) &AppDef_TheFunction::NbVariables, "returns the number of variables of the function. It corresponds to the number of MultiPoints.");
cls_AppDef_TheFunction.def("Value", [](AppDef_TheFunction &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "this method computes the new approximation of the MultiLine SSP and calculates F = sum (||Pui - Bi*Pi||2) for each point of the MultiLine.", py::arg("X"), py::arg("F"));
cls_AppDef_TheFunction.def("Gradient", (Standard_Boolean (AppDef_TheFunction::*)(const math_Vector &, math_Vector &)) &AppDef_TheFunction::Gradient, "returns the gradient G of the sum above for the parameters Xi.", py::arg("X"), py::arg("G"));
cls_AppDef_TheFunction.def("Values", [](AppDef_TheFunction &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "returns the value F=sum(||Pui - Bi*Pi||)2. returns the value G = grad(F) for the parameters Xi.", py::arg("X"), py::arg("F"), py::arg("G"));
cls_AppDef_TheFunction.def("NewParameters", (const math_Vector & (AppDef_TheFunction::*)() const) &AppDef_TheFunction::NewParameters, "returns the new parameters of the MultiLine.");
cls_AppDef_TheFunction.def("CurveValue", (const AppParCurves_MultiCurve & (AppDef_TheFunction::*)()) &AppDef_TheFunction::CurveValue, "returns the MultiCurve approximating the set after computing the value F or Grad(F).");
cls_AppDef_TheFunction.def("Error", (Standard_Real (AppDef_TheFunction::*)(const Standard_Integer, const Standard_Integer) const) &AppDef_TheFunction::Error, "returns the distance between the MultiPoint of range IPoint and the curve CurveIndex.", py::arg("IPoint"), py::arg("CurveIndex"));
cls_AppDef_TheFunction.def("MaxError3d", (Standard_Real (AppDef_TheFunction::*)() const) &AppDef_TheFunction::MaxError3d, "returns the maximum distance between the points and the MultiCurve.");
cls_AppDef_TheFunction.def("MaxError2d", (Standard_Real (AppDef_TheFunction::*)() const) &AppDef_TheFunction::MaxError2d, "returns the maximum distance between the points and the MultiCurve.");
cls_AppDef_TheFunction.def("FirstConstraint", (AppParCurves_Constraint (AppDef_TheFunction::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_TheFunction::FirstConstraint, "None", py::arg("TheConstraints"), py::arg("FirstPoint"));
cls_AppDef_TheFunction.def("LastConstraint", (AppParCurves_Constraint (AppDef_TheFunction::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_TheFunction::LastConstraint, "None", py::arg("TheConstraints"), py::arg("LastPoint"));

// CLASS: APPDEF_THEGRADIENT
py::class_<AppDef_TheGradient> cls_AppDef_TheGradient(mod, "AppDef_TheGradient", "None");

// Constructors
cls_AppDef_TheGradient.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"));
cls_AppDef_TheGradient.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIterations"));

// Methods
// cls_AppDef_TheGradient.def_static("operator new_", (void * (*)(size_t)) &AppDef_TheGradient::operator new, "None", py::arg("theSize"));
// cls_AppDef_TheGradient.def_static("operator delete_", (void (*)(void *)) &AppDef_TheGradient::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_TheGradient.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_TheGradient::operator new[], "None", py::arg("theSize"));
// cls_AppDef_TheGradient.def_static("operator delete[]_", (void (*)(void *)) &AppDef_TheGradient::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_TheGradient.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_TheGradient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_TheGradient.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_TheGradient::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_TheGradient.def("IsDone", (Standard_Boolean (AppDef_TheGradient::*)() const) &AppDef_TheGradient::IsDone, "returns True if all has been correctly done.");
cls_AppDef_TheGradient.def("Value", (AppParCurves_MultiCurve (AppDef_TheGradient::*)() const) &AppDef_TheGradient::Value, "returns all the Bezier curves approximating the MultiLine SSP after minimization of the parameter.");
cls_AppDef_TheGradient.def("Error", (Standard_Real (AppDef_TheGradient::*)(const Standard_Integer) const) &AppDef_TheGradient::Error, "returns the difference between the old and the new approximation. An exception is raised if NotDone. An exception is raised if Index<1 or Index>NbParameters.", py::arg("Index"));
cls_AppDef_TheGradient.def("MaxError3d", (Standard_Real (AppDef_TheGradient::*)() const) &AppDef_TheGradient::MaxError3d, "returns the maximum difference between the old and the new approximation.");
cls_AppDef_TheGradient.def("MaxError2d", (Standard_Real (AppDef_TheGradient::*)() const) &AppDef_TheGradient::MaxError2d, "returns the maximum difference between the old and the new approximation.");
cls_AppDef_TheGradient.def("AverageError", (Standard_Real (AppDef_TheGradient::*)() const) &AppDef_TheGradient::AverageError, "returns the average error between the old and the new approximation.");

// CLASS: APPDEF_THERESOL
py::class_<AppDef_TheResol> cls_AppDef_TheResol(mod, "AppDef_TheResol", "None");

// Constructors
cls_AppDef_TheResol.def(py::init<const AppDef_MultiLine &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"));
cls_AppDef_TheResol.def(py::init<const AppDef_MultiLine &, AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Matrix &, const math_Matrix &, const Standard_Real>(), py::arg("SSP"), py::arg("SCurv"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("Constraints"), py::arg("Bern"), py::arg("DerivativeBern"), py::arg("Tolerance"));

// Methods
// cls_AppDef_TheResol.def_static("operator new_", (void * (*)(size_t)) &AppDef_TheResol::operator new, "None", py::arg("theSize"));
// cls_AppDef_TheResol.def_static("operator delete_", (void (*)(void *)) &AppDef_TheResol::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_TheResol.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_TheResol::operator new[], "None", py::arg("theSize"));
// cls_AppDef_TheResol.def_static("operator delete[]_", (void (*)(void *)) &AppDef_TheResol::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_TheResol.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_TheResol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_TheResol.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_TheResol::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_TheResol.def("IsDone", (Standard_Boolean (AppDef_TheResol::*)() const) &AppDef_TheResol::IsDone, "returns True if all has been correctly done.");
// cls_AppDef_TheResol.def("Error", (Standard_Real (AppDef_TheResol::*)() const) &AppDef_TheResol::Error, "returns the maximum difference value between the curve and the given points.");
cls_AppDef_TheResol.def("ConstraintMatrix", (const math_Matrix & (AppDef_TheResol::*)() const) &AppDef_TheResol::ConstraintMatrix, "None");
cls_AppDef_TheResol.def("Duale", (const math_Vector & (AppDef_TheResol::*)() const) &AppDef_TheResol::Duale, "returns the duale variables of the system.");
cls_AppDef_TheResol.def("ConstraintDerivative", (const math_Matrix & (AppDef_TheResol::*)(const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const math_Matrix &)) &AppDef_TheResol::ConstraintDerivative, "Returns the derivative of the constraint matrix.", py::arg("SSP"), py::arg("Parameters"), py::arg("Deg"), py::arg("DA"));
cls_AppDef_TheResol.def("InverseMatrix", (const math_Matrix & (AppDef_TheResol::*)() const) &AppDef_TheResol::InverseMatrix, "returns the Inverse of Cont*Transposed(Cont), where Cont is the constraint matrix for the algorithm.");

// CLASS: APPDEF_VARIATIONAL
py::class_<AppDef_Variational> cls_AppDef_Variational(mod, "AppDef_Variational", "This class is used to smooth N points with constraints by minimization of quadratic criterium but also variational criterium in order to obtain ' fair Curve ' Computes the approximation of a Multiline by Variational optimization.");

// Constructors
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"), py::arg("Continuity"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Boolean>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"), py::arg("Continuity"), py::arg("WithMinMax"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Boolean, const Standard_Boolean>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"), py::arg("Continuity"), py::arg("WithMinMax"), py::arg("WithCutting"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Boolean, const Standard_Boolean, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"), py::arg("Continuity"), py::arg("WithMinMax"), py::arg("WithCutting"), py::arg("Tolerance"));
cls_AppDef_Variational.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("MaxDegree"), py::arg("MaxSegment"), py::arg("Continuity"), py::arg("WithMinMax"), py::arg("WithCutting"), py::arg("Tolerance"), py::arg("NbIterations"));

// Methods
// cls_AppDef_Variational.def_static("operator new_", (void * (*)(size_t)) &AppDef_Variational::operator new, "None", py::arg("theSize"));
// cls_AppDef_Variational.def_static("operator delete_", (void (*)(void *)) &AppDef_Variational::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_Variational.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_Variational::operator new[], "None", py::arg("theSize"));
// cls_AppDef_Variational.def_static("operator delete[]_", (void (*)(void *)) &AppDef_Variational::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_Variational.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_Variational::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_Variational.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_Variational::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_Variational.def("Approximate", (void (AppDef_Variational::*)()) &AppDef_Variational::Approximate, "Makes the approximation with the current fields.");
cls_AppDef_Variational.def("IsCreated", (Standard_Boolean (AppDef_Variational::*)() const) &AppDef_Variational::IsCreated, "returns True if the creation is done and correspond to the current fields.");
cls_AppDef_Variational.def("IsDone", (Standard_Boolean (AppDef_Variational::*)() const) &AppDef_Variational::IsDone, "returns True if the approximation is ok and correspond to the current fields.");
cls_AppDef_Variational.def("IsOverConstrained", (Standard_Boolean (AppDef_Variational::*)() const) &AppDef_Variational::IsOverConstrained, "returns True if the problem is overconstrained in this case, approximation cannot be done.");
cls_AppDef_Variational.def("Value", (AppParCurves_MultiBSpCurve (AppDef_Variational::*)() const) &AppDef_Variational::Value, "returns all the BSpline curves approximating the MultiLine from AppDef SSP after minimization of the parameter.");
cls_AppDef_Variational.def("MaxError", (Standard_Real (AppDef_Variational::*)() const) &AppDef_Variational::MaxError, "returns the maximum of the distances between the points of the multiline and the approximation curves.");
cls_AppDef_Variational.def("MaxErrorIndex", (Standard_Integer (AppDef_Variational::*)() const) &AppDef_Variational::MaxErrorIndex, "returns the index of the MultiPoint of ErrorMax");
cls_AppDef_Variational.def("QuadraticError", (Standard_Real (AppDef_Variational::*)() const) &AppDef_Variational::QuadraticError, "returns the quadratic average of the distances between the points of the multiline and the approximation curves.");
cls_AppDef_Variational.def("Distance", (void (AppDef_Variational::*)(math_Matrix &)) &AppDef_Variational::Distance, "returns the distances between the points of the multiline and the approximation curves.", py::arg("mat"));
cls_AppDef_Variational.def("AverageError", (Standard_Real (AppDef_Variational::*)() const) &AppDef_Variational::AverageError, "returns the average error between the MultiLine from AppDef and the approximation.");
cls_AppDef_Variational.def("Parameters", (const opencascade::handle<TColStd_HArray1OfReal> & (AppDef_Variational::*)() const) &AppDef_Variational::Parameters, "returns the parameters uses to the approximations");
cls_AppDef_Variational.def("Knots", (const opencascade::handle<TColStd_HArray1OfReal> & (AppDef_Variational::*)() const) &AppDef_Variational::Knots, "returns the knots uses to the approximations");
cls_AppDef_Variational.def("Criterium", [](AppDef_Variational &self, Standard_Real & VFirstOrder, Standard_Real & VSecondOrder, Standard_Real & VThirdOrder){ self.Criterium(VFirstOrder, VSecondOrder, VThirdOrder); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(VFirstOrder, VSecondOrder, VThirdOrder); }, "returns the values of the quality criterium.", py::arg("VFirstOrder"), py::arg("VSecondOrder"), py::arg("VThirdOrder"));
cls_AppDef_Variational.def("CriteriumWeight", [](AppDef_Variational &self, Standard_Real & Percent1, Standard_Real & Percent2, Standard_Real & Percent3){ self.CriteriumWeight(Percent1, Percent2, Percent3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Percent1, Percent2, Percent3); }, "returns the Weights (as percent) associed to the criterium used in the optimization.", py::arg("Percent1"), py::arg("Percent2"), py::arg("Percent3"));
cls_AppDef_Variational.def("MaxDegree", (Standard_Integer (AppDef_Variational::*)() const) &AppDef_Variational::MaxDegree, "returns the Maximum Degree used in the approximation");
cls_AppDef_Variational.def("MaxSegment", (Standard_Integer (AppDef_Variational::*)() const) &AppDef_Variational::MaxSegment, "returns the Maximum of segment used in the approximation");
cls_AppDef_Variational.def("Continuity", (GeomAbs_Shape (AppDef_Variational::*)() const) &AppDef_Variational::Continuity, "returns the Continuity used in the approximation");
cls_AppDef_Variational.def("WithMinMax", (Standard_Boolean (AppDef_Variational::*)() const) &AppDef_Variational::WithMinMax, "returns if the approximation search to minimize the maximum Error or not.");
cls_AppDef_Variational.def("WithCutting", (Standard_Boolean (AppDef_Variational::*)() const) &AppDef_Variational::WithCutting, "returns if the approximation can insert new Knots or not.");
cls_AppDef_Variational.def("Tolerance", (Standard_Real (AppDef_Variational::*)() const) &AppDef_Variational::Tolerance, "returns the tolerance used in the approximation.");
cls_AppDef_Variational.def("NbIterations", (Standard_Integer (AppDef_Variational::*)() const) &AppDef_Variational::NbIterations, "returns the number of iterations used in the approximation.");
cls_AppDef_Variational.def("Dump", (void (AppDef_Variational::*)(Standard_OStream &) const) &AppDef_Variational::Dump, "Prints on the stream o information on the current state of the object. MaxError,MaxErrorIndex,AverageError,QuadraticError,Criterium Distances,Degre,Nombre de poles, parametres, noeuds", py::arg("o"));
cls_AppDef_Variational.def("SetConstraints", (Standard_Boolean (AppDef_Variational::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &)) &AppDef_Variational::SetConstraints, "Define the constraints to approximate If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("aConstrainst"));
cls_AppDef_Variational.def("SetParameters", (void (AppDef_Variational::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &AppDef_Variational::SetParameters, "Defines the parameters used by the approximations.", py::arg("param"));
cls_AppDef_Variational.def("SetKnots", (Standard_Boolean (AppDef_Variational::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &AppDef_Variational::SetKnots, "Defines the knots used by the approximations If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("knots"));
cls_AppDef_Variational.def("SetMaxDegree", (Standard_Boolean (AppDef_Variational::*)(const Standard_Integer)) &AppDef_Variational::SetMaxDegree, "Define the Maximum Degree used in the approximation If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("Degree"));
cls_AppDef_Variational.def("SetMaxSegment", (Standard_Boolean (AppDef_Variational::*)(const Standard_Integer)) &AppDef_Variational::SetMaxSegment, "Define the maximum number of segments used in the approximation If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("NbSegment"));
cls_AppDef_Variational.def("SetContinuity", (Standard_Boolean (AppDef_Variational::*)(const GeomAbs_Shape)) &AppDef_Variational::SetContinuity, "Define the Continuity used in the approximation If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("C"));
cls_AppDef_Variational.def("SetWithMinMax", (void (AppDef_Variational::*)(const Standard_Boolean)) &AppDef_Variational::SetWithMinMax, "Define if the approximation search to minimize the maximum Error or not.", py::arg("MinMax"));
cls_AppDef_Variational.def("SetWithCutting", (Standard_Boolean (AppDef_Variational::*)(const Standard_Boolean)) &AppDef_Variational::SetWithCutting, "Define if the approximation can insert new Knots or not. If this value is incompatible with the others fields this method modify nothing and returns false", py::arg("Cutting"));
cls_AppDef_Variational.def("SetCriteriumWeight", (void (AppDef_Variational::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &AppDef_Variational::SetCriteriumWeight, "define the Weights (as percent) associed to the criterium used in the optimization.", py::arg("Percent1"), py::arg("Percent2"), py::arg("Percent3"));
cls_AppDef_Variational.def("SetCriteriumWeight", (void (AppDef_Variational::*)(const Standard_Integer, const Standard_Real)) &AppDef_Variational::SetCriteriumWeight, "define the Weight (as percent) associed to the criterium Order used in the optimization : Others weights are updated. if Percent < 0 if Order < 1 or Order > 3", py::arg("Order"), py::arg("Percent"));
cls_AppDef_Variational.def("SetTolerance", (void (AppDef_Variational::*)(const Standard_Real)) &AppDef_Variational::SetTolerance, "define the tolerance used in the approximation.", py::arg("Tol"));
cls_AppDef_Variational.def("SetNbIterations", (void (AppDef_Variational::*)(const Standard_Integer)) &AppDef_Variational::SetNbIterations, "define the number of iterations used in the approximation. if Iter < 1", py::arg("Iter"));


}
