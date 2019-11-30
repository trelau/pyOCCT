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
#include <Extrema_ExtFlag.hxx>
#include <Extrema_ExtAlgo.hxx>
#include <Extrema_ElementType.hxx>
#include <Standard.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv.hxx>
#include <math_Vector.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_ECC.hxx>
#include <gp_Pnt.hxx>
#include <NCollection_Sequence.hxx>
#include <Extrema_SequenceOfPOnCurv.hxx>
#include <Extrema_ExtElC.hxx>
#include <Extrema_ExtCC.hxx>
#include <NCollection_Array1.hxx>
#include <Extrema_Array1OfPOnCurv.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Std.hxx>
#include <Extrema_HArray1OfPOnCurv.hxx>
#include <Standard_Type.hxx>
#include <Extrema_POnSurf.hxx>
#include <Extrema_Array1OfPOnSurf.hxx>
#include <Extrema_HArray1OfPOnSurf.hxx>
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <gp_Circ.hxx>
#include <gp_Hypr.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Extrema_ExtElCS.hxx>
#include <Extrema_SequenceOfPOnSurf.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <Extrema_ExtCS.hxx>
#include <Extrema_ExtElSS.hxx>
#include <Extrema_ExtSS.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <Extrema_ExtPElC.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Extrema_PCFOfEPCOfExtPC.hxx>
#include <Extrema_EPCOfExtPC.hxx>
#include <GeomAbs_CurveType.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <Extrema_ExtPC.hxx>
#include <Extrema_ExtPElS.hxx>
#include <Extrema_POnSurfParams.hxx>
#include <NCollection_Array2.hxx>
#include <Extrema_Array2OfPOnSurfParams.hxx>
#include <Extrema_HArray2OfPOnSurfParams.hxx>
#include <NCollection_UBTree.hxx>
#include <Bnd_Sphere.hxx>
#include <Extrema_HUBTreeOfSphere.hxx>
#include <NCollection_UBTreeFiller.hxx>
#include <NCollection_Handle.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <math_Matrix.hxx>
#include <Extrema_FuncPSNorm.hxx>
#include <Bnd_HArray1OfSphere.hxx>
#include <Extrema_GenExtPS.hxx>
#include <Extrema_ExtPExtS.hxx>
#include <Extrema_ExtPRevS.hxx>
#include <Extrema_ExtPS.hxx>
#include <Extrema_PCLocFOfLocEPCOfLocateExtPC.hxx>
#include <Extrema_LocEPCOfLocateExtPC.hxx>
#include <Extrema_PCFOfEPCOfELPCOfLocateExtPC.hxx>
#include <Extrema_EPCOfELPCOfLocateExtPC.hxx>
#include <Extrema_ELPCOfLocateExtPC.hxx>
#include <Extrema_LocateExtPC.hxx>
#include <Extrema_LocateExtCC.hxx>
#include <gp_Pnt2d.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <Extrema_Array1OfPOnCurv2d.hxx>
#include <Extrema_Array2OfPOnCurv.hxx>
#include <Extrema_Array2OfPOnCurv2d.hxx>
#include <Extrema_Array2OfPOnSurf.hxx>
#include <gp_Vec.hxx>
#include <Extrema_CCLocFOfLocECC.hxx>
#include <Extrema_SequenceOfPOnCurv2d.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <gp_Vec2d.hxx>
#include <Extrema_CCLocFOfLocECC2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Extrema_Curve2dTool.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Extrema_CurveTool.hxx>
#include <Extrema_ECC2d.hxx>
#include <Extrema_ExtPElC2d.hxx>
#include <Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.hxx>
#include <Extrema_EPCOfELPCOfLocateExtPC2d.hxx>
#include <Extrema_ELPCOfLocateExtPC2d.hxx>
#include <Extrema_PCFOfEPCOfExtPC2d.hxx>
#include <Extrema_EPCOfExtPC2d.hxx>
#include <Extrema_ExtElC2d.hxx>
#include <Extrema_ExtCC2d.hxx>
#include <Extrema_ExtPC2d.hxx>
#include <GeomAdaptor_HSurfaceOfLinearExtrusion.hxx>
#include <gp_Ax2.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <GeomAdaptor_HSurfaceOfRevolution.hxx>
#include <Adaptor3d_CurvePtr.hxx>
#include <Extrema_FuncExtCS.hxx>
#include <Extrema_FuncExtSS.hxx>
#include <math_MultipleVarFunctionWithGradient.hxx>
#include <Extrema_FuncPSDist.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <Extrema_GenExtCS.hxx>
#include <Extrema_GenExtSS.hxx>
#include <Extrema_GenLocateExtCS.hxx>
#include <Precision.hxx>
#include <Extrema_GenLocateExtPS.hxx>
#include <Extrema_GenLocateExtSS.hxx>
#include <math_MultipleVarFunction.hxx>
#include <Extrema_GlobOptFuncCC.hxx>
#include <math_MultipleVarFunctionWithHessian.hxx>
#include <Extrema_GlobOptFuncCS.hxx>
#include <Extrema_HArray1OfPOnCurv2d.hxx>
#include <Extrema_HArray2OfPOnCurv.hxx>
#include <Extrema_HArray2OfPOnCurv2d.hxx>
#include <Extrema_HArray2OfPOnSurf.hxx>
#include <Extrema_LocateExtCC2d.hxx>
#include <Extrema_PCLocFOfLocEPCOfLocateExtPC2d.hxx>
#include <Extrema_LocEPCOfLocateExtPC2d.hxx>
#include <Extrema_LocateExtPC2d.hxx>
#include <Extrema_LocECC.hxx>
#include <Extrema_LocECC2d.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Array2.hxx>
#include <bind_NCollection_UBTree.hxx>
#include <bind_NCollection_UBTreeFiller.hxx>
#include <bind_NCollection_Handle.hxx>

PYBIND11_MODULE(Extrema, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.math");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Precision");

// ENUM: EXTREMA_EXTFLAG
py::enum_<Extrema_ExtFlag>(mod, "Extrema_ExtFlag", "None")
	.value("Extrema_ExtFlag_MIN", Extrema_ExtFlag::Extrema_ExtFlag_MIN)
	.value("Extrema_ExtFlag_MAX", Extrema_ExtFlag::Extrema_ExtFlag_MAX)
	.value("Extrema_ExtFlag_MINMAX", Extrema_ExtFlag::Extrema_ExtFlag_MINMAX)
	.export_values();


// ENUM: EXTREMA_EXTALGO
py::enum_<Extrema_ExtAlgo>(mod, "Extrema_ExtAlgo", "None")
	.value("Extrema_ExtAlgo_Grad", Extrema_ExtAlgo::Extrema_ExtAlgo_Grad)
	.value("Extrema_ExtAlgo_Tree", Extrema_ExtAlgo::Extrema_ExtAlgo_Tree)
	.export_values();


// ENUM: EXTREMA_ELEMENTTYPE
py::enum_<Extrema_ElementType>(mod, "Extrema_ElementType", "None")
	.value("Extrema_Node", Extrema_ElementType::Extrema_Node)
	.value("Extrema_UIsoEdge", Extrema_ElementType::Extrema_UIsoEdge)
	.value("Extrema_VIsoEdge", Extrema_ElementType::Extrema_VIsoEdge)
	.value("Extrema_Face", Extrema_ElementType::Extrema_Face)
	.export_values();


// CLASS: EXTREMA_ECC
py::class_<Extrema_ECC> cls_Extrema_ECC(mod, "Extrema_ECC", "None");

// Constructors
cls_Extrema_ECC.def(py::init<>());
cls_Extrema_ECC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ECC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"));

// Methods
// cls_Extrema_ECC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ECC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ECC.def_static("operator delete_", (void (*)(void *)) &Extrema_ECC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ECC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ECC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ECC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ECC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ECC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ECC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ECC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ECC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ECC.def("SetParams", (void (Extrema_ECC::*)(const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ECC::SetParams, "Set params in case of empty constructor is usage.", py::arg("C1"), py::arg("C2"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"));
cls_Extrema_ECC.def("SetTolerance", (void (Extrema_ECC::*)(const Standard_Real)) &Extrema_ECC::SetTolerance, "None", py::arg("Tol"));
cls_Extrema_ECC.def("SetSingleSolutionFlag", (void (Extrema_ECC::*)(const Standard_Boolean)) &Extrema_ECC::SetSingleSolutionFlag, "Set flag for single extrema computation. Works on parametric solver only.", py::arg("theSingleSolutionFlag"));
cls_Extrema_ECC.def("GetSingleSolutionFlag", (Standard_Boolean (Extrema_ECC::*)() const) &Extrema_ECC::GetSingleSolutionFlag, "Get flag for single extrema computation. Works on parametric solver only.");
cls_Extrema_ECC.def("Perform", (void (Extrema_ECC::*)()) &Extrema_ECC::Perform, "Performs calculations.");
cls_Extrema_ECC.def("IsDone", (Standard_Boolean (Extrema_ECC::*)() const) &Extrema_ECC::IsDone, "Returns True if the distances are found.");
cls_Extrema_ECC.def("IsParallel", (Standard_Boolean (Extrema_ECC::*)() const) &Extrema_ECC::IsParallel, "Returns state of myParallel flag.");
cls_Extrema_ECC.def("NbExt", (Standard_Integer (Extrema_ECC::*)() const) &Extrema_ECC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ECC.def("SquareDistance", [](Extrema_ECC &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ECC.def("SquareDistance", (Standard_Real (Extrema_ECC::*)(const Standard_Integer) const) &Extrema_ECC::SquareDistance, "Returns the value of the Nth square extremum distance.", py::arg("N"));
cls_Extrema_ECC.def("Points", (void (Extrema_ECC::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_ECC::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_PONCURV
py::class_<Extrema_POnCurv> cls_Extrema_POnCurv(mod, "Extrema_POnCurv", "None");

// Constructors
cls_Extrema_POnCurv.def(py::init<>());
cls_Extrema_POnCurv.def(py::init<const Standard_Real, const gp_Pnt &>(), py::arg("U"), py::arg("P"));

// Methods
// cls_Extrema_POnCurv.def_static("operator new_", (void * (*)(size_t)) &Extrema_POnCurv::operator new, "None", py::arg("theSize"));
// cls_Extrema_POnCurv.def_static("operator delete_", (void (*)(void *)) &Extrema_POnCurv::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_POnCurv.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_POnCurv::operator new[], "None", py::arg("theSize"));
// cls_Extrema_POnCurv.def_static("operator delete[]_", (void (*)(void *)) &Extrema_POnCurv::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_POnCurv.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_POnCurv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_POnCurv.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_POnCurv::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_POnCurv.def("SetValues", (void (Extrema_POnCurv::*)(const Standard_Real, const gp_Pnt &)) &Extrema_POnCurv::SetValues, "sets the point and parameter values.", py::arg("U"), py::arg("P"));
cls_Extrema_POnCurv.def("Value", (const gp_Pnt & (Extrema_POnCurv::*)() const) &Extrema_POnCurv::Value, "Returns the point.");
cls_Extrema_POnCurv.def("Parameter", (Standard_Real (Extrema_POnCurv::*)() const) &Extrema_POnCurv::Parameter, "Returns the parameter on the curve.");

// TYPEDEF: EXTREMA_SEQUENCEOFPONCURV
bind_NCollection_Sequence<Extrema_POnCurv>(mod, "Extrema_SequenceOfPOnCurv", py::module_local(false));

// CLASS: EXTREMA_EXTCC
py::class_<Extrema_ExtCC> cls_Extrema_ExtCC(mod, "Extrema_ExtCC", "It calculates all the distance between two curves. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtCC.def(py::init<>());
cls_Extrema_ExtCC.def(py::init<const Standard_Real>(), py::arg("TolC1"));
cls_Extrema_ExtCC.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("TolC1"), py::arg("TolC2"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolC1"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolC1"), py::arg("TolC2"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("TolC1"));
cls_Extrema_ExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("TolC1"), py::arg("TolC2"));

// Methods
// cls_Extrema_ExtCC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtCC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtCC.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtCC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtCC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtCC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtCC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtCC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtCC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtCC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtCC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtCC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtCC.def("SetCurve", (void (Extrema_ExtCC::*)(const Standard_Integer, const Adaptor3d_Curve &)) &Extrema_ExtCC::SetCurve, "None", py::arg("theRank"), py::arg("C"));
cls_Extrema_ExtCC.def("SetCurve", (void (Extrema_ExtCC::*)(const Standard_Integer, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &Extrema_ExtCC::SetCurve, "None", py::arg("theRank"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtCC.def("SetRange", (void (Extrema_ExtCC::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &Extrema_ExtCC::SetRange, "None", py::arg("theRank"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtCC.def("SetTolerance", (void (Extrema_ExtCC::*)(const Standard_Integer, const Standard_Real)) &Extrema_ExtCC::SetTolerance, "None", py::arg("theRank"), py::arg("Tol"));
cls_Extrema_ExtCC.def("Perform", (void (Extrema_ExtCC::*)()) &Extrema_ExtCC::Perform, "None");
cls_Extrema_ExtCC.def("IsDone", (Standard_Boolean (Extrema_ExtCC::*)() const) &Extrema_ExtCC::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtCC.def("NbExt", (Standard_Integer (Extrema_ExtCC::*)() const) &Extrema_ExtCC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtCC.def("IsParallel", (Standard_Boolean (Extrema_ExtCC::*)() const) &Extrema_ExtCC::IsParallel, "Returns True if the two curves are parallel.");
cls_Extrema_ExtCC.def("SquareDistance", [](Extrema_ExtCC &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtCC.def("SquareDistance", (Standard_Real (Extrema_ExtCC::*)(const Standard_Integer) const) &Extrema_ExtCC::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtCC.def("Points", (void (Extrema_ExtCC::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_ExtCC::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));
cls_Extrema_ExtCC.def("TrimmedSquareDistances", [](Extrema_ExtCC &self, Standard_Real & dist11, Standard_Real & distP12, Standard_Real & distP21, Standard_Real & distP22, gp_Pnt & P11, gp_Pnt & P12, gp_Pnt & P21, gp_Pnt & P22){ self.TrimmedSquareDistances(dist11, distP12, distP21, distP22, P11, P12, P21, P22); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(dist11, distP12, distP21, distP22); }, "if the curve is a trimmed curve, dist11 is a square distance between the point on C1 of parameter FirstParameter and the point of parameter FirstParameter on C2.", py::arg("dist11"), py::arg("distP12"), py::arg("distP21"), py::arg("distP22"), py::arg("P11"), py::arg("P12"), py::arg("P21"), py::arg("P22"));
cls_Extrema_ExtCC.def("SetSingleSolutionFlag", (void (Extrema_ExtCC::*)(const Standard_Boolean)) &Extrema_ExtCC::SetSingleSolutionFlag, "Set flag for single extrema computation. Works on parametric solver only.", py::arg("theSingleSolutionFlag"));
cls_Extrema_ExtCC.def("GetSingleSolutionFlag", (Standard_Boolean (Extrema_ExtCC::*)() const) &Extrema_ExtCC::GetSingleSolutionFlag, "Get flag for single extrema computation. Works on parametric solver only.");

// TYPEDEF: EXTREMA_ARRAY1OFPONCURV
bind_NCollection_Array1<Extrema_POnCurv>(mod, "Extrema_Array1OfPOnCurv", py::module_local(false));

// CLASS: EXTREMA_HARRAY1OFPONCURV
py::class_<Extrema_HArray1OfPOnCurv, opencascade::handle<Extrema_HArray1OfPOnCurv>, Standard_Transient> cls_Extrema_HArray1OfPOnCurv(mod, "Extrema_HArray1OfPOnCurv", "None", py::multiple_inheritance());

// Constructors
cls_Extrema_HArray1OfPOnCurv.def(py::init<>());
cls_Extrema_HArray1OfPOnCurv.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Extrema_HArray1OfPOnCurv.def(py::init<const Standard_Integer, const Standard_Integer, const Extrema_Array1OfPOnCurv::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Extrema_HArray1OfPOnCurv.def(py::init<const Extrema_Array1OfPOnCurv &>(), py::arg("theOther"));

// Methods
// cls_Extrema_HArray1OfPOnCurv.def_static("operator new_", (void * (*)(size_t)) &Extrema_HArray1OfPOnCurv::operator new, "None", py::arg("theSize"));
// cls_Extrema_HArray1OfPOnCurv.def_static("operator delete_", (void (*)(void *)) &Extrema_HArray1OfPOnCurv::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnCurv.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_HArray1OfPOnCurv::operator new[], "None", py::arg("theSize"));
// cls_Extrema_HArray1OfPOnCurv.def_static("operator delete[]_", (void (*)(void *)) &Extrema_HArray1OfPOnCurv::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnCurv.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_HArray1OfPOnCurv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnCurv.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_HArray1OfPOnCurv::operator delete, "None", py::arg(""), py::arg(""));
// cls_Extrema_HArray1OfPOnCurv.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray1OfPOnCurv::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Extrema_HArray1OfPOnCurv.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray1OfPOnCurv::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Extrema_HArray1OfPOnCurv.def("Array1", (const Extrema_Array1OfPOnCurv & (Extrema_HArray1OfPOnCurv::*)() const) &Extrema_HArray1OfPOnCurv::Array1, "None");
cls_Extrema_HArray1OfPOnCurv.def("ChangeArray1", (Extrema_Array1OfPOnCurv & (Extrema_HArray1OfPOnCurv::*)()) &Extrema_HArray1OfPOnCurv::ChangeArray1, "None");
cls_Extrema_HArray1OfPOnCurv.def_static("get_type_name_", (const char * (*)()) &Extrema_HArray1OfPOnCurv::get_type_name, "None");
cls_Extrema_HArray1OfPOnCurv.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_HArray1OfPOnCurv::get_type_descriptor, "None");
cls_Extrema_HArray1OfPOnCurv.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_HArray1OfPOnCurv::*)() const) &Extrema_HArray1OfPOnCurv::DynamicType, "None");

// CLASS: EXTREMA_PONSURF
py::class_<Extrema_POnSurf> cls_Extrema_POnSurf(mod, "Extrema_POnSurf", "Definition of a point on surface.");

// Constructors
cls_Extrema_POnSurf.def(py::init<>());
cls_Extrema_POnSurf.def(py::init<const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("U"), py::arg("V"), py::arg("P"));

// Methods
// cls_Extrema_POnSurf.def_static("operator new_", (void * (*)(size_t)) &Extrema_POnSurf::operator new, "None", py::arg("theSize"));
// cls_Extrema_POnSurf.def_static("operator delete_", (void (*)(void *)) &Extrema_POnSurf::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_POnSurf.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_POnSurf::operator new[], "None", py::arg("theSize"));
// cls_Extrema_POnSurf.def_static("operator delete[]_", (void (*)(void *)) &Extrema_POnSurf::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_POnSurf.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_POnSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_POnSurf.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_POnSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_POnSurf.def("Value", (const gp_Pnt & (Extrema_POnSurf::*)() const) &Extrema_POnSurf::Value, "Returns the 3d point.");
cls_Extrema_POnSurf.def("SetParameters", (void (Extrema_POnSurf::*)(const Standard_Real, const Standard_Real, const gp_Pnt &)) &Extrema_POnSurf::SetParameters, "Sets the params of current POnSurf instance. (e.g. to the point to be projected).", py::arg("theU"), py::arg("theV"), py::arg("thePnt"));
cls_Extrema_POnSurf.def("Parameter", [](Extrema_POnSurf &self, Standard_Real & U, Standard_Real & V){ self.Parameter(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameter values on the surface.", py::arg("U"), py::arg("V"));

// TYPEDEF: EXTREMA_ARRAY1OFPONSURF
bind_NCollection_Array1<Extrema_POnSurf>(mod, "Extrema_Array1OfPOnSurf", py::module_local(false));

// CLASS: EXTREMA_HARRAY1OFPONSURF
py::class_<Extrema_HArray1OfPOnSurf, opencascade::handle<Extrema_HArray1OfPOnSurf>, Standard_Transient> cls_Extrema_HArray1OfPOnSurf(mod, "Extrema_HArray1OfPOnSurf", "None", py::multiple_inheritance());

// Constructors
cls_Extrema_HArray1OfPOnSurf.def(py::init<>());
cls_Extrema_HArray1OfPOnSurf.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Extrema_HArray1OfPOnSurf.def(py::init<const Standard_Integer, const Standard_Integer, const Extrema_Array1OfPOnSurf::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Extrema_HArray1OfPOnSurf.def(py::init<const Extrema_Array1OfPOnSurf &>(), py::arg("theOther"));

// Methods
// cls_Extrema_HArray1OfPOnSurf.def_static("operator new_", (void * (*)(size_t)) &Extrema_HArray1OfPOnSurf::operator new, "None", py::arg("theSize"));
// cls_Extrema_HArray1OfPOnSurf.def_static("operator delete_", (void (*)(void *)) &Extrema_HArray1OfPOnSurf::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnSurf.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_HArray1OfPOnSurf::operator new[], "None", py::arg("theSize"));
// cls_Extrema_HArray1OfPOnSurf.def_static("operator delete[]_", (void (*)(void *)) &Extrema_HArray1OfPOnSurf::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnSurf.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_HArray1OfPOnSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnSurf.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_HArray1OfPOnSurf::operator delete, "None", py::arg(""), py::arg(""));
// cls_Extrema_HArray1OfPOnSurf.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray1OfPOnSurf::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Extrema_HArray1OfPOnSurf.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray1OfPOnSurf::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Extrema_HArray1OfPOnSurf.def("Array1", (const Extrema_Array1OfPOnSurf & (Extrema_HArray1OfPOnSurf::*)() const) &Extrema_HArray1OfPOnSurf::Array1, "None");
cls_Extrema_HArray1OfPOnSurf.def("ChangeArray1", (Extrema_Array1OfPOnSurf & (Extrema_HArray1OfPOnSurf::*)()) &Extrema_HArray1OfPOnSurf::ChangeArray1, "None");
cls_Extrema_HArray1OfPOnSurf.def_static("get_type_name_", (const char * (*)()) &Extrema_HArray1OfPOnSurf::get_type_name, "None");
cls_Extrema_HArray1OfPOnSurf.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_HArray1OfPOnSurf::get_type_descriptor, "None");
cls_Extrema_HArray1OfPOnSurf.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_HArray1OfPOnSurf::*)() const) &Extrema_HArray1OfPOnSurf::DynamicType, "None");

// CLASS: EXTREMA_EXTELCS
py::class_<Extrema_ExtElCS> cls_Extrema_ExtElCS(mod, "Extrema_ExtElCS", "It calculates all the distances between a curve and a surface. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtElCS.def(py::init<>());
cls_Extrema_ExtElCS.def(py::init<const gp_Lin &, const gp_Pln &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Lin &, const gp_Cylinder &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Lin &, const gp_Cone &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Lin &, const gp_Sphere &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Lin &, const gp_Torus &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Circ &, const gp_Pln &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Circ &, const gp_Cylinder &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Circ &, const gp_Cone &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Circ &, const gp_Sphere &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Circ &, const gp_Torus &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Hypr &, const gp_Pln &>(), py::arg("C"), py::arg("S"));

// Methods
// cls_Extrema_ExtElCS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtElCS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtElCS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtElCS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtElCS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtElCS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtElCS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtElCS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtElCS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtElCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtElCS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtElCS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Lin &, const gp_Pln &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Lin &, const gp_Cylinder &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Lin &, const gp_Cone &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Lin &, const gp_Sphere &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Lin &, const gp_Torus &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Circ &, const gp_Pln &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Circ &, const gp_Cylinder &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Circ &, const gp_Cone &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Circ &, const gp_Sphere &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Circ &, const gp_Torus &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Hypr &, const gp_Pln &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("IsDone", (Standard_Boolean (Extrema_ExtElCS::*)() const) &Extrema_ExtElCS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtElCS.def("IsParallel", (Standard_Boolean (Extrema_ExtElCS::*)() const) &Extrema_ExtElCS::IsParallel, "Returns True if the curve is on a parallel surface.");
cls_Extrema_ExtElCS.def("NbExt", (Standard_Integer (Extrema_ExtElCS::*)() const) &Extrema_ExtElCS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtElCS.def("SquareDistance", [](Extrema_ExtElCS &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtElCS.def("SquareDistance", (Standard_Real (Extrema_ExtElCS::*)(const Standard_Integer) const) &Extrema_ExtElCS::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtElCS.def("Points", (void (Extrema_ExtElCS::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnSurf &) const) &Extrema_ExtElCS::Points, "Returns the points of the Nth extremum distance. P1 is on the curve, P2 on the surface.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// TYPEDEF: EXTREMA_SEQUENCEOFPONSURF
bind_NCollection_Sequence<Extrema_POnSurf>(mod, "Extrema_SequenceOfPOnSurf", py::module_local(false));

// CLASS: EXTREMA_EXTCS
py::class_<Extrema_ExtCS> cls_Extrema_ExtCS(mod, "Extrema_ExtCS", "It calculates all the extremum distances between a curve and a surface. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtCS.def(py::init<>());
cls_Extrema_ExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("TolC"), py::arg("TolS"));
cls_Extrema_ExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("UCinf"), py::arg("UCsup"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolC"), py::arg("TolS"));

// Methods
// cls_Extrema_ExtCS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtCS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtCS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtCS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtCS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtCS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtCS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtCS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtCS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtCS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtCS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtCS.def("Initialize", (void (Extrema_ExtCS::*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtCS::Initialize, "Initializes the fields of the algorithm.", py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolC"), py::arg("TolS"));
cls_Extrema_ExtCS.def("Perform", (void (Extrema_ExtCS::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &Extrema_ExtCS::Perform, "Computes the distances. An exception is raised if the fieds have not been initialized.", py::arg("C"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtCS.def("IsDone", (Standard_Boolean (Extrema_ExtCS::*)() const) &Extrema_ExtCS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtCS.def("IsParallel", (Standard_Boolean (Extrema_ExtCS::*)() const) &Extrema_ExtCS::IsParallel, "Returns True if the curve is on a parallel surface.");
cls_Extrema_ExtCS.def("NbExt", (Standard_Integer (Extrema_ExtCS::*)() const) &Extrema_ExtCS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtCS.def("SquareDistance", (Standard_Real (Extrema_ExtCS::*)(const Standard_Integer) const) &Extrema_ExtCS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtCS.def("Points", (void (Extrema_ExtCS::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnSurf &) const) &Extrema_ExtCS::Points, "Returns the point of the Nth resulting distance.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_EXTELSS
py::class_<Extrema_ExtElSS> cls_Extrema_ExtElSS(mod, "Extrema_ExtElSS", "It calculates all the distances between 2 elementary surfaces. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtElSS.def(py::init<>());
cls_Extrema_ExtElSS.def(py::init<const gp_Pln &, const gp_Pln &>(), py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def(py::init<const gp_Pln &, const gp_Sphere &>(), py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def(py::init<const gp_Sphere &, const gp_Sphere &>(), py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def(py::init<const gp_Sphere &, const gp_Cylinder &>(), py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def(py::init<const gp_Sphere &, const gp_Cone &>(), py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def(py::init<const gp_Sphere &, const gp_Torus &>(), py::arg("S1"), py::arg("S2"));

// Methods
// cls_Extrema_ExtElSS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtElSS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtElSS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtElSS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtElSS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtElSS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtElSS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtElSS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtElSS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtElSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtElSS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtElSS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Pln &, const gp_Pln &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Pln &, const gp_Sphere &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Sphere &, const gp_Sphere &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Sphere &, const gp_Cylinder &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Sphere &, const gp_Cone &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Sphere &, const gp_Torus &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("IsDone", (Standard_Boolean (Extrema_ExtElSS::*)() const) &Extrema_ExtElSS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtElSS.def("IsParallel", (Standard_Boolean (Extrema_ExtElSS::*)() const) &Extrema_ExtElSS::IsParallel, "Returns True if the two surfaces are parallel.");
cls_Extrema_ExtElSS.def("NbExt", (Standard_Integer (Extrema_ExtElSS::*)() const) &Extrema_ExtElSS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtElSS.def("SquareDistance", [](Extrema_ExtElSS &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtElSS.def("SquareDistance", (Standard_Real (Extrema_ExtElSS::*)(const Standard_Integer) const) &Extrema_ExtElSS::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtElSS.def("Points", (void (Extrema_ExtElSS::*)(const Standard_Integer, Extrema_POnSurf &, Extrema_POnSurf &) const) &Extrema_ExtElSS::Points, "Returns the points for the Nth resulting distance. P1 is on the first surface, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_EXTSS
py::class_<Extrema_ExtSS> cls_Extrema_ExtSS(mod, "Extrema_ExtSS", "It calculates all the extremum distances between two surfaces. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtSS.def(py::init<>());
cls_Extrema_ExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("TolS1"), py::arg("TolS2"));
cls_Extrema_ExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("Uinf1"), py::arg("Usup1"), py::arg("Vinf1"), py::arg("Vsup1"), py::arg("Uinf2"), py::arg("Usup2"), py::arg("Vinf2"), py::arg("Vsup2"), py::arg("TolS1"), py::arg("TolS2"));

// Methods
// cls_Extrema_ExtSS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtSS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtSS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtSS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtSS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtSS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtSS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtSS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtSS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtSS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtSS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtSS.def("Initialize", (void (Extrema_ExtSS::*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtSS::Initialize, "Initializes the fields of the algorithm.", py::arg("S2"), py::arg("Uinf2"), py::arg("Usup2"), py::arg("Vinf2"), py::arg("Vsup2"), py::arg("TolS1"));
cls_Extrema_ExtSS.def("Perform", (void (Extrema_ExtSS::*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtSS::Perform, "Computes the distances. An exception is raised if the fieds have not been initialized.", py::arg("S1"), py::arg("Uinf1"), py::arg("Usup1"), py::arg("Vinf1"), py::arg("Vsup1"), py::arg("TolS1"));
cls_Extrema_ExtSS.def("IsDone", (Standard_Boolean (Extrema_ExtSS::*)() const) &Extrema_ExtSS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtSS.def("IsParallel", (Standard_Boolean (Extrema_ExtSS::*)() const) &Extrema_ExtSS::IsParallel, "Returns True if the curve is on a parallel surface.");
cls_Extrema_ExtSS.def("NbExt", (Standard_Integer (Extrema_ExtSS::*)() const) &Extrema_ExtSS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtSS.def("SquareDistance", (Standard_Real (Extrema_ExtSS::*)(const Standard_Integer) const) &Extrema_ExtSS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtSS.def("Points", (void (Extrema_ExtSS::*)(const Standard_Integer, Extrema_POnSurf &, Extrema_POnSurf &) const) &Extrema_ExtSS::Points, "Returns the point of the Nth resulting distance.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_EXTPELC
py::class_<Extrema_ExtPElC> cls_Extrema_ExtPElC(mod, "Extrema_ExtPElC", "It calculates all the distances between a point and an elementary curve. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtPElC.def(py::init<>());
cls_Extrema_ExtPElC.def(py::init<const gp_Pnt &, const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def(py::init<const gp_Pnt &, const gp_Circ &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def(py::init<const gp_Pnt &, const gp_Elips &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def(py::init<const gp_Pnt &, const gp_Hypr &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def(py::init<const gp_Pnt &, const gp_Parab &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));

// Methods
// cls_Extrema_ExtPElC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtPElC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtPElC.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtPElC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtPElC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtPElC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtPElC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtPElC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtPElC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtPElC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtPElC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtPElC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtPElC.def("Perform", (void (Extrema_ExtPElC::*)(const gp_Pnt &, const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def("Perform", (void (Extrema_ExtPElC::*)(const gp_Pnt &, const gp_Circ &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def("Perform", (void (Extrema_ExtPElC::*)(const gp_Pnt &, const gp_Elips &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def("Perform", (void (Extrema_ExtPElC::*)(const gp_Pnt &, const gp_Hypr &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def("Perform", (void (Extrema_ExtPElC::*)(const gp_Pnt &, const gp_Parab &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def("IsDone", (Standard_Boolean (Extrema_ExtPElC::*)() const) &Extrema_ExtPElC::IsDone, "True if the distances are found.");
cls_Extrema_ExtPElC.def("NbExt", (Standard_Integer (Extrema_ExtPElC::*)() const) &Extrema_ExtPElC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPElC.def("SquareDistance", (Standard_Real (Extrema_ExtPElC::*)(const Standard_Integer) const) &Extrema_ExtPElC::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtPElC.def("IsMin", (Standard_Boolean (Extrema_ExtPElC::*)(const Standard_Integer) const) &Extrema_ExtPElC::IsMin, "Returns True if the Nth extremum distance is a minimum.", py::arg("N"));
cls_Extrema_ExtPElC.def("Point", (const Extrema_POnCurv & (Extrema_ExtPElC::*)(const Standard_Integer) const) &Extrema_ExtPElC::Point, "Returns the point of the Nth extremum distance.", py::arg("N"));

// CLASS: EXTREMA_PCFOFEPCOFEXTPC
py::class_<Extrema_PCFOfEPCOfExtPC, math_FunctionWithDerivative> cls_Extrema_PCFOfEPCOfExtPC(mod, "Extrema_PCFOfEPCOfExtPC", "None");

// Constructors
cls_Extrema_PCFOfEPCOfExtPC.def(py::init<>());
cls_Extrema_PCFOfEPCOfExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &>(), py::arg("P"), py::arg("C"));

// Methods
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_PCFOfEPCOfExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_PCFOfEPCOfExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_PCFOfEPCOfExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_PCFOfEPCOfExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_PCFOfEPCOfExtPC.def("Initialize", (void (Extrema_PCFOfEPCOfExtPC::*)(const Adaptor3d_Curve &)) &Extrema_PCFOfEPCOfExtPC::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Extrema_PCFOfEPCOfExtPC.def("SetPoint", (void (Extrema_PCFOfEPCOfExtPC::*)(const gp_Pnt &)) &Extrema_PCFOfEPCOfExtPC::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Extrema_PCFOfEPCOfExtPC.def("Value", [](Extrema_PCFOfEPCOfExtPC &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Extrema_PCFOfEPCOfExtPC.def("Derivative", [](Extrema_PCFOfEPCOfExtPC &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfExtPC.def("Values", [](Extrema_PCFOfEPCOfExtPC &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfExtPC.def("GetStateNumber", (Standard_Integer (Extrema_PCFOfEPCOfExtPC::*)()) &Extrema_PCFOfEPCOfExtPC::GetStateNumber, "Save the found extremum.");
cls_Extrema_PCFOfEPCOfExtPC.def("NbExt", (Standard_Integer (Extrema_PCFOfEPCOfExtPC::*)() const) &Extrema_PCFOfEPCOfExtPC::NbExt, "Return the nunber of found extrema.");
cls_Extrema_PCFOfEPCOfExtPC.def("SquareDistance", (Standard_Real (Extrema_PCFOfEPCOfExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC.def("IsMin", (Standard_Boolean (Extrema_PCFOfEPCOfExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC.def("Point", (const Extrema_POnCurv & (Extrema_PCFOfEPCOfExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC.def("SubIntervalInitialize", (void (Extrema_PCFOfEPCOfExtPC::*)(const Standard_Real, const Standard_Real)) &Extrema_PCFOfEPCOfExtPC::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_PCFOfEPCOfExtPC.def("SearchOfTolerance", (Standard_Real (Extrema_PCFOfEPCOfExtPC::*)()) &Extrema_PCFOfEPCOfExtPC::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// CLASS: EXTREMA_EPCOFEXTPC
py::class_<Extrema_EPCOfExtPC> cls_Extrema_EPCOfExtPC(mod, "Extrema_EPCOfExtPC", "None");

// Constructors
cls_Extrema_EPCOfExtPC.def(py::init<>());
cls_Extrema_EPCOfExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));

// Methods
// cls_Extrema_EPCOfExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_EPCOfExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_EPCOfExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_EPCOfExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_EPCOfExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_EPCOfExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_EPCOfExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_EPCOfExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_EPCOfExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_EPCOfExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_EPCOfExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_EPCOfExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_EPCOfExtPC.def("Initialize", (void (Extrema_EPCOfExtPC::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real)) &Extrema_EPCOfExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("NbU"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC.def("Initialize", (void (Extrema_EPCOfExtPC::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_EPCOfExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC.def("Initialize", (void (Extrema_EPCOfExtPC::*)(const Adaptor3d_Curve &)) &Extrema_EPCOfExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"));
cls_Extrema_EPCOfExtPC.def("Initialize", (void (Extrema_EPCOfExtPC::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_EPCOfExtPC::Initialize, "sets the fields of the algorithm.", py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC.def("Perform", (void (Extrema_EPCOfExtPC::*)(const gp_Pnt &)) &Extrema_EPCOfExtPC::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_EPCOfExtPC.def("IsDone", (Standard_Boolean (Extrema_EPCOfExtPC::*)() const) &Extrema_EPCOfExtPC::IsDone, "True if the distances are found.");
cls_Extrema_EPCOfExtPC.def("NbExt", (Standard_Integer (Extrema_EPCOfExtPC::*)() const) &Extrema_EPCOfExtPC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_EPCOfExtPC.def("SquareDistance", (Standard_Real (Extrema_EPCOfExtPC::*)(const Standard_Integer) const) &Extrema_EPCOfExtPC::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_EPCOfExtPC.def("IsMin", (Standard_Boolean (Extrema_EPCOfExtPC::*)(const Standard_Integer) const) &Extrema_EPCOfExtPC::IsMin, "Returns True if the Nth extremum distance is a minimum.", py::arg("N"));
cls_Extrema_EPCOfExtPC.def("Point", (const Extrema_POnCurv & (Extrema_EPCOfExtPC::*)(const Standard_Integer) const) &Extrema_EPCOfExtPC::Point, "Returns the point of the Nth extremum distance.", py::arg("N"));

// CLASS: EXTREMA_EXTPC
py::class_<Extrema_ExtPC> cls_Extrema_ExtPC(mod, "Extrema_ExtPC", "None");

// Constructors
cls_Extrema_ExtPC.def(py::init<>());
cls_Extrema_ExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_ExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &>(), py::arg("P"), py::arg("C"));
cls_Extrema_ExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("TolF"));

// Methods
// cls_Extrema_ExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtPC.def("Initialize", [](Extrema_ExtPC &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_Extrema_ExtPC.def("Initialize", (void (Extrema_ExtPC::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPC::Initialize, "initializes the fields of the algorithm.", py::arg("C"), py::arg("Uinf"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_ExtPC.def("Perform", (void (Extrema_ExtPC::*)(const gp_Pnt &)) &Extrema_ExtPC::Perform, "An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_ExtPC.def("IsDone", (Standard_Boolean (Extrema_ExtPC::*)() const) &Extrema_ExtPC::IsDone, "True if the distances are found.");
cls_Extrema_ExtPC.def("SquareDistance", (Standard_Real (Extrema_ExtPC::*)(const Standard_Integer) const) &Extrema_ExtPC::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
cls_Extrema_ExtPC.def("NbExt", (Standard_Integer (Extrema_ExtPC::*)() const) &Extrema_ExtPC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPC.def("IsMin", (Standard_Boolean (Extrema_ExtPC::*)(const Standard_Integer) const) &Extrema_ExtPC::IsMin, "Returns True if the <N>th extremum distance is a minimum.", py::arg("N"));
cls_Extrema_ExtPC.def("Point", (const Extrema_POnCurv & (Extrema_ExtPC::*)(const Standard_Integer) const) &Extrema_ExtPC::Point, "Returns the point of the <N>th extremum distance.", py::arg("N"));
cls_Extrema_ExtPC.def("TrimmedSquareDistances", [](Extrema_ExtPC &self, Standard_Real & dist1, Standard_Real & dist2, gp_Pnt & P1, gp_Pnt & P2){ self.TrimmedSquareDistances(dist1, dist2, P1, P2); return std::tuple<Standard_Real &, Standard_Real &>(dist1, dist2); }, "if the curve is a trimmed curve, dist1 is a square distance between <P> and the point of parameter FirstParameter <P1> and dist2 is a square distance between <P> and the point of parameter LastParameter <P2>.", py::arg("dist1"), py::arg("dist2"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_EXTPELS
py::class_<Extrema_ExtPElS> cls_Extrema_ExtPElS(mod, "Extrema_ExtPElS", "It calculates all the extremum distances between a point and a surface. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtPElS.def(py::init<>());
cls_Extrema_ExtPElS.def(py::init<const gp_Pnt &, const gp_Cylinder &, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def(py::init<const gp_Pnt &, const gp_Pln &, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def(py::init<const gp_Pnt &, const gp_Cone &, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def(py::init<const gp_Pnt &, const gp_Torus &, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def(py::init<const gp_Pnt &, const gp_Sphere &, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Tol"));

// Methods
// cls_Extrema_ExtPElS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtPElS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtPElS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtPElS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtPElS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtPElS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtPElS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtPElS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtPElS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtPElS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtPElS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtPElS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtPElS.def("Perform", (void (Extrema_ExtPElS::*)(const gp_Pnt &, const gp_Cylinder &, const Standard_Real)) &Extrema_ExtPElS::Perform, "None", py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def("Perform", (void (Extrema_ExtPElS::*)(const gp_Pnt &, const gp_Pln &, const Standard_Real)) &Extrema_ExtPElS::Perform, "None", py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def("Perform", (void (Extrema_ExtPElS::*)(const gp_Pnt &, const gp_Cone &, const Standard_Real)) &Extrema_ExtPElS::Perform, "None", py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def("Perform", (void (Extrema_ExtPElS::*)(const gp_Pnt &, const gp_Torus &, const Standard_Real)) &Extrema_ExtPElS::Perform, "None", py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def("Perform", (void (Extrema_ExtPElS::*)(const gp_Pnt &, const gp_Sphere &, const Standard_Real)) &Extrema_ExtPElS::Perform, "None", py::arg("P"), py::arg("S"), py::arg("Tol"));
cls_Extrema_ExtPElS.def("IsDone", (Standard_Boolean (Extrema_ExtPElS::*)() const) &Extrema_ExtPElS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtPElS.def("NbExt", (Standard_Integer (Extrema_ExtPElS::*)() const) &Extrema_ExtPElS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPElS.def("SquareDistance", (Standard_Real (Extrema_ExtPElS::*)(const Standard_Integer) const) &Extrema_ExtPElS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtPElS.def("Point", (const Extrema_POnSurf & (Extrema_ExtPElS::*)(const Standard_Integer) const) &Extrema_ExtPElS::Point, "Returns the point of the Nth resulting distance.", py::arg("N"));

// CLASS: EXTREMA_PONSURFPARAMS
py::class_<Extrema_POnSurfParams, Extrema_POnSurf> cls_Extrema_POnSurfParams(mod, "Extrema_POnSurfParams", "Data container for point on surface parameters. These parameters are required to compute an initial approximation for extrema computation.");

// Constructors
cls_Extrema_POnSurfParams.def(py::init<>());
cls_Extrema_POnSurfParams.def(py::init<const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("theU"), py::arg("theV"), py::arg("thePnt"));

// Methods
// cls_Extrema_POnSurfParams.def_static("operator new_", (void * (*)(size_t)) &Extrema_POnSurfParams::operator new, "None", py::arg("theSize"));
// cls_Extrema_POnSurfParams.def_static("operator delete_", (void (*)(void *)) &Extrema_POnSurfParams::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_POnSurfParams.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_POnSurfParams::operator new[], "None", py::arg("theSize"));
// cls_Extrema_POnSurfParams.def_static("operator delete[]_", (void (*)(void *)) &Extrema_POnSurfParams::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_POnSurfParams.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_POnSurfParams::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_POnSurfParams.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_POnSurfParams::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_POnSurfParams.def("SetSqrDistance", (void (Extrema_POnSurfParams::*)(const Standard_Real)) &Extrema_POnSurfParams::SetSqrDistance, "Sets the square distance from this point to another one (e.g. to the point to be projected).", py::arg("theSqrDistance"));
cls_Extrema_POnSurfParams.def("GetSqrDistance", (Standard_Real (Extrema_POnSurfParams::*)() const) &Extrema_POnSurfParams::GetSqrDistance, "Query the square distance from this point to another one.");
cls_Extrema_POnSurfParams.def("SetElementType", (void (Extrema_POnSurfParams::*)(const Extrema_ElementType)) &Extrema_POnSurfParams::SetElementType, "Sets the element type on which this point is situated.", py::arg("theElementType"));
cls_Extrema_POnSurfParams.def("GetElementType", (Extrema_ElementType (Extrema_POnSurfParams::*)() const) &Extrema_POnSurfParams::GetElementType, "Query the element type on which this point is situated.");
cls_Extrema_POnSurfParams.def("SetIndices", (void (Extrema_POnSurfParams::*)(const Standard_Integer, const Standard_Integer)) &Extrema_POnSurfParams::SetIndices, "Sets the U and V indices of an element that contains this point.", py::arg("theIndexU"), py::arg("theIndexV"));
cls_Extrema_POnSurfParams.def("GetIndices", [](Extrema_POnSurfParams &self, Standard_Integer & theIndexU, Standard_Integer & theIndexV){ self.GetIndices(theIndexU, theIndexV); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndexU, theIndexV); }, "Query the U and V indices of an element that contains this point.", py::arg("theIndexU"), py::arg("theIndexV"));

// TYPEDEF: EXTREMA_ARRAY2OFPONSURFPARAMS
bind_NCollection_Array2<Extrema_POnSurfParams>(mod, "Extrema_Array2OfPOnSurfParams", py::module_local(false));

// CLASS: EXTREMA_HARRAY2OFPONSURFPARAMS
py::class_<Extrema_HArray2OfPOnSurfParams, opencascade::handle<Extrema_HArray2OfPOnSurfParams>, Standard_Transient> cls_Extrema_HArray2OfPOnSurfParams(mod, "Extrema_HArray2OfPOnSurfParams", "None", py::multiple_inheritance());

// Constructors
cls_Extrema_HArray2OfPOnSurfParams.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_Extrema_HArray2OfPOnSurfParams.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Extrema_Array2OfPOnSurfParams::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_Extrema_HArray2OfPOnSurfParams.def(py::init<const Extrema_Array2OfPOnSurfParams &>(), py::arg("theOther"));

// Methods
// cls_Extrema_HArray2OfPOnSurfParams.def_static("operator new_", (void * (*)(size_t)) &Extrema_HArray2OfPOnSurfParams::operator new, "None", py::arg("theSize"));
// cls_Extrema_HArray2OfPOnSurfParams.def_static("operator delete_", (void (*)(void *)) &Extrema_HArray2OfPOnSurfParams::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnSurfParams.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_HArray2OfPOnSurfParams::operator new[], "None", py::arg("theSize"));
// cls_Extrema_HArray2OfPOnSurfParams.def_static("operator delete[]_", (void (*)(void *)) &Extrema_HArray2OfPOnSurfParams::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnSurfParams.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_HArray2OfPOnSurfParams::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnSurfParams.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_HArray2OfPOnSurfParams::operator delete, "None", py::arg(""), py::arg(""));
// cls_Extrema_HArray2OfPOnSurfParams.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray2OfPOnSurfParams::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Extrema_HArray2OfPOnSurfParams.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray2OfPOnSurfParams::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Extrema_HArray2OfPOnSurfParams.def("Array2", (const Extrema_Array2OfPOnSurfParams & (Extrema_HArray2OfPOnSurfParams::*)() const) &Extrema_HArray2OfPOnSurfParams::Array2, "None");
cls_Extrema_HArray2OfPOnSurfParams.def("ChangeArray2", (Extrema_Array2OfPOnSurfParams & (Extrema_HArray2OfPOnSurfParams::*)()) &Extrema_HArray2OfPOnSurfParams::ChangeArray2, "None");
cls_Extrema_HArray2OfPOnSurfParams.def_static("get_type_name_", (const char * (*)()) &Extrema_HArray2OfPOnSurfParams::get_type_name, "None");
cls_Extrema_HArray2OfPOnSurfParams.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_HArray2OfPOnSurfParams::get_type_descriptor, "None");
cls_Extrema_HArray2OfPOnSurfParams.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_HArray2OfPOnSurfParams::*)() const) &Extrema_HArray2OfPOnSurfParams::DynamicType, "None");

// TYPEDEF: EXTREMA_UBTREEOFSPHERE
bind_NCollection_UBTree<int, Bnd_Sphere>(mod, "Extrema_UBTreeOfSphere", py::module_local(false));

// TYPEDEF: EXTREMA_UBTREEFILLEROFSPHERE
bind_NCollection_UBTreeFiller<int, Bnd_Sphere>(mod, "Extrema_UBTreeFillerOfSphere", py::module_local(false));

// TYPEDEF: EXTREMA_HUBTREEOFSPHERE
bind_NCollection_Handle<NCollection_UBTree<int, Bnd_Sphere> >(mod, "Extrema_HUBTreeOfSphere", py::module_local(false));

// CLASS: EXTREMA_FUNCPSNORM
py::class_<Extrema_FuncPSNorm, math_FunctionSetWithDerivatives> cls_Extrema_FuncPSNorm(mod, "Extrema_FuncPSNorm", "Functional for search of extremum of the distance between point P and surface S, starting from approximate solution (u0, v0).");

// Constructors
cls_Extrema_FuncPSNorm.def(py::init<>());
cls_Extrema_FuncPSNorm.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &>(), py::arg("P"), py::arg("S"));

// Methods
// cls_Extrema_FuncPSNorm.def_static("operator new_", (void * (*)(size_t)) &Extrema_FuncPSNorm::operator new, "None", py::arg("theSize"));
// cls_Extrema_FuncPSNorm.def_static("operator delete_", (void (*)(void *)) &Extrema_FuncPSNorm::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_FuncPSNorm.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_FuncPSNorm::operator new[], "None", py::arg("theSize"));
// cls_Extrema_FuncPSNorm.def_static("operator delete[]_", (void (*)(void *)) &Extrema_FuncPSNorm::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_FuncPSNorm.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_FuncPSNorm::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_FuncPSNorm.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_FuncPSNorm::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_FuncPSNorm.def("Initialize", (void (Extrema_FuncPSNorm::*)(const Adaptor3d_Surface &)) &Extrema_FuncPSNorm::Initialize, "sets the field mysurf of the function.", py::arg("S"));
cls_Extrema_FuncPSNorm.def("SetPoint", (void (Extrema_FuncPSNorm::*)(const gp_Pnt &)) &Extrema_FuncPSNorm::SetPoint, "sets the field mysurf of the function.", py::arg("P"));
cls_Extrema_FuncPSNorm.def("NbVariables", (Standard_Integer (Extrema_FuncPSNorm::*)() const) &Extrema_FuncPSNorm::NbVariables, "None");
cls_Extrema_FuncPSNorm.def("NbEquations", (Standard_Integer (Extrema_FuncPSNorm::*)() const) &Extrema_FuncPSNorm::NbEquations, "None");
cls_Extrema_FuncPSNorm.def("Value", (Standard_Boolean (Extrema_FuncPSNorm::*)(const math_Vector &, math_Vector &)) &Extrema_FuncPSNorm::Value, "Calculate Fi(U,V).", py::arg("UV"), py::arg("F"));
cls_Extrema_FuncPSNorm.def("Derivatives", (Standard_Boolean (Extrema_FuncPSNorm::*)(const math_Vector &, math_Matrix &)) &Extrema_FuncPSNorm::Derivatives, "Calculate Fi'(U,V).", py::arg("UV"), py::arg("DF"));
cls_Extrema_FuncPSNorm.def("Values", (Standard_Boolean (Extrema_FuncPSNorm::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Extrema_FuncPSNorm::Values, "Calculate Fi(U,V) and Fi'(U,V).", py::arg("UV"), py::arg("F"), py::arg("DF"));
cls_Extrema_FuncPSNorm.def("GetStateNumber", (Standard_Integer (Extrema_FuncPSNorm::*)()) &Extrema_FuncPSNorm::GetStateNumber, "Save the found extremum.");
cls_Extrema_FuncPSNorm.def("NbExt", (Standard_Integer (Extrema_FuncPSNorm::*)() const) &Extrema_FuncPSNorm::NbExt, "Return the number of found extrema.");
cls_Extrema_FuncPSNorm.def("SquareDistance", (Standard_Real (Extrema_FuncPSNorm::*)(const Standard_Integer) const) &Extrema_FuncPSNorm::SquareDistance, "Return the value of the Nth distance.", py::arg("N"));
cls_Extrema_FuncPSNorm.def("Point", (const Extrema_POnSurf & (Extrema_FuncPSNorm::*)(const Standard_Integer) const) &Extrema_FuncPSNorm::Point, "Returns the Nth extremum.", py::arg("N"));

// CLASS: EXTREMA_GENEXTPS
py::class_<Extrema_GenExtPS> cls_Extrema_GenExtPS(mod, "Extrema_GenExtPS", "It calculates all the extremum distances between a point and a surface. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_GenExtPS.def(py::init<>());
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Extrema_ExtFlag>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("TolU"), py::arg("TolV"), py::arg("F"));
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("TolU"), py::arg("TolV"), py::arg("F"), py::arg("A"));
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtFlag>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"), py::arg("F"));
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"), py::arg("F"), py::arg("A"));

// Methods
// cls_Extrema_GenExtPS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenExtPS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenExtPS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenExtPS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenExtPS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenExtPS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenExtPS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenExtPS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenExtPS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenExtPS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenExtPS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenExtPS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenExtPS.def("Initialize", (void (Extrema_GenExtPS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real)) &Extrema_GenExtPS::Initialize, "None", py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_GenExtPS.def("Initialize", (void (Extrema_GenExtPS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenExtPS::Initialize, "None", py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_GenExtPS.def("Perform", (void (Extrema_GenExtPS::*)(const gp_Pnt &)) &Extrema_GenExtPS::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_GenExtPS.def("SetFlag", (void (Extrema_GenExtPS::*)(const Extrema_ExtFlag)) &Extrema_GenExtPS::SetFlag, "None", py::arg("F"));
cls_Extrema_GenExtPS.def("SetAlgo", (void (Extrema_GenExtPS::*)(const Extrema_ExtAlgo)) &Extrema_GenExtPS::SetAlgo, "None", py::arg("A"));
cls_Extrema_GenExtPS.def("IsDone", (Standard_Boolean (Extrema_GenExtPS::*)() const) &Extrema_GenExtPS::IsDone, "Returns True if the distances are found.");
cls_Extrema_GenExtPS.def("NbExt", (Standard_Integer (Extrema_GenExtPS::*)() const) &Extrema_GenExtPS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_GenExtPS.def("SquareDistance", (Standard_Real (Extrema_GenExtPS::*)(const Standard_Integer) const) &Extrema_GenExtPS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_GenExtPS.def("Point", (const Extrema_POnSurf & (Extrema_GenExtPS::*)(const Standard_Integer) const) &Extrema_GenExtPS::Point, "Returns the point of the Nth resulting distance.", py::arg("N"));

// CLASS: EXTREMA_EXTPS
py::class_<Extrema_ExtPS> cls_Extrema_ExtPS(mod, "Extrema_ExtPS", "It calculates all the extremum distances between a point and a surface. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtPS.def(py::init<>());
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Extrema_ExtFlag>(), py::arg("P"), py::arg("S"), py::arg("TolU"), py::arg("TolV"), py::arg("F"));
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("S"), py::arg("TolU"), py::arg("TolV"), py::arg("F"), py::arg("A"));
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtFlag>(), py::arg("P"), py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"), py::arg("F"));
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"), py::arg("F"), py::arg("A"));

// Methods
// cls_Extrema_ExtPS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtPS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtPS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtPS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtPS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtPS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtPS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtPS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtPS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtPS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtPS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtPS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtPS.def("Initialize", (void (Extrema_ExtPS::*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPS::Initialize, "Initializes the fields of the algorithm.", py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPS.def("Perform", (void (Extrema_ExtPS::*)(const gp_Pnt &)) &Extrema_ExtPS::Perform, "Computes the distances. An exception is raised if the fieds have not been initialized.", py::arg("P"));
cls_Extrema_ExtPS.def("IsDone", (Standard_Boolean (Extrema_ExtPS::*)() const) &Extrema_ExtPS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtPS.def("NbExt", (Standard_Integer (Extrema_ExtPS::*)() const) &Extrema_ExtPS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPS.def("SquareDistance", (Standard_Real (Extrema_ExtPS::*)(const Standard_Integer) const) &Extrema_ExtPS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtPS.def("Point", (const Extrema_POnSurf & (Extrema_ExtPS::*)(const Standard_Integer) const) &Extrema_ExtPS::Point, "Returns the point of the Nth resulting distance.", py::arg("N"));
cls_Extrema_ExtPS.def("TrimmedSquareDistances", [](Extrema_ExtPS &self, Standard_Real & dUfVf, Standard_Real & dUfVl, Standard_Real & dUlVf, Standard_Real & dUlVl, gp_Pnt & PUfVf, gp_Pnt & PUfVl, gp_Pnt & PUlVf, gp_Pnt & PUlVl){ self.TrimmedSquareDistances(dUfVf, dUfVl, dUlVf, dUlVl, PUfVf, PUfVl, PUlVf, PUlVl); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(dUfVf, dUfVl, dUlVf, dUlVl); }, "if the surface is a trimmed surface, dUfVf is a square distance between <P> and the point of parameter FirstUParameter and FirstVParameter <PUfVf>. dUfVl is a square distance between <P> and the point of parameter FirstUParameter and LastVParameter <PUfVl>. dUlVf is a square distance between <P> and the point of parameter LastUParameter and FirstVParameter <PUlVf>. dUlVl is a square distance between <P> and the point of parameter LastUParameter and LastVParameter <PUlVl>.", py::arg("dUfVf"), py::arg("dUfVl"), py::arg("dUlVf"), py::arg("dUlVl"), py::arg("PUfVf"), py::arg("PUfVl"), py::arg("PUlVf"), py::arg("PUlVl"));
cls_Extrema_ExtPS.def("SetFlag", (void (Extrema_ExtPS::*)(const Extrema_ExtFlag)) &Extrema_ExtPS::SetFlag, "None", py::arg("F"));
cls_Extrema_ExtPS.def("SetAlgo", (void (Extrema_ExtPS::*)(const Extrema_ExtAlgo)) &Extrema_ExtPS::SetAlgo, "None", py::arg("A"));

// CLASS: EXTREMA_PCLOCFOFLOCEPCOFLOCATEEXTPC
py::class_<Extrema_PCLocFOfLocEPCOfLocateExtPC, math_FunctionWithDerivative> cls_Extrema_PCLocFOfLocEPCOfLocateExtPC(mod, "Extrema_PCLocFOfLocEPCOfLocateExtPC", "None");

// Constructors
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def(py::init<>());
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &>(), py::arg("P"), py::arg("C"));

// Methods
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_PCLocFOfLocEPCOfLocateExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_PCLocFOfLocEPCOfLocateExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_PCLocFOfLocEPCOfLocateExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_PCLocFOfLocEPCOfLocateExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_PCLocFOfLocEPCOfLocateExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_PCLocFOfLocEPCOfLocateExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("Initialize", (void (Extrema_PCLocFOfLocEPCOfLocateExtPC::*)(const Adaptor3d_Curve &)) &Extrema_PCLocFOfLocEPCOfLocateExtPC::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("SetPoint", (void (Extrema_PCLocFOfLocEPCOfLocateExtPC::*)(const gp_Pnt &)) &Extrema_PCLocFOfLocEPCOfLocateExtPC::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("Value", [](Extrema_PCLocFOfLocEPCOfLocateExtPC &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("Derivative", [](Extrema_PCLocFOfLocEPCOfLocateExtPC &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("Values", [](Extrema_PCLocFOfLocEPCOfLocateExtPC &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("GetStateNumber", (Standard_Integer (Extrema_PCLocFOfLocEPCOfLocateExtPC::*)()) &Extrema_PCLocFOfLocEPCOfLocateExtPC::GetStateNumber, "Save the found extremum.");
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("NbExt", (Standard_Integer (Extrema_PCLocFOfLocEPCOfLocateExtPC::*)() const) &Extrema_PCLocFOfLocEPCOfLocateExtPC::NbExt, "Return the nunber of found extrema.");
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("SquareDistance", (Standard_Real (Extrema_PCLocFOfLocEPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_PCLocFOfLocEPCOfLocateExtPC::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("IsMin", (Standard_Boolean (Extrema_PCLocFOfLocEPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_PCLocFOfLocEPCOfLocateExtPC::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("Point", (const Extrema_POnCurv & (Extrema_PCLocFOfLocEPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_PCLocFOfLocEPCOfLocateExtPC::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("SubIntervalInitialize", (void (Extrema_PCLocFOfLocEPCOfLocateExtPC::*)(const Standard_Real, const Standard_Real)) &Extrema_PCLocFOfLocEPCOfLocateExtPC::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC.def("SearchOfTolerance", (Standard_Real (Extrema_PCLocFOfLocEPCOfLocateExtPC::*)()) &Extrema_PCLocFOfLocEPCOfLocateExtPC::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// CLASS: EXTREMA_LOCEPCOFLOCATEEXTPC
py::class_<Extrema_LocEPCOfLocateExtPC> cls_Extrema_LocEPCOfLocateExtPC(mod, "Extrema_LocEPCOfLocateExtPC", "None");

// Constructors
cls_Extrema_LocEPCOfLocateExtPC.def(py::init<>());
cls_Extrema_LocEPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("TolU"));
cls_Extrema_LocEPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));

// Methods
// cls_Extrema_LocEPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocEPCOfLocateExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocEPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_LocEPCOfLocateExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocEPCOfLocateExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocEPCOfLocateExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocEPCOfLocateExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocEPCOfLocateExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocEPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocEPCOfLocateExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocEPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocEPCOfLocateExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocEPCOfLocateExtPC.def("Initialize", (void (Extrema_LocEPCOfLocateExtPC::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_LocEPCOfLocateExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));
cls_Extrema_LocEPCOfLocateExtPC.def("Perform", (void (Extrema_LocEPCOfLocateExtPC::*)(const gp_Pnt &, const Standard_Real)) &Extrema_LocEPCOfLocateExtPC::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"), py::arg("U0"));
cls_Extrema_LocEPCOfLocateExtPC.def("IsDone", (Standard_Boolean (Extrema_LocEPCOfLocateExtPC::*)() const) &Extrema_LocEPCOfLocateExtPC::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocEPCOfLocateExtPC.def("SquareDistance", (Standard_Real (Extrema_LocEPCOfLocateExtPC::*)() const) &Extrema_LocEPCOfLocateExtPC::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocEPCOfLocateExtPC.def("IsMin", (Standard_Boolean (Extrema_LocEPCOfLocateExtPC::*)() const) &Extrema_LocEPCOfLocateExtPC::IsMin, "Returns True if the extremum distance is a minimum.");
cls_Extrema_LocEPCOfLocateExtPC.def("Point", (const Extrema_POnCurv & (Extrema_LocEPCOfLocateExtPC::*)() const) &Extrema_LocEPCOfLocateExtPC::Point, "Returns the point of the extremum distance.");

// CLASS: EXTREMA_PCFOFEPCOFELPCOFLOCATEEXTPC
py::class_<Extrema_PCFOfEPCOfELPCOfLocateExtPC, math_FunctionWithDerivative> cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC(mod, "Extrema_PCFOfEPCOfELPCOfLocateExtPC", "None");

// Constructors
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def(py::init<>());
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &>(), py::arg("P"), py::arg("C"));

// Methods
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("Initialize", (void (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const Adaptor3d_Curve &)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("SetPoint", (void (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const gp_Pnt &)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("Value", [](Extrema_PCFOfEPCOfELPCOfLocateExtPC &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("Derivative", [](Extrema_PCFOfEPCOfELPCOfLocateExtPC &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("Values", [](Extrema_PCFOfEPCOfELPCOfLocateExtPC &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("GetStateNumber", (Standard_Integer (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)()) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::GetStateNumber, "Save the found extremum.");
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("NbExt", (Standard_Integer (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)() const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::NbExt, "Return the nunber of found extrema.");
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("SquareDistance", (Standard_Real (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("IsMin", (Standard_Boolean (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("Point", (const Extrema_POnCurv & (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("SubIntervalInitialize", (void (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const Standard_Real, const Standard_Real)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("SearchOfTolerance", (Standard_Real (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)()) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// CLASS: EXTREMA_EPCOFELPCOFLOCATEEXTPC
py::class_<Extrema_EPCOfELPCOfLocateExtPC> cls_Extrema_EPCOfELPCOfLocateExtPC(mod, "Extrema_EPCOfELPCOfLocateExtPC", "None");

// Constructors
cls_Extrema_EPCOfELPCOfLocateExtPC.def(py::init<>());
cls_Extrema_EPCOfELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));

// Methods
// cls_Extrema_EPCOfELPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_EPCOfELPCOfLocateExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_EPCOfELPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_EPCOfELPCOfLocateExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_EPCOfELPCOfLocateExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_EPCOfELPCOfLocateExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_EPCOfELPCOfLocateExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_EPCOfELPCOfLocateExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_EPCOfELPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_EPCOfELPCOfLocateExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_EPCOfELPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_EPCOfELPCOfLocateExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_EPCOfELPCOfLocateExtPC.def("Initialize", (void (Extrema_EPCOfELPCOfLocateExtPC::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real)) &Extrema_EPCOfELPCOfLocateExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("NbU"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfELPCOfLocateExtPC.def("Initialize", (void (Extrema_EPCOfELPCOfLocateExtPC::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_EPCOfELPCOfLocateExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfELPCOfLocateExtPC.def("Initialize", (void (Extrema_EPCOfELPCOfLocateExtPC::*)(const Adaptor3d_Curve &)) &Extrema_EPCOfELPCOfLocateExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"));
cls_Extrema_EPCOfELPCOfLocateExtPC.def("Initialize", (void (Extrema_EPCOfELPCOfLocateExtPC::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_EPCOfELPCOfLocateExtPC::Initialize, "sets the fields of the algorithm.", py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfELPCOfLocateExtPC.def("Perform", (void (Extrema_EPCOfELPCOfLocateExtPC::*)(const gp_Pnt &)) &Extrema_EPCOfELPCOfLocateExtPC::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_EPCOfELPCOfLocateExtPC.def("IsDone", (Standard_Boolean (Extrema_EPCOfELPCOfLocateExtPC::*)() const) &Extrema_EPCOfELPCOfLocateExtPC::IsDone, "True if the distances are found.");
cls_Extrema_EPCOfELPCOfLocateExtPC.def("NbExt", (Standard_Integer (Extrema_EPCOfELPCOfLocateExtPC::*)() const) &Extrema_EPCOfELPCOfLocateExtPC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_EPCOfELPCOfLocateExtPC.def("SquareDistance", (Standard_Real (Extrema_EPCOfELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_EPCOfELPCOfLocateExtPC::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_EPCOfELPCOfLocateExtPC.def("IsMin", (Standard_Boolean (Extrema_EPCOfELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_EPCOfELPCOfLocateExtPC::IsMin, "Returns True if the Nth extremum distance is a minimum.", py::arg("N"));
cls_Extrema_EPCOfELPCOfLocateExtPC.def("Point", (const Extrema_POnCurv & (Extrema_EPCOfELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_EPCOfELPCOfLocateExtPC::Point, "Returns the point of the Nth extremum distance.", py::arg("N"));

// CLASS: EXTREMA_ELPCOFLOCATEEXTPC
py::class_<Extrema_ELPCOfLocateExtPC> cls_Extrema_ELPCOfLocateExtPC(mod, "Extrema_ELPCOfLocateExtPC", "None");

// Constructors
cls_Extrema_ELPCOfLocateExtPC.def(py::init<>());
cls_Extrema_ELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_ELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &>(), py::arg("P"), py::arg("C"));
cls_Extrema_ELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("TolF"));

// Methods
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ELPCOfLocateExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_ELPCOfLocateExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ELPCOfLocateExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ELPCOfLocateExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ELPCOfLocateExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ELPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ELPCOfLocateExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ELPCOfLocateExtPC.def("Initialize", [](Extrema_ELPCOfLocateExtPC &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_Extrema_ELPCOfLocateExtPC.def("Initialize", (void (Extrema_ELPCOfLocateExtPC::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ELPCOfLocateExtPC::Initialize, "initializes the fields of the algorithm.", py::arg("C"), py::arg("Uinf"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_ELPCOfLocateExtPC.def("Perform", (void (Extrema_ELPCOfLocateExtPC::*)(const gp_Pnt &)) &Extrema_ELPCOfLocateExtPC::Perform, "An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_ELPCOfLocateExtPC.def("IsDone", (Standard_Boolean (Extrema_ELPCOfLocateExtPC::*)() const) &Extrema_ELPCOfLocateExtPC::IsDone, "True if the distances are found.");
cls_Extrema_ELPCOfLocateExtPC.def("SquareDistance", (Standard_Real (Extrema_ELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_ELPCOfLocateExtPC::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
cls_Extrema_ELPCOfLocateExtPC.def("NbExt", (Standard_Integer (Extrema_ELPCOfLocateExtPC::*)() const) &Extrema_ELPCOfLocateExtPC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ELPCOfLocateExtPC.def("IsMin", (Standard_Boolean (Extrema_ELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_ELPCOfLocateExtPC::IsMin, "Returns True if the <N>th extremum distance is a minimum.", py::arg("N"));
cls_Extrema_ELPCOfLocateExtPC.def("Point", (const Extrema_POnCurv & (Extrema_ELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_ELPCOfLocateExtPC::Point, "Returns the point of the <N>th extremum distance.", py::arg("N"));
cls_Extrema_ELPCOfLocateExtPC.def("TrimmedSquareDistances", [](Extrema_ELPCOfLocateExtPC &self, Standard_Real & dist1, Standard_Real & dist2, gp_Pnt & P1, gp_Pnt & P2){ self.TrimmedSquareDistances(dist1, dist2, P1, P2); return std::tuple<Standard_Real &, Standard_Real &>(dist1, dist2); }, "if the curve is a trimmed curve, dist1 is a square distance between <P> and the point of parameter FirstParameter <P1> and dist2 is a square distance between <P> and the point of parameter LastParameter <P2>.", py::arg("dist1"), py::arg("dist2"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_LOCATEEXTPC
py::class_<Extrema_LocateExtPC> cls_Extrema_LocateExtPC(mod, "Extrema_LocateExtPC", "None");

// Constructors
cls_Extrema_LocateExtPC.def(py::init<>());
cls_Extrema_LocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("TolF"));
cls_Extrema_LocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("Umin"), py::arg("Usup"), py::arg("TolF"));

// Methods
// cls_Extrema_LocateExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocateExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocateExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_LocateExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocateExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocateExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocateExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocateExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocateExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocateExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocateExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocateExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocateExtPC.def("Initialize", (void (Extrema_LocateExtPC::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_LocateExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("Umin"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_LocateExtPC.def("Perform", (void (Extrema_LocateExtPC::*)(const gp_Pnt &, const Standard_Real)) &Extrema_LocateExtPC::Perform, "None", py::arg("P"), py::arg("U0"));
cls_Extrema_LocateExtPC.def("IsDone", (Standard_Boolean (Extrema_LocateExtPC::*)() const) &Extrema_LocateExtPC::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocateExtPC.def("SquareDistance", (Standard_Real (Extrema_LocateExtPC::*)() const) &Extrema_LocateExtPC::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocateExtPC.def("IsMin", (Standard_Boolean (Extrema_LocateExtPC::*)() const) &Extrema_LocateExtPC::IsMin, "Returns True if the extremum distance is a minimum.");
cls_Extrema_LocateExtPC.def("Point", (const Extrema_POnCurv & (Extrema_LocateExtPC::*)() const) &Extrema_LocateExtPC::Point, "Returns the point of the extremum distance.");

// CLASS: EXTREMA_LOCATEEXTCC
py::class_<Extrema_LocateExtCC> cls_Extrema_LocateExtCC(mod, "Extrema_LocateExtCC", "It calculates the distance between two curves with a close point; these distances can be maximum or minimum.");

// Constructors
cls_Extrema_LocateExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U0"), py::arg("V0"));

// Methods
// cls_Extrema_LocateExtCC.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocateExtCC::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocateExtCC.def_static("operator delete_", (void (*)(void *)) &Extrema_LocateExtCC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocateExtCC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocateExtCC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocateExtCC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocateExtCC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocateExtCC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocateExtCC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocateExtCC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocateExtCC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocateExtCC.def("IsDone", (Standard_Boolean (Extrema_LocateExtCC::*)() const) &Extrema_LocateExtCC::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocateExtCC.def("SquareDistance", (Standard_Real (Extrema_LocateExtCC::*)() const) &Extrema_LocateExtCC::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocateExtCC.def("Point", (void (Extrema_LocateExtCC::*)(Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_LocateExtCC::Point, "Returns the points of the extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_PONCURV2D
py::class_<Extrema_POnCurv2d> cls_Extrema_POnCurv2d(mod, "Extrema_POnCurv2d", "None");

// Constructors
cls_Extrema_POnCurv2d.def(py::init<>());
cls_Extrema_POnCurv2d.def(py::init<const Standard_Real, const gp_Pnt2d &>(), py::arg("U"), py::arg("P"));

// Methods
// cls_Extrema_POnCurv2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_POnCurv2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_POnCurv2d.def_static("operator delete_", (void (*)(void *)) &Extrema_POnCurv2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_POnCurv2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_POnCurv2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_POnCurv2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_POnCurv2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_POnCurv2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_POnCurv2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_POnCurv2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_POnCurv2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_POnCurv2d.def("SetValues", (void (Extrema_POnCurv2d::*)(const Standard_Real, const gp_Pnt2d &)) &Extrema_POnCurv2d::SetValues, "sets the point and parameter values.", py::arg("U"), py::arg("P"));
cls_Extrema_POnCurv2d.def("Value", (const gp_Pnt2d & (Extrema_POnCurv2d::*)() const) &Extrema_POnCurv2d::Value, "Returns the point.");
cls_Extrema_POnCurv2d.def("Parameter", (Standard_Real (Extrema_POnCurv2d::*)() const) &Extrema_POnCurv2d::Parameter, "Returns the parameter on the curve.");

// TYPEDEF: EXTREMA_ARRAY1OFPONCURV2D
bind_NCollection_Array1<Extrema_POnCurv2d>(mod, "Extrema_Array1OfPOnCurv2d", py::module_local(false));

// TYPEDEF: EXTREMA_ARRAY2OFPONCURV
bind_NCollection_Array2<Extrema_POnCurv>(mod, "Extrema_Array2OfPOnCurv", py::module_local(false));

// TYPEDEF: EXTREMA_ARRAY2OFPONCURV2D
bind_NCollection_Array2<Extrema_POnCurv2d>(mod, "Extrema_Array2OfPOnCurv2d", py::module_local(false));

// TYPEDEF: EXTREMA_ARRAY2OFPONSURF
bind_NCollection_Array2<Extrema_POnSurf>(mod, "Extrema_Array2OfPOnSurf", py::module_local(false));

// CLASS: EXTREMA_CCLOCFOFLOCECC
py::class_<Extrema_CCLocFOfLocECC, math_FunctionSetWithDerivatives> cls_Extrema_CCLocFOfLocECC(mod, "Extrema_CCLocFOfLocECC", "None");

// Constructors
cls_Extrema_CCLocFOfLocECC.def(py::init<>());
cls_Extrema_CCLocFOfLocECC.def(py::init<const Standard_Real>(), py::arg("thetol"));
cls_Extrema_CCLocFOfLocECC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_CCLocFOfLocECC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("thetol"));

// Methods
// cls_Extrema_CCLocFOfLocECC.def_static("operator new_", (void * (*)(size_t)) &Extrema_CCLocFOfLocECC::operator new, "None", py::arg("theSize"));
// cls_Extrema_CCLocFOfLocECC.def_static("operator delete_", (void (*)(void *)) &Extrema_CCLocFOfLocECC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_CCLocFOfLocECC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_CCLocFOfLocECC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_CCLocFOfLocECC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_CCLocFOfLocECC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_CCLocFOfLocECC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_CCLocFOfLocECC.def("SetCurve", (void (Extrema_CCLocFOfLocECC::*)(const Standard_Integer, const Adaptor3d_Curve &)) &Extrema_CCLocFOfLocECC::SetCurve, "None", py::arg("theRank"), py::arg("C1"));
cls_Extrema_CCLocFOfLocECC.def("SetTolerance", (void (Extrema_CCLocFOfLocECC::*)(const Standard_Real)) &Extrema_CCLocFOfLocECC::SetTolerance, "None", py::arg("theTol"));
cls_Extrema_CCLocFOfLocECC.def("NbVariables", (Standard_Integer (Extrema_CCLocFOfLocECC::*)() const) &Extrema_CCLocFOfLocECC::NbVariables, "None");
cls_Extrema_CCLocFOfLocECC.def("NbEquations", (Standard_Integer (Extrema_CCLocFOfLocECC::*)() const) &Extrema_CCLocFOfLocECC::NbEquations, "None");
cls_Extrema_CCLocFOfLocECC.def("Value", (Standard_Boolean (Extrema_CCLocFOfLocECC::*)(const math_Vector &, math_Vector &)) &Extrema_CCLocFOfLocECC::Value, "Calculate Fi(U,V).", py::arg("UV"), py::arg("F"));
cls_Extrema_CCLocFOfLocECC.def("Derivatives", (Standard_Boolean (Extrema_CCLocFOfLocECC::*)(const math_Vector &, math_Matrix &)) &Extrema_CCLocFOfLocECC::Derivatives, "Calculate Fi'(U,V).", py::arg("UV"), py::arg("DF"));
cls_Extrema_CCLocFOfLocECC.def("Values", (Standard_Boolean (Extrema_CCLocFOfLocECC::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Extrema_CCLocFOfLocECC::Values, "Calculate Fi(U,V) and Fi'(U,V).", py::arg("UV"), py::arg("F"), py::arg("DF"));
cls_Extrema_CCLocFOfLocECC.def("GetStateNumber", (Standard_Integer (Extrema_CCLocFOfLocECC::*)()) &Extrema_CCLocFOfLocECC::GetStateNumber, "Save the found extremum.");
cls_Extrema_CCLocFOfLocECC.def("NbExt", (Standard_Integer (Extrema_CCLocFOfLocECC::*)() const) &Extrema_CCLocFOfLocECC::NbExt, "Return the number of found extrema.");
cls_Extrema_CCLocFOfLocECC.def("SquareDistance", (Standard_Real (Extrema_CCLocFOfLocECC::*)(const Standard_Integer) const) &Extrema_CCLocFOfLocECC::SquareDistance, "Return the value of the Nth distance.", py::arg("N"));
cls_Extrema_CCLocFOfLocECC.def("Points", (void (Extrema_CCLocFOfLocECC::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_CCLocFOfLocECC::Points, "Return the points of the Nth extreme distance.", py::arg("N"), py::arg("P1"), py::arg("P2"));
cls_Extrema_CCLocFOfLocECC.def("CurvePtr", (Standard_Address (Extrema_CCLocFOfLocECC::*)(const Standard_Integer) const) &Extrema_CCLocFOfLocECC::CurvePtr, "Returns a pointer to the curve specified in the constructor or in SetCurve() method.", py::arg("theRank"));
cls_Extrema_CCLocFOfLocECC.def("Tolerance", (Standard_Real (Extrema_CCLocFOfLocECC::*)() const) &Extrema_CCLocFOfLocECC::Tolerance, "Returns a tolerance specified in the constructor or in SetTolerance() method.");
cls_Extrema_CCLocFOfLocECC.def("SubIntervalInitialize", (void (Extrema_CCLocFOfLocECC::*)(const math_Vector &, const math_Vector &)) &Extrema_CCLocFOfLocECC::SubIntervalInitialize, "Determines of boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_CCLocFOfLocECC.def("SearchOfTolerance", (Standard_Real (Extrema_CCLocFOfLocECC::*)(const Standard_Address)) &Extrema_CCLocFOfLocECC::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.", py::arg("C"));

// TYPEDEF: EXTREMA_SEQUENCEOFPONCURV2D
bind_NCollection_Sequence<Extrema_POnCurv2d>(mod, "Extrema_SequenceOfPOnCurv2d", py::module_local(false));

// CLASS: EXTREMA_CCLOCFOFLOCECC2D
py::class_<Extrema_CCLocFOfLocECC2d, math_FunctionSetWithDerivatives> cls_Extrema_CCLocFOfLocECC2d(mod, "Extrema_CCLocFOfLocECC2d", "None");

// Constructors
cls_Extrema_CCLocFOfLocECC2d.def(py::init<>());
cls_Extrema_CCLocFOfLocECC2d.def(py::init<const Standard_Real>(), py::arg("thetol"));
cls_Extrema_CCLocFOfLocECC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_CCLocFOfLocECC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("thetol"));

// Methods
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_CCLocFOfLocECC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_CCLocFOfLocECC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_CCLocFOfLocECC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_CCLocFOfLocECC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_CCLocFOfLocECC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_CCLocFOfLocECC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_CCLocFOfLocECC2d.def("SetCurve", (void (Extrema_CCLocFOfLocECC2d::*)(const Standard_Integer, const Adaptor2d_Curve2d &)) &Extrema_CCLocFOfLocECC2d::SetCurve, "None", py::arg("theRank"), py::arg("C1"));
cls_Extrema_CCLocFOfLocECC2d.def("SetTolerance", (void (Extrema_CCLocFOfLocECC2d::*)(const Standard_Real)) &Extrema_CCLocFOfLocECC2d::SetTolerance, "None", py::arg("theTol"));
cls_Extrema_CCLocFOfLocECC2d.def("NbVariables", (Standard_Integer (Extrema_CCLocFOfLocECC2d::*)() const) &Extrema_CCLocFOfLocECC2d::NbVariables, "None");
cls_Extrema_CCLocFOfLocECC2d.def("NbEquations", (Standard_Integer (Extrema_CCLocFOfLocECC2d::*)() const) &Extrema_CCLocFOfLocECC2d::NbEquations, "None");
cls_Extrema_CCLocFOfLocECC2d.def("Value", (Standard_Boolean (Extrema_CCLocFOfLocECC2d::*)(const math_Vector &, math_Vector &)) &Extrema_CCLocFOfLocECC2d::Value, "Calculate Fi(U,V).", py::arg("UV"), py::arg("F"));
cls_Extrema_CCLocFOfLocECC2d.def("Derivatives", (Standard_Boolean (Extrema_CCLocFOfLocECC2d::*)(const math_Vector &, math_Matrix &)) &Extrema_CCLocFOfLocECC2d::Derivatives, "Calculate Fi'(U,V).", py::arg("UV"), py::arg("DF"));
cls_Extrema_CCLocFOfLocECC2d.def("Values", (Standard_Boolean (Extrema_CCLocFOfLocECC2d::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Extrema_CCLocFOfLocECC2d::Values, "Calculate Fi(U,V) and Fi'(U,V).", py::arg("UV"), py::arg("F"), py::arg("DF"));
cls_Extrema_CCLocFOfLocECC2d.def("GetStateNumber", (Standard_Integer (Extrema_CCLocFOfLocECC2d::*)()) &Extrema_CCLocFOfLocECC2d::GetStateNumber, "Save the found extremum.");
cls_Extrema_CCLocFOfLocECC2d.def("NbExt", (Standard_Integer (Extrema_CCLocFOfLocECC2d::*)() const) &Extrema_CCLocFOfLocECC2d::NbExt, "Return the number of found extrema.");
cls_Extrema_CCLocFOfLocECC2d.def("SquareDistance", (Standard_Real (Extrema_CCLocFOfLocECC2d::*)(const Standard_Integer) const) &Extrema_CCLocFOfLocECC2d::SquareDistance, "Return the value of the Nth distance.", py::arg("N"));
cls_Extrema_CCLocFOfLocECC2d.def("Points", (void (Extrema_CCLocFOfLocECC2d::*)(const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_CCLocFOfLocECC2d::Points, "Return the points of the Nth extreme distance.", py::arg("N"), py::arg("P1"), py::arg("P2"));
cls_Extrema_CCLocFOfLocECC2d.def("CurvePtr", (Standard_Address (Extrema_CCLocFOfLocECC2d::*)(const Standard_Integer) const) &Extrema_CCLocFOfLocECC2d::CurvePtr, "Returns a pointer to the curve specified in the constructor or in SetCurve() method.", py::arg("theRank"));
cls_Extrema_CCLocFOfLocECC2d.def("Tolerance", (Standard_Real (Extrema_CCLocFOfLocECC2d::*)() const) &Extrema_CCLocFOfLocECC2d::Tolerance, "Returns a tolerance specified in the constructor or in SetTolerance() method.");
cls_Extrema_CCLocFOfLocECC2d.def("SubIntervalInitialize", (void (Extrema_CCLocFOfLocECC2d::*)(const math_Vector &, const math_Vector &)) &Extrema_CCLocFOfLocECC2d::SubIntervalInitialize, "Determines of boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_CCLocFOfLocECC2d.def("SearchOfTolerance", (Standard_Real (Extrema_CCLocFOfLocECC2d::*)(const Standard_Address)) &Extrema_CCLocFOfLocECC2d::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.", py::arg("C"));

// CLASS: EXTREMA_CURVE2DTOOL
py::class_<Extrema_Curve2dTool> cls_Extrema_Curve2dTool(mod, "Extrema_Curve2dTool", "None");

// Constructors
cls_Extrema_Curve2dTool.def(py::init<>());

// Methods
// cls_Extrema_Curve2dTool.def_static("operator new_", (void * (*)(size_t)) &Extrema_Curve2dTool::operator new, "None", py::arg("theSize"));
// cls_Extrema_Curve2dTool.def_static("operator delete_", (void (*)(void *)) &Extrema_Curve2dTool::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_Curve2dTool.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_Curve2dTool::operator new[], "None", py::arg("theSize"));
// cls_Extrema_Curve2dTool.def_static("operator delete[]_", (void (*)(void *)) &Extrema_Curve2dTool::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_Curve2dTool.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_Curve2dTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_Curve2dTool.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_Curve2dTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_Curve2dTool.def_static("FirstParameter_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::FirstParameter, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("LastParameter_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::LastParameter, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Continuity_", (GeomAbs_Shape (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Continuity, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("NbIntervals_", (Standard_Integer (*)(const Adaptor2d_Curve2d &, const GeomAbs_Shape)) &Extrema_Curve2dTool::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("C"), py::arg("S"));
cls_Extrema_Curve2dTool.def_static("Intervals_", (void (*)(const Adaptor2d_Curve2d &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &Extrema_Curve2dTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_Extrema_Curve2dTool.def_static("DeflCurvIntervals_", (opencascade::handle<TColStd_HArray1OfReal> (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::DeflCurvIntervals, "Returns the parameters bounding the intervals of subdivision of curve according to Curvature deflection. Value of deflection is defined in method.", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("IsClosed_", (Standard_Boolean (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::IsClosed, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::IsPeriodic, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Period_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Period, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Value_", (gp_Pnt2d (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &Extrema_Curve2dTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_Extrema_Curve2dTool.def_static("D0_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &)) &Extrema_Curve2dTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_Extrema_Curve2dTool.def_static("D1_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &Extrema_Curve2dTool::D1, "Computes the point of parameter U on the curve with its first derivative.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_Extrema_Curve2dTool.def_static("D2_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &Extrema_Curve2dTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Extrema_Curve2dTool.def_static("D3_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Extrema_Curve2dTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Extrema_Curve2dTool.def_static("DN_", (gp_Vec2d (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Integer)) &Extrema_Curve2dTool::DN, "The returned vector gives the value of the derivative for the order of derivation N.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_Extrema_Curve2dTool.def_static("Resolution_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &Extrema_Curve2dTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_Extrema_Curve2dTool.def_static("GetType_", (GeomAbs_CurveType (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Line_", (gp_Lin2d (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Line, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Circle_", (gp_Circ2d (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Circle, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Ellipse_", (gp_Elips2d (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Ellipse, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Hyperbola_", (gp_Hypr2d (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Hyperbola, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Parabola_", (gp_Parab2d (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Parabola, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Degree_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Degree, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("IsRational_", (Standard_Boolean (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::IsRational, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("NbPoles_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::NbPoles, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("NbKnots_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::NbKnots, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Bezier_", (opencascade::handle<Geom2d_BezierCurve> (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Bezier, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("BSpline_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::BSpline, "None", py::arg("C"));

// CLASS: EXTREMA_CURVETOOL
py::class_<Extrema_CurveTool> cls_Extrema_CurveTool(mod, "Extrema_CurveTool", "None");

// Constructors
cls_Extrema_CurveTool.def(py::init<>());

// Methods
// cls_Extrema_CurveTool.def_static("operator new_", (void * (*)(size_t)) &Extrema_CurveTool::operator new, "None", py::arg("theSize"));
// cls_Extrema_CurveTool.def_static("operator delete_", (void (*)(void *)) &Extrema_CurveTool::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_CurveTool.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_CurveTool::operator new[], "None", py::arg("theSize"));
// cls_Extrema_CurveTool.def_static("operator delete[]_", (void (*)(void *)) &Extrema_CurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_CurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_CurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_CurveTool.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_CurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_CurveTool.def_static("FirstParameter_", (Standard_Real (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::FirstParameter, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("LastParameter_", (Standard_Real (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::LastParameter, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Continuity_", (GeomAbs_Shape (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Continuity, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("NbIntervals_", (Standard_Integer (*)(Adaptor3d_Curve &, const GeomAbs_Shape)) &Extrema_CurveTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("C"), py::arg("S"));
cls_Extrema_CurveTool.def_static("Intervals_", (void (*)(Adaptor3d_Curve &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &Extrema_CurveTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_Extrema_CurveTool.def_static("DeflCurvIntervals_", (opencascade::handle<TColStd_HArray1OfReal> (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::DeflCurvIntervals, "Returns the parameters bounding the intervals of subdivision of curve according to Curvature deflection. Value of deflection is defined in method.", py::arg("C"));
cls_Extrema_CurveTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::IsPeriodic, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Period_", (Standard_Real (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Period, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Resolution_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real)) &Extrema_CurveTool::Resolution, "None", py::arg("C"), py::arg("R3d"));
cls_Extrema_CurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::GetType, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Value_", (gp_Pnt (*)(const Adaptor3d_Curve &, const Standard_Real)) &Extrema_CurveTool::Value, "None", py::arg("C"), py::arg("U"));
cls_Extrema_CurveTool.def_static("D0_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, gp_Pnt &)) &Extrema_CurveTool::D0, "None", py::arg("C"), py::arg("U"), py::arg("P"));
cls_Extrema_CurveTool.def_static("D1_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &)) &Extrema_CurveTool::D1, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_Extrema_CurveTool.def_static("D2_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &Extrema_CurveTool::D2, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Extrema_CurveTool.def_static("D3_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &Extrema_CurveTool::D3, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Extrema_CurveTool.def_static("DN_", (gp_Vec (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Integer)) &Extrema_CurveTool::DN, "None", py::arg("C"), py::arg("U"), py::arg("N"));
cls_Extrema_CurveTool.def_static("Line_", (gp_Lin (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Line, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Circle_", (gp_Circ (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Circle, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Ellipse_", (gp_Elips (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Ellipse, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Hyperbola_", (gp_Hypr (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Hyperbola, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Parabola_", (gp_Parab (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Parabola, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Degree_", (Standard_Integer (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Degree, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("IsRational_", (Standard_Boolean (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::IsRational, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("NbPoles_", (Standard_Integer (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::NbPoles, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("NbKnots_", (Standard_Integer (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::NbKnots, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Bezier_", (opencascade::handle<Geom_BezierCurve> (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Bezier, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineCurve> (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::BSpline, "None", py::arg("C"));

// CLASS: EXTREMA_ECC2D
py::class_<Extrema_ECC2d> cls_Extrema_ECC2d(mod, "Extrema_ECC2d", "None");

// Constructors
cls_Extrema_ECC2d.def(py::init<>());
cls_Extrema_ECC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ECC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"));

// Methods
// cls_Extrema_ECC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_ECC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_ECC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_ECC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ECC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ECC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ECC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ECC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ECC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ECC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ECC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ECC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ECC2d.def("SetParams", (void (Extrema_ECC2d::*)(const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ECC2d::SetParams, "Set params in case of empty constructor is usage.", py::arg("C1"), py::arg("C2"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"));
cls_Extrema_ECC2d.def("SetTolerance", (void (Extrema_ECC2d::*)(const Standard_Real)) &Extrema_ECC2d::SetTolerance, "None", py::arg("Tol"));
cls_Extrema_ECC2d.def("SetSingleSolutionFlag", (void (Extrema_ECC2d::*)(const Standard_Boolean)) &Extrema_ECC2d::SetSingleSolutionFlag, "Set flag for single extrema computation. Works on parametric solver only.", py::arg("theSingleSolutionFlag"));
cls_Extrema_ECC2d.def("GetSingleSolutionFlag", (Standard_Boolean (Extrema_ECC2d::*)() const) &Extrema_ECC2d::GetSingleSolutionFlag, "Get flag for single extrema computation. Works on parametric solver only.");
cls_Extrema_ECC2d.def("Perform", (void (Extrema_ECC2d::*)()) &Extrema_ECC2d::Perform, "Performs calculations.");
cls_Extrema_ECC2d.def("IsDone", (Standard_Boolean (Extrema_ECC2d::*)() const) &Extrema_ECC2d::IsDone, "Returns True if the distances are found.");
cls_Extrema_ECC2d.def("IsParallel", (Standard_Boolean (Extrema_ECC2d::*)() const) &Extrema_ECC2d::IsParallel, "Returns state of myParallel flag.");
cls_Extrema_ECC2d.def("NbExt", (Standard_Integer (Extrema_ECC2d::*)() const) &Extrema_ECC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ECC2d.def("SquareDistance", [](Extrema_ECC2d &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ECC2d.def("SquareDistance", (Standard_Real (Extrema_ECC2d::*)(const Standard_Integer) const) &Extrema_ECC2d::SquareDistance, "Returns the value of the Nth square extremum distance.", py::arg("N"));
cls_Extrema_ECC2d.def("Points", (void (Extrema_ECC2d::*)(const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_ECC2d::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_EXTPELC2D
py::class_<Extrema_ExtPElC2d> cls_Extrema_ExtPElC2d(mod, "Extrema_ExtPElC2d", "It calculates all the distances between a point and an elementary curve. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtPElC2d.def(py::init<>());
cls_Extrema_ExtPElC2d.def(py::init<const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def(py::init<const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def(py::init<const gp_Pnt2d &, const gp_Elips2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def(py::init<const gp_Pnt2d &, const gp_Hypr2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def(py::init<const gp_Pnt2d &, const gp_Parab2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));

// Methods
// cls_Extrema_ExtPElC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtPElC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtPElC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtPElC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtPElC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtPElC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtPElC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtPElC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtPElC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtPElC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtPElC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtPElC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtPElC2d.def("Perform", (void (Extrema_ExtPElC2d::*)(const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC2d::Perform, "None", py::arg("P"), py::arg("L"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def("Perform", (void (Extrema_ExtPElC2d::*)(const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC2d::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def("Perform", (void (Extrema_ExtPElC2d::*)(const gp_Pnt2d &, const gp_Elips2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC2d::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def("Perform", (void (Extrema_ExtPElC2d::*)(const gp_Pnt2d &, const gp_Hypr2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC2d::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def("Perform", (void (Extrema_ExtPElC2d::*)(const gp_Pnt2d &, const gp_Parab2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC2d::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def("IsDone", (Standard_Boolean (Extrema_ExtPElC2d::*)() const) &Extrema_ExtPElC2d::IsDone, "True if the distances are found.");
cls_Extrema_ExtPElC2d.def("NbExt", (Standard_Integer (Extrema_ExtPElC2d::*)() const) &Extrema_ExtPElC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPElC2d.def("SquareDistance", (Standard_Real (Extrema_ExtPElC2d::*)(const Standard_Integer) const) &Extrema_ExtPElC2d::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtPElC2d.def("IsMin", (Standard_Boolean (Extrema_ExtPElC2d::*)(const Standard_Integer) const) &Extrema_ExtPElC2d::IsMin, "Returns True if the Nth extremum distance is a minimum.", py::arg("N"));
cls_Extrema_ExtPElC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_ExtPElC2d::*)(const Standard_Integer) const) &Extrema_ExtPElC2d::Point, "Returns the point of the Nth extremum distance.", py::arg("N"));

// CLASS: EXTREMA_PCFOFEPCOFELPCOFLOCATEEXTPC2D
py::class_<Extrema_PCFOfEPCOfELPCOfLocateExtPC2d, math_FunctionWithDerivative> cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d(mod, "Extrema_PCFOfEPCOfELPCOfLocateExtPC2d", "None");

// Constructors
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def(py::init<>());
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &>(), py::arg("P"), py::arg("C"));

// Methods
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("Initialize", (void (Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::*)(const Adaptor2d_Curve2d &)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("SetPoint", (void (Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::*)(const gp_Pnt2d &)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("Value", [](Extrema_PCFOfEPCOfELPCOfLocateExtPC2d &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("Derivative", [](Extrema_PCFOfEPCOfELPCOfLocateExtPC2d &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("Values", [](Extrema_PCFOfEPCOfELPCOfLocateExtPC2d &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("GetStateNumber", (Standard_Integer (Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::*)()) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::GetStateNumber, "Save the found extremum.");
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("NbExt", (Standard_Integer (Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::*)() const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::NbExt, "Return the nunber of found extrema.");
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("SquareDistance", (Standard_Real (Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("IsMin", (Standard_Boolean (Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("SubIntervalInitialize", (void (Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::*)(const Standard_Real, const Standard_Real)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d.def("SearchOfTolerance", (Standard_Real (Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::*)()) &Extrema_PCFOfEPCOfELPCOfLocateExtPC2d::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// CLASS: EXTREMA_EPCOFELPCOFLOCATEEXTPC2D
py::class_<Extrema_EPCOfELPCOfLocateExtPC2d> cls_Extrema_EPCOfELPCOfLocateExtPC2d(mod, "Extrema_EPCOfELPCOfLocateExtPC2d", "None");

// Constructors
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def(py::init<>());
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));

// Methods
// cls_Extrema_EPCOfELPCOfLocateExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_EPCOfELPCOfLocateExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_EPCOfELPCOfLocateExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_EPCOfELPCOfLocateExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_EPCOfELPCOfLocateExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_EPCOfELPCOfLocateExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_EPCOfELPCOfLocateExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_EPCOfELPCOfLocateExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_EPCOfELPCOfLocateExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_EPCOfELPCOfLocateExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_EPCOfELPCOfLocateExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_EPCOfELPCOfLocateExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def("Initialize", (void (Extrema_EPCOfELPCOfLocateExtPC2d::*)(const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real)) &Extrema_EPCOfELPCOfLocateExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("NbU"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def("Initialize", (void (Extrema_EPCOfELPCOfLocateExtPC2d::*)(const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_EPCOfELPCOfLocateExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def("Initialize", (void (Extrema_EPCOfELPCOfLocateExtPC2d::*)(const Adaptor2d_Curve2d &)) &Extrema_EPCOfELPCOfLocateExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("C"));
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def("Initialize", (void (Extrema_EPCOfELPCOfLocateExtPC2d::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_EPCOfELPCOfLocateExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def("Perform", (void (Extrema_EPCOfELPCOfLocateExtPC2d::*)(const gp_Pnt2d &)) &Extrema_EPCOfELPCOfLocateExtPC2d::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def("IsDone", (Standard_Boolean (Extrema_EPCOfELPCOfLocateExtPC2d::*)() const) &Extrema_EPCOfELPCOfLocateExtPC2d::IsDone, "True if the distances are found.");
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def("NbExt", (Standard_Integer (Extrema_EPCOfELPCOfLocateExtPC2d::*)() const) &Extrema_EPCOfELPCOfLocateExtPC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def("SquareDistance", (Standard_Real (Extrema_EPCOfELPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_EPCOfELPCOfLocateExtPC2d::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def("IsMin", (Standard_Boolean (Extrema_EPCOfELPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_EPCOfELPCOfLocateExtPC2d::IsMin, "Returns True if the Nth extremum distance is a minimum.", py::arg("N"));
cls_Extrema_EPCOfELPCOfLocateExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_EPCOfELPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_EPCOfELPCOfLocateExtPC2d::Point, "Returns the point of the Nth extremum distance.", py::arg("N"));

// CLASS: EXTREMA_ELPCOFLOCATEEXTPC2D
py::class_<Extrema_ELPCOfLocateExtPC2d> cls_Extrema_ELPCOfLocateExtPC2d(mod, "Extrema_ELPCOfLocateExtPC2d", "None");

// Constructors
cls_Extrema_ELPCOfLocateExtPC2d.def(py::init<>());
cls_Extrema_ELPCOfLocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ELPCOfLocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_ELPCOfLocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &>(), py::arg("P"), py::arg("C"));
cls_Extrema_ELPCOfLocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("TolF"));

// Methods
// cls_Extrema_ELPCOfLocateExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_ELPCOfLocateExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_ELPCOfLocateExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_ELPCOfLocateExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ELPCOfLocateExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ELPCOfLocateExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ELPCOfLocateExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ELPCOfLocateExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ELPCOfLocateExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ELPCOfLocateExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ELPCOfLocateExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ELPCOfLocateExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ELPCOfLocateExtPC2d.def("Initialize", [](Extrema_ELPCOfLocateExtPC2d &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_Extrema_ELPCOfLocateExtPC2d.def("Initialize", (void (Extrema_ELPCOfLocateExtPC2d::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ELPCOfLocateExtPC2d::Initialize, "initializes the fields of the algorithm.", py::arg("C"), py::arg("Uinf"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_ELPCOfLocateExtPC2d.def("Perform", (void (Extrema_ELPCOfLocateExtPC2d::*)(const gp_Pnt2d &)) &Extrema_ELPCOfLocateExtPC2d::Perform, "An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_ELPCOfLocateExtPC2d.def("IsDone", (Standard_Boolean (Extrema_ELPCOfLocateExtPC2d::*)() const) &Extrema_ELPCOfLocateExtPC2d::IsDone, "True if the distances are found.");
cls_Extrema_ELPCOfLocateExtPC2d.def("SquareDistance", (Standard_Real (Extrema_ELPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_ELPCOfLocateExtPC2d::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
cls_Extrema_ELPCOfLocateExtPC2d.def("NbExt", (Standard_Integer (Extrema_ELPCOfLocateExtPC2d::*)() const) &Extrema_ELPCOfLocateExtPC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ELPCOfLocateExtPC2d.def("IsMin", (Standard_Boolean (Extrema_ELPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_ELPCOfLocateExtPC2d::IsMin, "Returns True if the <N>th extremum distance is a minimum.", py::arg("N"));
cls_Extrema_ELPCOfLocateExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_ELPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_ELPCOfLocateExtPC2d::Point, "Returns the point of the <N>th extremum distance.", py::arg("N"));
cls_Extrema_ELPCOfLocateExtPC2d.def("TrimmedSquareDistances", [](Extrema_ELPCOfLocateExtPC2d &self, Standard_Real & dist1, Standard_Real & dist2, gp_Pnt2d & P1, gp_Pnt2d & P2){ self.TrimmedSquareDistances(dist1, dist2, P1, P2); return std::tuple<Standard_Real &, Standard_Real &>(dist1, dist2); }, "if the curve is a trimmed curve, dist1 is a square distance between <P> and the point of parameter FirstParameter <P1> and dist2 is a square distance between <P> and the point of parameter LastParameter <P2>.", py::arg("dist1"), py::arg("dist2"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_PCFOFEPCOFEXTPC2D
py::class_<Extrema_PCFOfEPCOfExtPC2d, math_FunctionWithDerivative> cls_Extrema_PCFOfEPCOfExtPC2d(mod, "Extrema_PCFOfEPCOfExtPC2d", "None");

// Constructors
cls_Extrema_PCFOfEPCOfExtPC2d.def(py::init<>());
cls_Extrema_PCFOfEPCOfExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &>(), py::arg("P"), py::arg("C"));

// Methods
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_PCFOfEPCOfExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_PCFOfEPCOfExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_PCFOfEPCOfExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_PCFOfEPCOfExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_PCFOfEPCOfExtPC2d.def("Initialize", (void (Extrema_PCFOfEPCOfExtPC2d::*)(const Adaptor2d_Curve2d &)) &Extrema_PCFOfEPCOfExtPC2d::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("SetPoint", (void (Extrema_PCFOfEPCOfExtPC2d::*)(const gp_Pnt2d &)) &Extrema_PCFOfEPCOfExtPC2d::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("Value", [](Extrema_PCFOfEPCOfExtPC2d &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("Derivative", [](Extrema_PCFOfEPCOfExtPC2d &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("Values", [](Extrema_PCFOfEPCOfExtPC2d &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("GetStateNumber", (Standard_Integer (Extrema_PCFOfEPCOfExtPC2d::*)()) &Extrema_PCFOfEPCOfExtPC2d::GetStateNumber, "Save the found extremum.");
cls_Extrema_PCFOfEPCOfExtPC2d.def("NbExt", (Standard_Integer (Extrema_PCFOfEPCOfExtPC2d::*)() const) &Extrema_PCFOfEPCOfExtPC2d::NbExt, "Return the nunber of found extrema.");
cls_Extrema_PCFOfEPCOfExtPC2d.def("SquareDistance", (Standard_Real (Extrema_PCFOfEPCOfExtPC2d::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC2d::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("IsMin", (Standard_Boolean (Extrema_PCFOfEPCOfExtPC2d::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC2d::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_PCFOfEPCOfExtPC2d::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC2d::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("SubIntervalInitialize", (void (Extrema_PCFOfEPCOfExtPC2d::*)(const Standard_Real, const Standard_Real)) &Extrema_PCFOfEPCOfExtPC2d::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("SearchOfTolerance", (Standard_Real (Extrema_PCFOfEPCOfExtPC2d::*)()) &Extrema_PCFOfEPCOfExtPC2d::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// CLASS: EXTREMA_EPCOFEXTPC2D
py::class_<Extrema_EPCOfExtPC2d> cls_Extrema_EPCOfExtPC2d(mod, "Extrema_EPCOfExtPC2d", "None");

// Constructors
cls_Extrema_EPCOfExtPC2d.def(py::init<>());
cls_Extrema_EPCOfExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));

// Methods
// cls_Extrema_EPCOfExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_EPCOfExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_EPCOfExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_EPCOfExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_EPCOfExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_EPCOfExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_EPCOfExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_EPCOfExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_EPCOfExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_EPCOfExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_EPCOfExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_EPCOfExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_EPCOfExtPC2d.def("Initialize", (void (Extrema_EPCOfExtPC2d::*)(const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real)) &Extrema_EPCOfExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("NbU"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC2d.def("Initialize", (void (Extrema_EPCOfExtPC2d::*)(const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_EPCOfExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC2d.def("Initialize", (void (Extrema_EPCOfExtPC2d::*)(const Adaptor2d_Curve2d &)) &Extrema_EPCOfExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("C"));
cls_Extrema_EPCOfExtPC2d.def("Initialize", (void (Extrema_EPCOfExtPC2d::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_EPCOfExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC2d.def("Perform", (void (Extrema_EPCOfExtPC2d::*)(const gp_Pnt2d &)) &Extrema_EPCOfExtPC2d::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_EPCOfExtPC2d.def("IsDone", (Standard_Boolean (Extrema_EPCOfExtPC2d::*)() const) &Extrema_EPCOfExtPC2d::IsDone, "True if the distances are found.");
cls_Extrema_EPCOfExtPC2d.def("NbExt", (Standard_Integer (Extrema_EPCOfExtPC2d::*)() const) &Extrema_EPCOfExtPC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_EPCOfExtPC2d.def("SquareDistance", (Standard_Real (Extrema_EPCOfExtPC2d::*)(const Standard_Integer) const) &Extrema_EPCOfExtPC2d::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_EPCOfExtPC2d.def("IsMin", (Standard_Boolean (Extrema_EPCOfExtPC2d::*)(const Standard_Integer) const) &Extrema_EPCOfExtPC2d::IsMin, "Returns True if the Nth extremum distance is a minimum.", py::arg("N"));
cls_Extrema_EPCOfExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_EPCOfExtPC2d::*)(const Standard_Integer) const) &Extrema_EPCOfExtPC2d::Point, "Returns the point of the Nth extremum distance.", py::arg("N"));

// CLASS: EXTREMA_EXTCC2D
py::class_<Extrema_ExtCC2d> cls_Extrema_ExtCC2d(mod, "Extrema_ExtCC2d", "It calculates all the distance between two curves. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtCC2d.def(py::init<>());
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolC1"));
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolC1"), py::arg("TolC2"));
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("TolC1"));
cls_Extrema_ExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("TolC1"), py::arg("TolC2"));

// Methods
// cls_Extrema_ExtCC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtCC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtCC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtCC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtCC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtCC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtCC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtCC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtCC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtCC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtCC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtCC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtCC2d.def("Initialize", [](Extrema_ExtCC2d &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_Extrema_ExtCC2d.def("Initialize", [](Extrema_ExtCC2d &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_Extrema_ExtCC2d.def("Initialize", (void (Extrema_ExtCC2d::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtCC2d::Initialize, "initializes the fields.", py::arg("C2"), py::arg("V1"), py::arg("V2"), py::arg("TolC1"), py::arg("TolC2"));
cls_Extrema_ExtCC2d.def("Perform", (void (Extrema_ExtCC2d::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &Extrema_ExtCC2d::Perform, "None", py::arg("C1"), py::arg("U1"), py::arg("U2"));
cls_Extrema_ExtCC2d.def("IsDone", (Standard_Boolean (Extrema_ExtCC2d::*)() const) &Extrema_ExtCC2d::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtCC2d.def("NbExt", (Standard_Integer (Extrema_ExtCC2d::*)() const) &Extrema_ExtCC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtCC2d.def("IsParallel", (Standard_Boolean (Extrema_ExtCC2d::*)() const) &Extrema_ExtCC2d::IsParallel, "Returns True if the two curves are parallel.");
cls_Extrema_ExtCC2d.def("SquareDistance", [](Extrema_ExtCC2d &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtCC2d.def("SquareDistance", (Standard_Real (Extrema_ExtCC2d::*)(const Standard_Integer) const) &Extrema_ExtCC2d::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtCC2d.def("Points", (void (Extrema_ExtCC2d::*)(const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_ExtCC2d::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));
cls_Extrema_ExtCC2d.def("TrimmedSquareDistances", [](Extrema_ExtCC2d &self, Standard_Real & dist11, Standard_Real & distP12, Standard_Real & distP21, Standard_Real & distP22, gp_Pnt2d & P11, gp_Pnt2d & P12, gp_Pnt2d & P21, gp_Pnt2d & P22){ self.TrimmedSquareDistances(dist11, distP12, distP21, distP22, P11, P12, P21, P22); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(dist11, distP12, distP21, distP22); }, "if the curve is a trimmed curve, dist11 is a square distance between the point on C1 of parameter FirstParameter and the point of parameter FirstParameter on C2.", py::arg("dist11"), py::arg("distP12"), py::arg("distP21"), py::arg("distP22"), py::arg("P11"), py::arg("P12"), py::arg("P21"), py::arg("P22"));
cls_Extrema_ExtCC2d.def("SetSingleSolutionFlag", (void (Extrema_ExtCC2d::*)(const Standard_Boolean)) &Extrema_ExtCC2d::SetSingleSolutionFlag, "Set flag for single extrema computation. Works on parametric solver only.", py::arg("theSingleSolutionFlag"));
cls_Extrema_ExtCC2d.def("GetSingleSolutionFlag", (Standard_Boolean (Extrema_ExtCC2d::*)() const) &Extrema_ExtCC2d::GetSingleSolutionFlag, "Get flag for single extrema computation. Works on parametric solver only.");

// CLASS: EXTREMA_EXTELC
py::class_<Extrema_ExtElC> cls_Extrema_ExtElC(mod, "Extrema_ExtElC", "It calculates all the distance between two elementary curves. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtElC.def(py::init<>());
cls_Extrema_ExtElC.def(py::init<const gp_Lin &, const gp_Lin &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("AngTol"));
cls_Extrema_ExtElC.def(py::init<const gp_Lin &, const gp_Circ &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Tol"));
cls_Extrema_ExtElC.def(py::init<const gp_Lin &, const gp_Elips &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC.def(py::init<const gp_Lin &, const gp_Hypr &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC.def(py::init<const gp_Lin &, const gp_Parab &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC.def(py::init<const gp_Circ &, const gp_Circ &>(), py::arg("C1"), py::arg("C2"));

// Methods
// cls_Extrema_ExtElC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtElC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtElC.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtElC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtElC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtElC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtElC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtElC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtElC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtElC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtElC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtElC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtElC.def("IsDone", (Standard_Boolean (Extrema_ExtElC::*)() const) &Extrema_ExtElC::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtElC.def("IsParallel", (Standard_Boolean (Extrema_ExtElC::*)() const) &Extrema_ExtElC::IsParallel, "Returns True if the two curves are parallel.");
cls_Extrema_ExtElC.def("NbExt", (Standard_Integer (Extrema_ExtElC::*)() const) &Extrema_ExtElC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtElC.def("SquareDistance", [](Extrema_ExtElC &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtElC.def("SquareDistance", (Standard_Real (Extrema_ExtElC::*)(const Standard_Integer) const) &Extrema_ExtElC::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtElC.def("Points", (void (Extrema_ExtElC::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_ExtElC::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_EXTELC2D
py::class_<Extrema_ExtElC2d> cls_Extrema_ExtElC2d(mod, "Extrema_ExtElC2d", "It calculates all the distance between two elementary curves. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtElC2d.def(py::init<>());
cls_Extrema_ExtElC2d.def(py::init<const gp_Lin2d &, const gp_Lin2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("AngTol"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Lin2d &, const gp_Circ2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Tol"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Lin2d &, const gp_Elips2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Lin2d &, const gp_Hypr2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Lin2d &, const gp_Parab2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Circ2d &, const gp_Circ2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Circ2d &, const gp_Elips2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Circ2d &, const gp_Hypr2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Circ2d &, const gp_Parab2d &>(), py::arg("C1"), py::arg("C2"));

// Methods
// cls_Extrema_ExtElC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtElC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtElC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtElC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtElC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtElC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtElC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtElC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtElC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtElC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtElC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtElC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtElC2d.def("IsDone", (Standard_Boolean (Extrema_ExtElC2d::*)() const) &Extrema_ExtElC2d::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtElC2d.def("IsParallel", (Standard_Boolean (Extrema_ExtElC2d::*)() const) &Extrema_ExtElC2d::IsParallel, "Returns True if the two curves are parallel.");
cls_Extrema_ExtElC2d.def("NbExt", (Standard_Integer (Extrema_ExtElC2d::*)() const) &Extrema_ExtElC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtElC2d.def("SquareDistance", [](Extrema_ExtElC2d &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtElC2d.def("SquareDistance", (Standard_Real (Extrema_ExtElC2d::*)(const Standard_Integer) const) &Extrema_ExtElC2d::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtElC2d.def("Points", (void (Extrema_ExtElC2d::*)(const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_ExtElC2d::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_EXTPC2D
py::class_<Extrema_ExtPC2d> cls_Extrema_ExtPC2d(mod, "Extrema_ExtPC2d", "None");

// Constructors
cls_Extrema_ExtPC2d.def(py::init<>());
cls_Extrema_ExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Uinf"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_ExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &>(), py::arg("P"), py::arg("C"));
cls_Extrema_ExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("TolF"));

// Methods
// cls_Extrema_ExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtPC2d.def("Initialize", [](Extrema_ExtPC2d &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_Extrema_ExtPC2d.def("Initialize", (void (Extrema_ExtPC2d::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPC2d::Initialize, "initializes the fields of the algorithm.", py::arg("C"), py::arg("Uinf"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_ExtPC2d.def("Perform", (void (Extrema_ExtPC2d::*)(const gp_Pnt2d &)) &Extrema_ExtPC2d::Perform, "An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_ExtPC2d.def("IsDone", (Standard_Boolean (Extrema_ExtPC2d::*)() const) &Extrema_ExtPC2d::IsDone, "True if the distances are found.");
cls_Extrema_ExtPC2d.def("SquareDistance", (Standard_Real (Extrema_ExtPC2d::*)(const Standard_Integer) const) &Extrema_ExtPC2d::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
cls_Extrema_ExtPC2d.def("NbExt", (Standard_Integer (Extrema_ExtPC2d::*)() const) &Extrema_ExtPC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPC2d.def("IsMin", (Standard_Boolean (Extrema_ExtPC2d::*)(const Standard_Integer) const) &Extrema_ExtPC2d::IsMin, "Returns True if the <N>th extremum distance is a minimum.", py::arg("N"));
cls_Extrema_ExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_ExtPC2d::*)(const Standard_Integer) const) &Extrema_ExtPC2d::Point, "Returns the point of the <N>th extremum distance.", py::arg("N"));
cls_Extrema_ExtPC2d.def("TrimmedSquareDistances", [](Extrema_ExtPC2d &self, Standard_Real & dist1, Standard_Real & dist2, gp_Pnt2d & P1, gp_Pnt2d & P2){ self.TrimmedSquareDistances(dist1, dist2, P1, P2); return std::tuple<Standard_Real &, Standard_Real &>(dist1, dist2); }, "if the curve is a trimmed curve, dist1 is a square distance between <P> and the point of parameter FirstParameter <P1> and dist2 is a square distance between <P> and the point of parameter LastParameter <P2>.", py::arg("dist1"), py::arg("dist2"), py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_EXTPEXTS
py::class_<Extrema_ExtPExtS, opencascade::handle<Extrema_ExtPExtS>, Standard_Transient> cls_Extrema_ExtPExtS(mod, "Extrema_ExtPExtS", "It calculates all the extremum (minimum and maximum) distances between a point and a linear extrusion surface.");

// Constructors
cls_Extrema_ExtPExtS.def(py::init<>());
cls_Extrema_ExtPExtS.def(py::init<const gp_Pnt &, const opencascade::handle<GeomAdaptor_HSurfaceOfLinearExtrusion> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPExtS.def(py::init<const gp_Pnt &, const opencascade::handle<GeomAdaptor_HSurfaceOfLinearExtrusion> &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("TolU"), py::arg("TolV"));

// Methods
cls_Extrema_ExtPExtS.def("Initialize", (void (Extrema_ExtPExtS::*)(const opencascade::handle<GeomAdaptor_HSurfaceOfLinearExtrusion> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPExtS::Initialize, "Initializes the fields of the algorithm.", py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPExtS.def("Perform", (void (Extrema_ExtPExtS::*)(const gp_Pnt &)) &Extrema_ExtPExtS::Perform, "None", py::arg("P"));
cls_Extrema_ExtPExtS.def("IsDone", (Standard_Boolean (Extrema_ExtPExtS::*)() const) &Extrema_ExtPExtS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtPExtS.def("NbExt", (Standard_Integer (Extrema_ExtPExtS::*)() const) &Extrema_ExtPExtS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPExtS.def("SquareDistance", (Standard_Real (Extrema_ExtPExtS::*)(const Standard_Integer) const) &Extrema_ExtPExtS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtPExtS.def("Point", (const Extrema_POnSurf & (Extrema_ExtPExtS::*)(const Standard_Integer) const) &Extrema_ExtPExtS::Point, "Returns the point of the Nth resulting distance.", py::arg("N"));
cls_Extrema_ExtPExtS.def_static("get_type_name_", (const char * (*)()) &Extrema_ExtPExtS::get_type_name, "None");
cls_Extrema_ExtPExtS.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_ExtPExtS::get_type_descriptor, "None");
cls_Extrema_ExtPExtS.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_ExtPExtS::*)() const) &Extrema_ExtPExtS::DynamicType, "None");

// CLASS: EXTREMA_EXTPREVS
py::class_<Extrema_ExtPRevS, opencascade::handle<Extrema_ExtPRevS>, Standard_Transient> cls_Extrema_ExtPRevS(mod, "Extrema_ExtPRevS", "It calculates all the extremum (minimum and maximum) distances between a point and a surface of revolution.");

// Constructors
cls_Extrema_ExtPRevS.def(py::init<>());
cls_Extrema_ExtPRevS.def(py::init<const gp_Pnt &, const opencascade::handle<GeomAdaptor_HSurfaceOfRevolution> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPRevS.def(py::init<const gp_Pnt &, const opencascade::handle<GeomAdaptor_HSurfaceOfRevolution> &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("TolU"), py::arg("TolV"));

// Methods
cls_Extrema_ExtPRevS.def("Initialize", (void (Extrema_ExtPRevS::*)(const opencascade::handle<GeomAdaptor_HSurfaceOfRevolution> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPRevS::Initialize, "None", py::arg("S"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPRevS.def("Perform", (void (Extrema_ExtPRevS::*)(const gp_Pnt &)) &Extrema_ExtPRevS::Perform, "None", py::arg("P"));
cls_Extrema_ExtPRevS.def("IsDone", (Standard_Boolean (Extrema_ExtPRevS::*)() const) &Extrema_ExtPRevS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtPRevS.def("NbExt", (Standard_Integer (Extrema_ExtPRevS::*)() const) &Extrema_ExtPRevS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPRevS.def("SquareDistance", (Standard_Real (Extrema_ExtPRevS::*)(const Standard_Integer) const) &Extrema_ExtPRevS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtPRevS.def("Point", (const Extrema_POnSurf & (Extrema_ExtPRevS::*)(const Standard_Integer) const) &Extrema_ExtPRevS::Point, "Returns the point of the Nth resulting distance.", py::arg("N"));
cls_Extrema_ExtPRevS.def_static("get_type_name_", (const char * (*)()) &Extrema_ExtPRevS::get_type_name, "None");
cls_Extrema_ExtPRevS.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_ExtPRevS::get_type_descriptor, "None");
cls_Extrema_ExtPRevS.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_ExtPRevS::*)() const) &Extrema_ExtPRevS::DynamicType, "None");

// CLASS: EXTREMA_FUNCEXTCS
py::class_<Extrema_FuncExtCS, math_FunctionSetWithDerivatives> cls_Extrema_FuncExtCS(mod, "Extrema_FuncExtCS", "Function to find extrema of the distance between a curve and a surface.");

// Constructors
cls_Extrema_FuncExtCS.def(py::init<>());
cls_Extrema_FuncExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &>(), py::arg("C"), py::arg("S"));

// Methods
// cls_Extrema_FuncExtCS.def_static("operator new_", (void * (*)(size_t)) &Extrema_FuncExtCS::operator new, "None", py::arg("theSize"));
// cls_Extrema_FuncExtCS.def_static("operator delete_", (void (*)(void *)) &Extrema_FuncExtCS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_FuncExtCS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_FuncExtCS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_FuncExtCS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_FuncExtCS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_FuncExtCS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_FuncExtCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_FuncExtCS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_FuncExtCS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_FuncExtCS.def("Initialize", (void (Extrema_FuncExtCS::*)(const Adaptor3d_Curve &, const Adaptor3d_Surface &)) &Extrema_FuncExtCS::Initialize, "sets the field mysurf of the function.", py::arg("C"), py::arg("S"));
cls_Extrema_FuncExtCS.def("NbVariables", (Standard_Integer (Extrema_FuncExtCS::*)() const) &Extrema_FuncExtCS::NbVariables, "None");
cls_Extrema_FuncExtCS.def("NbEquations", (Standard_Integer (Extrema_FuncExtCS::*)() const) &Extrema_FuncExtCS::NbEquations, "None");
cls_Extrema_FuncExtCS.def("Value", (Standard_Boolean (Extrema_FuncExtCS::*)(const math_Vector &, math_Vector &)) &Extrema_FuncExtCS::Value, "Calculation of Fi(U,V).", py::arg("UV"), py::arg("F"));
cls_Extrema_FuncExtCS.def("Derivatives", (Standard_Boolean (Extrema_FuncExtCS::*)(const math_Vector &, math_Matrix &)) &Extrema_FuncExtCS::Derivatives, "Calculation of Fi'(U,V).", py::arg("UV"), py::arg("DF"));
cls_Extrema_FuncExtCS.def("Values", (Standard_Boolean (Extrema_FuncExtCS::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Extrema_FuncExtCS::Values, "Calculation of Fi(U,V) and Fi'(U,V).", py::arg("UV"), py::arg("F"), py::arg("DF"));
cls_Extrema_FuncExtCS.def("GetStateNumber", (Standard_Integer (Extrema_FuncExtCS::*)()) &Extrema_FuncExtCS::GetStateNumber, "Save the found extremum.");
cls_Extrema_FuncExtCS.def("NbExt", (Standard_Integer (Extrema_FuncExtCS::*)() const) &Extrema_FuncExtCS::NbExt, "Return the number of found extrema.");
cls_Extrema_FuncExtCS.def("SquareDistance", (Standard_Real (Extrema_FuncExtCS::*)(const Standard_Integer) const) &Extrema_FuncExtCS::SquareDistance, "Return the value of the Nth distance.", py::arg("N"));
cls_Extrema_FuncExtCS.def("PointOnCurve", (const Extrema_POnCurv & (Extrema_FuncExtCS::*)(const Standard_Integer) const) &Extrema_FuncExtCS::PointOnCurve, "Returns the Nth extremum on C.", py::arg("N"));
cls_Extrema_FuncExtCS.def("PointOnSurface", (const Extrema_POnSurf & (Extrema_FuncExtCS::*)(const Standard_Integer) const) &Extrema_FuncExtCS::PointOnSurface, "Return the Nth extremum on S.", py::arg("N"));

// CLASS: EXTREMA_FUNCEXTSS
py::class_<Extrema_FuncExtSS, math_FunctionSetWithDerivatives> cls_Extrema_FuncExtSS(mod, "Extrema_FuncExtSS", "Function to find extrema of the distance between two surfaces.");

// Constructors
cls_Extrema_FuncExtSS.def(py::init<>());
cls_Extrema_FuncExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &>(), py::arg("S1"), py::arg("S2"));

// Methods
// cls_Extrema_FuncExtSS.def_static("operator new_", (void * (*)(size_t)) &Extrema_FuncExtSS::operator new, "None", py::arg("theSize"));
// cls_Extrema_FuncExtSS.def_static("operator delete_", (void (*)(void *)) &Extrema_FuncExtSS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_FuncExtSS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_FuncExtSS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_FuncExtSS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_FuncExtSS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_FuncExtSS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_FuncExtSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_FuncExtSS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_FuncExtSS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_FuncExtSS.def("Initialize", (void (Extrema_FuncExtSS::*)(const Adaptor3d_Surface &, const Adaptor3d_Surface &)) &Extrema_FuncExtSS::Initialize, "sets the field mysurf of the function.", py::arg("S1"), py::arg("S2"));
cls_Extrema_FuncExtSS.def("NbVariables", (Standard_Integer (Extrema_FuncExtSS::*)() const) &Extrema_FuncExtSS::NbVariables, "None");
cls_Extrema_FuncExtSS.def("NbEquations", (Standard_Integer (Extrema_FuncExtSS::*)() const) &Extrema_FuncExtSS::NbEquations, "None");
cls_Extrema_FuncExtSS.def("Value", (Standard_Boolean (Extrema_FuncExtSS::*)(const math_Vector &, math_Vector &)) &Extrema_FuncExtSS::Value, "Calculate Fi(U,V).", py::arg("UV"), py::arg("F"));
cls_Extrema_FuncExtSS.def("Derivatives", (Standard_Boolean (Extrema_FuncExtSS::*)(const math_Vector &, math_Matrix &)) &Extrema_FuncExtSS::Derivatives, "Calculate Fi'(U,V).", py::arg("UV"), py::arg("DF"));
cls_Extrema_FuncExtSS.def("Values", (Standard_Boolean (Extrema_FuncExtSS::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Extrema_FuncExtSS::Values, "Calculate Fi(U,V) and Fi'(U,V).", py::arg("UV"), py::arg("F"), py::arg("DF"));
cls_Extrema_FuncExtSS.def("GetStateNumber", (Standard_Integer (Extrema_FuncExtSS::*)()) &Extrema_FuncExtSS::GetStateNumber, "Save the found extremum.");
cls_Extrema_FuncExtSS.def("NbExt", (Standard_Integer (Extrema_FuncExtSS::*)() const) &Extrema_FuncExtSS::NbExt, "Return the number of found extrema.");
cls_Extrema_FuncExtSS.def("SquareDistance", (Standard_Real (Extrema_FuncExtSS::*)(const Standard_Integer) const) &Extrema_FuncExtSS::SquareDistance, "Return the value of the Nth distance.", py::arg("N"));
cls_Extrema_FuncExtSS.def("PointOnS1", (const Extrema_POnSurf & (Extrema_FuncExtSS::*)(const Standard_Integer) const) &Extrema_FuncExtSS::PointOnS1, "Return the Nth extremum on S1.", py::arg("N"));
cls_Extrema_FuncExtSS.def("PointOnS2", (const Extrema_POnSurf & (Extrema_FuncExtSS::*)(const Standard_Integer) const) &Extrema_FuncExtSS::PointOnS2, "Renvoie le Nieme extremum sur S2.", py::arg("N"));

// CLASS: EXTREMA_FUNCPSDIST
py::class_<Extrema_FuncPSDist, math_MultipleVarFunctionWithGradient> cls_Extrema_FuncPSDist(mod, "Extrema_FuncPSDist", "Functional for search of extremum of the square Euclidean distance between point P and surface S, starting from approximate solution (u0, v0).");

// Constructors
cls_Extrema_FuncPSDist.def(py::init<const Adaptor3d_Surface &, const gp_Pnt &>(), py::arg("theS"), py::arg("theP"));

// Methods
// cls_Extrema_FuncPSDist.def_static("operator new_", (void * (*)(size_t)) &Extrema_FuncPSDist::operator new, "None", py::arg("theSize"));
// cls_Extrema_FuncPSDist.def_static("operator delete_", (void (*)(void *)) &Extrema_FuncPSDist::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_FuncPSDist.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_FuncPSDist::operator new[], "None", py::arg("theSize"));
// cls_Extrema_FuncPSDist.def_static("operator delete[]_", (void (*)(void *)) &Extrema_FuncPSDist::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_FuncPSDist.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_FuncPSDist::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_FuncPSDist.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_FuncPSDist::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_FuncPSDist.def("NbVariables", (Standard_Integer (Extrema_FuncPSDist::*)() const) &Extrema_FuncPSDist::NbVariables, "Number of variables.");
cls_Extrema_FuncPSDist.def("Value", [](Extrema_FuncPSDist &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Value.", py::arg("X"), py::arg("F"));
cls_Extrema_FuncPSDist.def("Gradient", (Standard_Boolean (Extrema_FuncPSDist::*)(const math_Vector &, math_Vector &)) &Extrema_FuncPSDist::Gradient, "Gradient.", py::arg("X"), py::arg("G"));
cls_Extrema_FuncPSDist.def("Values", [](Extrema_FuncPSDist &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Value and gradient.", py::arg("X"), py::arg("F"), py::arg("G"));

// CLASS: EXTREMA_GENEXTCS
py::class_<Extrema_GenExtCS> cls_Extrema_GenExtCS(mod, "Extrema_GenExtCS", "It calculates all the extremum distances between acurve and a surface. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_GenExtCS.def(py::init<>());
cls_Extrema_GenExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("NbT"), py::arg("NbU"), py::arg("NbV"), py::arg("Tol1"), py::arg("Tol2"));
cls_Extrema_GenExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("NbT"), py::arg("NbU"), py::arg("NbV"), py::arg("tmin"), py::arg("tsup"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tol1"), py::arg("Tol2"));

// Methods
// cls_Extrema_GenExtCS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenExtCS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenExtCS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenExtCS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenExtCS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenExtCS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenExtCS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenExtCS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenExtCS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenExtCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenExtCS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenExtCS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenExtCS.def("Initialize", (void (Extrema_GenExtCS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real)) &Extrema_GenExtCS::Initialize, "None", py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Tol2"));
cls_Extrema_GenExtCS.def("Initialize", (void (Extrema_GenExtCS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenExtCS::Initialize, "None", py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tol2"));
cls_Extrema_GenExtCS.def("Perform", (void (Extrema_GenExtCS::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real)) &Extrema_GenExtCS::Perform, "the algorithm is done with S An exception is raised if the fields have not been initialized.", py::arg("C"), py::arg("NbT"), py::arg("Tol1"));
cls_Extrema_GenExtCS.def("Perform", (void (Extrema_GenExtCS::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenExtCS::Perform, "the algorithm is done with C An exception is raised if the fields have not been initialized.", py::arg("C"), py::arg("NbT"), py::arg("tmin"), py::arg("tsup"), py::arg("Tol1"));
cls_Extrema_GenExtCS.def("IsDone", (Standard_Boolean (Extrema_GenExtCS::*)() const) &Extrema_GenExtCS::IsDone, "Returns True if the distances are found.");
cls_Extrema_GenExtCS.def("NbExt", (Standard_Integer (Extrema_GenExtCS::*)() const) &Extrema_GenExtCS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_GenExtCS.def("SquareDistance", (Standard_Real (Extrema_GenExtCS::*)(const Standard_Integer) const) &Extrema_GenExtCS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_GenExtCS.def("PointOnCurve", (const Extrema_POnCurv & (Extrema_GenExtCS::*)(const Standard_Integer) const) &Extrema_GenExtCS::PointOnCurve, "Returns the point of the Nth resulting distance.", py::arg("N"));
cls_Extrema_GenExtCS.def("PointOnSurface", (const Extrema_POnSurf & (Extrema_GenExtCS::*)(const Standard_Integer) const) &Extrema_GenExtCS::PointOnSurface, "Returns the point of the Nth resulting distance.", py::arg("N"));

// CLASS: EXTREMA_GENEXTSS
py::class_<Extrema_GenExtSS> cls_Extrema_GenExtSS(mod, "Extrema_GenExtSS", "It calculates all the extremum distances between two surfaces. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_GenExtSS.def(py::init<>());
cls_Extrema_GenExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("NbU"), py::arg("NbV"), py::arg("Tol1"), py::arg("Tol2"));
cls_Extrema_GenExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("NbU"), py::arg("NbV"), py::arg("U1min"), py::arg("U1sup"), py::arg("V1min"), py::arg("V1sup"), py::arg("U2min"), py::arg("U2sup"), py::arg("V2min"), py::arg("V2sup"), py::arg("Tol1"), py::arg("Tol2"));

// Methods
// cls_Extrema_GenExtSS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenExtSS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenExtSS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenExtSS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenExtSS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenExtSS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenExtSS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenExtSS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenExtSS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenExtSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenExtSS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenExtSS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenExtSS.def("Initialize", (void (Extrema_GenExtSS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real)) &Extrema_GenExtSS::Initialize, "None", py::arg("S2"), py::arg("NbU"), py::arg("NbV"), py::arg("Tol2"));
cls_Extrema_GenExtSS.def("Initialize", (void (Extrema_GenExtSS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenExtSS::Initialize, "None", py::arg("S2"), py::arg("NbU"), py::arg("NbV"), py::arg("U2min"), py::arg("U2sup"), py::arg("V2min"), py::arg("V2sup"), py::arg("Tol2"));
cls_Extrema_GenExtSS.def("Perform", (void (Extrema_GenExtSS::*)(const Adaptor3d_Surface &, const Standard_Real)) &Extrema_GenExtSS::Perform, "the algorithm is done with S1 An exception is raised if the fields have not been initialized.", py::arg("S1"), py::arg("Tol1"));
cls_Extrema_GenExtSS.def("Perform", (void (Extrema_GenExtSS::*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenExtSS::Perform, "the algorithm is done withS1 An exception is raised if the fields have not been initialized.", py::arg("S1"), py::arg("U1min"), py::arg("U1sup"), py::arg("V1min"), py::arg("V1sup"), py::arg("Tol1"));
cls_Extrema_GenExtSS.def("IsDone", (Standard_Boolean (Extrema_GenExtSS::*)() const) &Extrema_GenExtSS::IsDone, "Returns True if the distances are found.");
cls_Extrema_GenExtSS.def("NbExt", (Standard_Integer (Extrema_GenExtSS::*)() const) &Extrema_GenExtSS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_GenExtSS.def("SquareDistance", (Standard_Real (Extrema_GenExtSS::*)(const Standard_Integer) const) &Extrema_GenExtSS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_GenExtSS.def("PointOnS1", (const Extrema_POnSurf & (Extrema_GenExtSS::*)(const Standard_Integer) const) &Extrema_GenExtSS::PointOnS1, "Returns the point of the Nth resulting distance.", py::arg("N"));
cls_Extrema_GenExtSS.def("PointOnS2", (const Extrema_POnSurf & (Extrema_GenExtSS::*)(const Standard_Integer) const) &Extrema_GenExtSS::PointOnS2, "Returns the point of the Nth resulting distance.", py::arg("N"));

// CLASS: EXTREMA_GENLOCATEEXTCS
py::class_<Extrema_GenLocateExtCS> cls_Extrema_GenLocateExtCS(mod, "Extrema_GenLocateExtCS", "With two close points it calculates the distance between two surfaces. This distance can be a minimum or a maximum.");

// Constructors
cls_Extrema_GenLocateExtCS.def(py::init<>());
cls_Extrema_GenLocateExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("T"), py::arg("U"), py::arg("V"), py::arg("Tol1"), py::arg("Tol2"));

// Methods
// cls_Extrema_GenLocateExtCS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenLocateExtCS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtCS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenLocateExtCS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtCS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenLocateExtCS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtCS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenLocateExtCS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtCS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenLocateExtCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenLocateExtCS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenLocateExtCS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenLocateExtCS.def("Perform", (void (Extrema_GenLocateExtCS::*)(const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenLocateExtCS::Perform, "None", py::arg("C"), py::arg("S"), py::arg("T"), py::arg("U"), py::arg("V"), py::arg("Tol1"), py::arg("Tol2"));
cls_Extrema_GenLocateExtCS.def("IsDone", (Standard_Boolean (Extrema_GenLocateExtCS::*)() const) &Extrema_GenLocateExtCS::IsDone, "Returns True if the distance is found.");
cls_Extrema_GenLocateExtCS.def("SquareDistance", (Standard_Real (Extrema_GenLocateExtCS::*)() const) &Extrema_GenLocateExtCS::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_GenLocateExtCS.def("PointOnCurve", (const Extrema_POnCurv & (Extrema_GenLocateExtCS::*)() const) &Extrema_GenLocateExtCS::PointOnCurve, "Returns the point of the extremum distance on C.");
cls_Extrema_GenLocateExtCS.def("PointOnSurface", (const Extrema_POnSurf & (Extrema_GenLocateExtCS::*)() const) &Extrema_GenLocateExtCS::PointOnSurface, "Returns the point of the extremum distance on S.");

// CLASS: EXTREMA_GENLOCATEEXTPS
py::class_<Extrema_GenLocateExtPS> cls_Extrema_GenLocateExtPS(mod, "Extrema_GenLocateExtPS", "With a close point, it calculates the distance between a point and a surface. Criteria type is defined in 'Perform' method.");

// Constructors
cls_Extrema_GenLocateExtPS.def(py::init<const Adaptor3d_Surface &>(), py::arg("theS"));
cls_Extrema_GenLocateExtPS.def(py::init<const Adaptor3d_Surface &, const Standard_Real>(), py::arg("theS"), py::arg("theTolU"));
cls_Extrema_GenLocateExtPS.def(py::init<const Adaptor3d_Surface &, const Standard_Real, const Standard_Real>(), py::arg("theS"), py::arg("theTolU"), py::arg("theTolV"));

// Methods
// cls_Extrema_GenLocateExtPS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenLocateExtPS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtPS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenLocateExtPS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtPS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenLocateExtPS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtPS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenLocateExtPS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtPS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenLocateExtPS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenLocateExtPS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenLocateExtPS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenLocateExtPS.def("Perform", [](Extrema_GenLocateExtPS &self, const gp_Pnt & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); });
cls_Extrema_GenLocateExtPS.def("Perform", (void (Extrema_GenLocateExtPS::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Extrema_GenLocateExtPS::Perform, "Calculates the extrema between the point and the surface using a close point. The close point is defined by the parameter values theU0 and theV0. Type of the algorithm depends on the isDistanceCriteria flag. If flag value is false - normal projection criteria will be used. If flag value is true - distance criteria will be used.", py::arg("theP"), py::arg("theU0"), py::arg("theV0"), py::arg("isDistanceCriteria"));
cls_Extrema_GenLocateExtPS.def("IsDone", (Standard_Boolean (Extrema_GenLocateExtPS::*)() const) &Extrema_GenLocateExtPS::IsDone, "Returns True if the distance is found.");
cls_Extrema_GenLocateExtPS.def("SquareDistance", (Standard_Real (Extrema_GenLocateExtPS::*)() const) &Extrema_GenLocateExtPS::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_GenLocateExtPS.def("Point", (const Extrema_POnSurf & (Extrema_GenLocateExtPS::*)() const) &Extrema_GenLocateExtPS::Point, "Returns the point of the extremum distance.");

// CLASS: EXTREMA_GENLOCATEEXTSS
py::class_<Extrema_GenLocateExtSS> cls_Extrema_GenLocateExtSS(mod, "Extrema_GenLocateExtSS", "With two close points it calculates the distance between two surfaces. This distance can be a minimum or a maximum.");

// Constructors
cls_Extrema_GenLocateExtSS.def(py::init<>());
cls_Extrema_GenLocateExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Tol1"), py::arg("Tol2"));

// Methods
// cls_Extrema_GenLocateExtSS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenLocateExtSS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtSS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenLocateExtSS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtSS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenLocateExtSS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtSS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenLocateExtSS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtSS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenLocateExtSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenLocateExtSS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenLocateExtSS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenLocateExtSS.def("Perform", (void (Extrema_GenLocateExtSS::*)(const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenLocateExtSS::Perform, "None", py::arg("S1"), py::arg("S2"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Tol1"), py::arg("Tol2"));
cls_Extrema_GenLocateExtSS.def("IsDone", (Standard_Boolean (Extrema_GenLocateExtSS::*)() const) &Extrema_GenLocateExtSS::IsDone, "Returns True if the distance is found.");
cls_Extrema_GenLocateExtSS.def("SquareDistance", (Standard_Real (Extrema_GenLocateExtSS::*)() const) &Extrema_GenLocateExtSS::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_GenLocateExtSS.def("PointOnS1", (const Extrema_POnSurf & (Extrema_GenLocateExtSS::*)() const) &Extrema_GenLocateExtSS::PointOnS1, "Returns the point of the extremum distance on S1.");
cls_Extrema_GenLocateExtSS.def("PointOnS2", (const Extrema_POnSurf & (Extrema_GenLocateExtSS::*)() const) &Extrema_GenLocateExtSS::PointOnS2, "Returns the point of the extremum distance on S2.");

// CLASS: EXTREMA_GLOBOPTFUNCCCC0
py::class_<Extrema_GlobOptFuncCCC0, math_MultipleVarFunction> cls_Extrema_GlobOptFuncCCC0(mod, "Extrema_GlobOptFuncCCC0", "This class implements function which calculate Eucluidean distance between point on curve and point on other curve in case of C1 and C2 continuity is C0.");

// Constructors
cls_Extrema_GlobOptFuncCCC0.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_GlobOptFuncCCC0.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("C1"), py::arg("C2"));

// Methods
cls_Extrema_GlobOptFuncCCC0.def("NbVariables", (Standard_Integer (Extrema_GlobOptFuncCCC0::*)() const) &Extrema_GlobOptFuncCCC0::NbVariables, "None");
cls_Extrema_GlobOptFuncCCC0.def("Value", [](Extrema_GlobOptFuncCCC0 &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));

// CLASS: EXTREMA_GLOBOPTFUNCCCC1
py::class_<Extrema_GlobOptFuncCCC1, math_MultipleVarFunctionWithGradient> cls_Extrema_GlobOptFuncCCC1(mod, "Extrema_GlobOptFuncCCC1", "This class implements function which calculate Eucluidean distance between point on curve and point on other curve in case of C1 and C2 continuity is C1.");

// Constructors
cls_Extrema_GlobOptFuncCCC1.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_GlobOptFuncCCC1.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("C1"), py::arg("C2"));

// Methods
cls_Extrema_GlobOptFuncCCC1.def("NbVariables", (Standard_Integer (Extrema_GlobOptFuncCCC1::*)() const) &Extrema_GlobOptFuncCCC1::NbVariables, "None");
cls_Extrema_GlobOptFuncCCC1.def("Value", [](Extrema_GlobOptFuncCCC1 &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));
cls_Extrema_GlobOptFuncCCC1.def("Gradient", (Standard_Boolean (Extrema_GlobOptFuncCCC1::*)(const math_Vector &, math_Vector &)) &Extrema_GlobOptFuncCCC1::Gradient, "None", py::arg("X"), py::arg("G"));
cls_Extrema_GlobOptFuncCCC1.def("Values", [](Extrema_GlobOptFuncCCC1 &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"), py::arg("G"));

// CLASS: EXTREMA_GLOBOPTFUNCCCC2
py::class_<Extrema_GlobOptFuncCCC2, math_MultipleVarFunctionWithHessian> cls_Extrema_GlobOptFuncCCC2(mod, "Extrema_GlobOptFuncCCC2", "This class implements function which calculate Eucluidean distance between point on curve and point on other curve in case of C1 and C2 continuity is C2.");

// Constructors
cls_Extrema_GlobOptFuncCCC2.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_GlobOptFuncCCC2.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("C1"), py::arg("C2"));

// Methods
cls_Extrema_GlobOptFuncCCC2.def("NbVariables", (Standard_Integer (Extrema_GlobOptFuncCCC2::*)() const) &Extrema_GlobOptFuncCCC2::NbVariables, "None");
cls_Extrema_GlobOptFuncCCC2.def("Value", [](Extrema_GlobOptFuncCCC2 &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));
cls_Extrema_GlobOptFuncCCC2.def("Gradient", (Standard_Boolean (Extrema_GlobOptFuncCCC2::*)(const math_Vector &, math_Vector &)) &Extrema_GlobOptFuncCCC2::Gradient, "None", py::arg("X"), py::arg("G"));
cls_Extrema_GlobOptFuncCCC2.def("Values", [](Extrema_GlobOptFuncCCC2 &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"), py::arg("G"));
cls_Extrema_GlobOptFuncCCC2.def("Values", [](Extrema_GlobOptFuncCCC2 &self, const math_Vector & X, Standard_Real & F, math_Vector & G, math_Matrix & H){ Standard_Boolean rv = self.Values(X, F, G, H); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"), py::arg("G"), py::arg("H"));

// CLASS: EXTREMA_GLOBOPTFUNCCS
py::class_<Extrema_GlobOptFuncCS, math_MultipleVarFunctionWithHessian> cls_Extrema_GlobOptFuncCS(mod, "Extrema_GlobOptFuncCS", "This class implements function which calculate square Eucluidean distance between point on curve and point on surface in case of continuity is C2.");

// Constructors
cls_Extrema_GlobOptFuncCS.def(py::init<const Adaptor3d_Curve *, const Adaptor3d_Surface *>(), py::arg("C"), py::arg("S"));

// Methods
cls_Extrema_GlobOptFuncCS.def("NbVariables", (Standard_Integer (Extrema_GlobOptFuncCS::*)() const) &Extrema_GlobOptFuncCS::NbVariables, "None");
cls_Extrema_GlobOptFuncCS.def("Value", [](Extrema_GlobOptFuncCS &self, const math_Vector & theX, Standard_Real & theF){ Standard_Boolean rv = self.Value(theX, theF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theF); }, "None", py::arg("theX"), py::arg("theF"));
cls_Extrema_GlobOptFuncCS.def("Gradient", (Standard_Boolean (Extrema_GlobOptFuncCS::*)(const math_Vector &, math_Vector &)) &Extrema_GlobOptFuncCS::Gradient, "None", py::arg("theX"), py::arg("theG"));
cls_Extrema_GlobOptFuncCS.def("Values", [](Extrema_GlobOptFuncCS &self, const math_Vector & theX, Standard_Real & theF, math_Vector & theG){ Standard_Boolean rv = self.Values(theX, theF, theG); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theF); }, "None", py::arg("theX"), py::arg("theF"), py::arg("theG"));
cls_Extrema_GlobOptFuncCS.def("Values", [](Extrema_GlobOptFuncCS &self, const math_Vector & theX, Standard_Real & theF, math_Vector & theG, math_Matrix & theH){ Standard_Boolean rv = self.Values(theX, theF, theG, theH); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theF); }, "None", py::arg("theX"), py::arg("theF"), py::arg("theG"), py::arg("theH"));

// CLASS: EXTREMA_HARRAY1OFPONCURV2D
py::class_<Extrema_HArray1OfPOnCurv2d, opencascade::handle<Extrema_HArray1OfPOnCurv2d>, Standard_Transient> cls_Extrema_HArray1OfPOnCurv2d(mod, "Extrema_HArray1OfPOnCurv2d", "None", py::multiple_inheritance());

// Constructors
cls_Extrema_HArray1OfPOnCurv2d.def(py::init<>());
cls_Extrema_HArray1OfPOnCurv2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Extrema_HArray1OfPOnCurv2d.def(py::init<const Standard_Integer, const Standard_Integer, const Extrema_Array1OfPOnCurv2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Extrema_HArray1OfPOnCurv2d.def(py::init<const Extrema_Array1OfPOnCurv2d &>(), py::arg("theOther"));

// Methods
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_HArray1OfPOnCurv2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator delete_", (void (*)(void *)) &Extrema_HArray1OfPOnCurv2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_HArray1OfPOnCurv2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_HArray1OfPOnCurv2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_HArray1OfPOnCurv2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_HArray1OfPOnCurv2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray1OfPOnCurv2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray1OfPOnCurv2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Extrema_HArray1OfPOnCurv2d.def("Array1", (const Extrema_Array1OfPOnCurv2d & (Extrema_HArray1OfPOnCurv2d::*)() const) &Extrema_HArray1OfPOnCurv2d::Array1, "None");
cls_Extrema_HArray1OfPOnCurv2d.def("ChangeArray1", (Extrema_Array1OfPOnCurv2d & (Extrema_HArray1OfPOnCurv2d::*)()) &Extrema_HArray1OfPOnCurv2d::ChangeArray1, "None");
cls_Extrema_HArray1OfPOnCurv2d.def_static("get_type_name_", (const char * (*)()) &Extrema_HArray1OfPOnCurv2d::get_type_name, "None");
cls_Extrema_HArray1OfPOnCurv2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_HArray1OfPOnCurv2d::get_type_descriptor, "None");
cls_Extrema_HArray1OfPOnCurv2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_HArray1OfPOnCurv2d::*)() const) &Extrema_HArray1OfPOnCurv2d::DynamicType, "None");

// CLASS: EXTREMA_HARRAY2OFPONCURV
py::class_<Extrema_HArray2OfPOnCurv, opencascade::handle<Extrema_HArray2OfPOnCurv>, Standard_Transient> cls_Extrema_HArray2OfPOnCurv(mod, "Extrema_HArray2OfPOnCurv", "None", py::multiple_inheritance());

// Constructors
cls_Extrema_HArray2OfPOnCurv.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_Extrema_HArray2OfPOnCurv.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Extrema_Array2OfPOnCurv::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_Extrema_HArray2OfPOnCurv.def(py::init<const Extrema_Array2OfPOnCurv &>(), py::arg("theOther"));

// Methods
// cls_Extrema_HArray2OfPOnCurv.def_static("operator new_", (void * (*)(size_t)) &Extrema_HArray2OfPOnCurv::operator new, "None", py::arg("theSize"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator delete_", (void (*)(void *)) &Extrema_HArray2OfPOnCurv::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_HArray2OfPOnCurv::operator new[], "None", py::arg("theSize"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator delete[]_", (void (*)(void *)) &Extrema_HArray2OfPOnCurv::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_HArray2OfPOnCurv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_HArray2OfPOnCurv::operator delete, "None", py::arg(""), py::arg(""));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray2OfPOnCurv::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray2OfPOnCurv::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Extrema_HArray2OfPOnCurv.def("Array2", (const Extrema_Array2OfPOnCurv & (Extrema_HArray2OfPOnCurv::*)() const) &Extrema_HArray2OfPOnCurv::Array2, "None");
cls_Extrema_HArray2OfPOnCurv.def("ChangeArray2", (Extrema_Array2OfPOnCurv & (Extrema_HArray2OfPOnCurv::*)()) &Extrema_HArray2OfPOnCurv::ChangeArray2, "None");
cls_Extrema_HArray2OfPOnCurv.def_static("get_type_name_", (const char * (*)()) &Extrema_HArray2OfPOnCurv::get_type_name, "None");
cls_Extrema_HArray2OfPOnCurv.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_HArray2OfPOnCurv::get_type_descriptor, "None");
cls_Extrema_HArray2OfPOnCurv.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_HArray2OfPOnCurv::*)() const) &Extrema_HArray2OfPOnCurv::DynamicType, "None");

// CLASS: EXTREMA_HARRAY2OFPONCURV2D
py::class_<Extrema_HArray2OfPOnCurv2d, opencascade::handle<Extrema_HArray2OfPOnCurv2d>, Standard_Transient> cls_Extrema_HArray2OfPOnCurv2d(mod, "Extrema_HArray2OfPOnCurv2d", "None", py::multiple_inheritance());

// Constructors
cls_Extrema_HArray2OfPOnCurv2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_Extrema_HArray2OfPOnCurv2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Extrema_Array2OfPOnCurv2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_Extrema_HArray2OfPOnCurv2d.def(py::init<const Extrema_Array2OfPOnCurv2d &>(), py::arg("theOther"));

// Methods
// cls_Extrema_HArray2OfPOnCurv2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_HArray2OfPOnCurv2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_HArray2OfPOnCurv2d.def_static("operator delete_", (void (*)(void *)) &Extrema_HArray2OfPOnCurv2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnCurv2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_HArray2OfPOnCurv2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_HArray2OfPOnCurv2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_HArray2OfPOnCurv2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnCurv2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_HArray2OfPOnCurv2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnCurv2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_HArray2OfPOnCurv2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_Extrema_HArray2OfPOnCurv2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray2OfPOnCurv2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Extrema_HArray2OfPOnCurv2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray2OfPOnCurv2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Extrema_HArray2OfPOnCurv2d.def("Array2", (const Extrema_Array2OfPOnCurv2d & (Extrema_HArray2OfPOnCurv2d::*)() const) &Extrema_HArray2OfPOnCurv2d::Array2, "None");
cls_Extrema_HArray2OfPOnCurv2d.def("ChangeArray2", (Extrema_Array2OfPOnCurv2d & (Extrema_HArray2OfPOnCurv2d::*)()) &Extrema_HArray2OfPOnCurv2d::ChangeArray2, "None");
cls_Extrema_HArray2OfPOnCurv2d.def_static("get_type_name_", (const char * (*)()) &Extrema_HArray2OfPOnCurv2d::get_type_name, "None");
cls_Extrema_HArray2OfPOnCurv2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_HArray2OfPOnCurv2d::get_type_descriptor, "None");
cls_Extrema_HArray2OfPOnCurv2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_HArray2OfPOnCurv2d::*)() const) &Extrema_HArray2OfPOnCurv2d::DynamicType, "None");

// CLASS: EXTREMA_HARRAY2OFPONSURF
py::class_<Extrema_HArray2OfPOnSurf, opencascade::handle<Extrema_HArray2OfPOnSurf>, Standard_Transient> cls_Extrema_HArray2OfPOnSurf(mod, "Extrema_HArray2OfPOnSurf", "None", py::multiple_inheritance());

// Constructors
cls_Extrema_HArray2OfPOnSurf.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_Extrema_HArray2OfPOnSurf.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Extrema_Array2OfPOnSurf::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_Extrema_HArray2OfPOnSurf.def(py::init<const Extrema_Array2OfPOnSurf &>(), py::arg("theOther"));

// Methods
// cls_Extrema_HArray2OfPOnSurf.def_static("operator new_", (void * (*)(size_t)) &Extrema_HArray2OfPOnSurf::operator new, "None", py::arg("theSize"));
// cls_Extrema_HArray2OfPOnSurf.def_static("operator delete_", (void (*)(void *)) &Extrema_HArray2OfPOnSurf::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnSurf.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_HArray2OfPOnSurf::operator new[], "None", py::arg("theSize"));
// cls_Extrema_HArray2OfPOnSurf.def_static("operator delete[]_", (void (*)(void *)) &Extrema_HArray2OfPOnSurf::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnSurf.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_HArray2OfPOnSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnSurf.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_HArray2OfPOnSurf::operator delete, "None", py::arg(""), py::arg(""));
// cls_Extrema_HArray2OfPOnSurf.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray2OfPOnSurf::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Extrema_HArray2OfPOnSurf.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray2OfPOnSurf::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Extrema_HArray2OfPOnSurf.def("Array2", (const Extrema_Array2OfPOnSurf & (Extrema_HArray2OfPOnSurf::*)() const) &Extrema_HArray2OfPOnSurf::Array2, "None");
cls_Extrema_HArray2OfPOnSurf.def("ChangeArray2", (Extrema_Array2OfPOnSurf & (Extrema_HArray2OfPOnSurf::*)()) &Extrema_HArray2OfPOnSurf::ChangeArray2, "None");
cls_Extrema_HArray2OfPOnSurf.def_static("get_type_name_", (const char * (*)()) &Extrema_HArray2OfPOnSurf::get_type_name, "None");
cls_Extrema_HArray2OfPOnSurf.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_HArray2OfPOnSurf::get_type_descriptor, "None");
cls_Extrema_HArray2OfPOnSurf.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_HArray2OfPOnSurf::*)() const) &Extrema_HArray2OfPOnSurf::DynamicType, "None");

// CLASS: EXTREMA_LOCATEEXTCC2D
py::class_<Extrema_LocateExtCC2d> cls_Extrema_LocateExtCC2d(mod, "Extrema_LocateExtCC2d", "It calculates the distance between two curves with a close point; these distances can be maximum or minimum.");

// Constructors
cls_Extrema_LocateExtCC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U0"), py::arg("V0"));

// Methods
// cls_Extrema_LocateExtCC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocateExtCC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocateExtCC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_LocateExtCC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocateExtCC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocateExtCC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocateExtCC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocateExtCC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocateExtCC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocateExtCC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocateExtCC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocateExtCC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocateExtCC2d.def("IsDone", (Standard_Boolean (Extrema_LocateExtCC2d::*)() const) &Extrema_LocateExtCC2d::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocateExtCC2d.def("SquareDistance", (Standard_Real (Extrema_LocateExtCC2d::*)() const) &Extrema_LocateExtCC2d::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocateExtCC2d.def("Point", (void (Extrema_LocateExtCC2d::*)(Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_LocateExtCC2d::Point, "Returns the points of the extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_PCLOCFOFLOCEPCOFLOCATEEXTPC2D
py::class_<Extrema_PCLocFOfLocEPCOfLocateExtPC2d, math_FunctionWithDerivative> cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d(mod, "Extrema_PCLocFOfLocEPCOfLocateExtPC2d", "None");

// Constructors
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def(py::init<>());
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &>(), py::arg("P"), py::arg("C"));

// Methods
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("Initialize", (void (Extrema_PCLocFOfLocEPCOfLocateExtPC2d::*)(const Adaptor2d_Curve2d &)) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("SetPoint", (void (Extrema_PCLocFOfLocEPCOfLocateExtPC2d::*)(const gp_Pnt2d &)) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("Value", [](Extrema_PCLocFOfLocEPCOfLocateExtPC2d &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("Derivative", [](Extrema_PCLocFOfLocEPCOfLocateExtPC2d &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("Values", [](Extrema_PCLocFOfLocEPCOfLocateExtPC2d &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("GetStateNumber", (Standard_Integer (Extrema_PCLocFOfLocEPCOfLocateExtPC2d::*)()) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::GetStateNumber, "Save the found extremum.");
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("NbExt", (Standard_Integer (Extrema_PCLocFOfLocEPCOfLocateExtPC2d::*)() const) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::NbExt, "Return the nunber of found extrema.");
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("SquareDistance", (Standard_Real (Extrema_PCLocFOfLocEPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("IsMin", (Standard_Boolean (Extrema_PCLocFOfLocEPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_PCLocFOfLocEPCOfLocateExtPC2d::*)(const Standard_Integer) const) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("SubIntervalInitialize", (void (Extrema_PCLocFOfLocEPCOfLocateExtPC2d::*)(const Standard_Real, const Standard_Real)) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_PCLocFOfLocEPCOfLocateExtPC2d.def("SearchOfTolerance", (Standard_Real (Extrema_PCLocFOfLocEPCOfLocateExtPC2d::*)()) &Extrema_PCLocFOfLocEPCOfLocateExtPC2d::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// CLASS: EXTREMA_LOCEPCOFLOCATEEXTPC2D
py::class_<Extrema_LocEPCOfLocateExtPC2d> cls_Extrema_LocEPCOfLocateExtPC2d(mod, "Extrema_LocEPCOfLocateExtPC2d", "None");

// Constructors
cls_Extrema_LocEPCOfLocateExtPC2d.def(py::init<>());
cls_Extrema_LocEPCOfLocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("TolU"));
cls_Extrema_LocEPCOfLocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));

// Methods
// cls_Extrema_LocEPCOfLocateExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocEPCOfLocateExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocEPCOfLocateExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_LocEPCOfLocateExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocEPCOfLocateExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocEPCOfLocateExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocEPCOfLocateExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocEPCOfLocateExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocEPCOfLocateExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocEPCOfLocateExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocEPCOfLocateExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocEPCOfLocateExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocEPCOfLocateExtPC2d.def("Initialize", (void (Extrema_LocEPCOfLocateExtPC2d::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_LocEPCOfLocateExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));
cls_Extrema_LocEPCOfLocateExtPC2d.def("Perform", (void (Extrema_LocEPCOfLocateExtPC2d::*)(const gp_Pnt2d &, const Standard_Real)) &Extrema_LocEPCOfLocateExtPC2d::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"), py::arg("U0"));
cls_Extrema_LocEPCOfLocateExtPC2d.def("IsDone", (Standard_Boolean (Extrema_LocEPCOfLocateExtPC2d::*)() const) &Extrema_LocEPCOfLocateExtPC2d::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocEPCOfLocateExtPC2d.def("SquareDistance", (Standard_Real (Extrema_LocEPCOfLocateExtPC2d::*)() const) &Extrema_LocEPCOfLocateExtPC2d::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocEPCOfLocateExtPC2d.def("IsMin", (Standard_Boolean (Extrema_LocEPCOfLocateExtPC2d::*)() const) &Extrema_LocEPCOfLocateExtPC2d::IsMin, "Returns True if the extremum distance is a minimum.");
cls_Extrema_LocEPCOfLocateExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_LocEPCOfLocateExtPC2d::*)() const) &Extrema_LocEPCOfLocateExtPC2d::Point, "Returns the point of the extremum distance.");

// CLASS: EXTREMA_LOCATEEXTPC2D
py::class_<Extrema_LocateExtPC2d> cls_Extrema_LocateExtPC2d(mod, "Extrema_LocateExtPC2d", "None");

// Constructors
cls_Extrema_LocateExtPC2d.def(py::init<>());
cls_Extrema_LocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("TolF"));
cls_Extrema_LocateExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("Umin"), py::arg("Usup"), py::arg("TolF"));

// Methods
// cls_Extrema_LocateExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocateExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocateExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_LocateExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocateExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocateExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocateExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocateExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocateExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocateExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocateExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocateExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocateExtPC2d.def("Initialize", (void (Extrema_LocateExtPC2d::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_LocateExtPC2d::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("Umin"), py::arg("Usup"), py::arg("TolF"));
cls_Extrema_LocateExtPC2d.def("Perform", (void (Extrema_LocateExtPC2d::*)(const gp_Pnt2d &, const Standard_Real)) &Extrema_LocateExtPC2d::Perform, "None", py::arg("P"), py::arg("U0"));
cls_Extrema_LocateExtPC2d.def("IsDone", (Standard_Boolean (Extrema_LocateExtPC2d::*)() const) &Extrema_LocateExtPC2d::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocateExtPC2d.def("SquareDistance", (Standard_Real (Extrema_LocateExtPC2d::*)() const) &Extrema_LocateExtPC2d::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocateExtPC2d.def("IsMin", (Standard_Boolean (Extrema_LocateExtPC2d::*)() const) &Extrema_LocateExtPC2d::IsMin, "Returns True if the extremum distance is a minimum.");
cls_Extrema_LocateExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_LocateExtPC2d::*)() const) &Extrema_LocateExtPC2d::Point, "Returns the point of the extremum distance.");

// CLASS: EXTREMA_LOCECC
py::class_<Extrema_LocECC> cls_Extrema_LocECC(mod, "Extrema_LocECC", "None");

// Constructors
cls_Extrema_LocECC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U0"), py::arg("V0"), py::arg("TolU"), py::arg("TolV"));

// Methods
// cls_Extrema_LocECC.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocECC::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocECC.def_static("operator delete_", (void (*)(void *)) &Extrema_LocECC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocECC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocECC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocECC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocECC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocECC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocECC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocECC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocECC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocECC.def("IsDone", (Standard_Boolean (Extrema_LocECC::*)() const) &Extrema_LocECC::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocECC.def("SquareDistance", (Standard_Real (Extrema_LocECC::*)() const) &Extrema_LocECC::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocECC.def("Point", (void (Extrema_LocECC::*)(Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_LocECC::Point, "Returns the points of the extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("P1"), py::arg("P2"));

// CLASS: EXTREMA_LOCECC2D
py::class_<Extrema_LocECC2d> cls_Extrema_LocECC2d(mod, "Extrema_LocECC2d", "None");

// Constructors
cls_Extrema_LocECC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U0"), py::arg("V0"), py::arg("TolU"), py::arg("TolV"));

// Methods
// cls_Extrema_LocECC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocECC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocECC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_LocECC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocECC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocECC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocECC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocECC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocECC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocECC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocECC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocECC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocECC2d.def("IsDone", (Standard_Boolean (Extrema_LocECC2d::*)() const) &Extrema_LocECC2d::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocECC2d.def("SquareDistance", (Standard_Real (Extrema_LocECC2d::*)() const) &Extrema_LocECC2d::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocECC2d.def("Point", (void (Extrema_LocECC2d::*)(Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_LocECC2d::Point, "Returns the points of the extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("P1"), py::arg("P2"));


}
