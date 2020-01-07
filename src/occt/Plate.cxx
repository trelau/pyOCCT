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
#include <Standard.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <Plate_PinpointConstraint.hxx>
#include <NCollection_Sequence.hxx>
#include <Plate_SequenceOfPinpointConstraint.hxx>
#include <NCollection_Array1.hxx>
#include <Plate_Array1OfPinpointConstraint.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Std.hxx>
#include <Plate_HArray1OfPinpointConstraint.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <Plate_LinearXYZConstraint.hxx>
#include <Plate_SequenceOfLinearXYZConstraint.hxx>
#include <TColgp_Array1OfXYZ.hxx>
#include <TColgp_Array2OfXYZ.hxx>
#include <TColgp_HArray2OfXYZ.hxx>
#include <Plate_LinearScalarConstraint.hxx>
#include <Plate_SequenceOfLinearScalarConstraint.hxx>
#include <Plate_Plate.hxx>
#include <Plate_GlobalTranslationConstraint.hxx>
#include <Plate_LineConstraint.hxx>
#include <Plate_PlaneConstraint.hxx>
#include <Plate_SampledCurveConstraint.hxx>
#include <Plate_GtoCConstraint.hxx>
#include <Plate_FreeGtoCConstraint.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <math_Matrix.hxx>
#include <Plate_D1.hxx>
#include <Plate_D2.hxx>
#include <Plate_D3.hxx>
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>

PYBIND11_MODULE(Plate, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Message");
py::module::import("OCCT.math");

// CLASS: PLATE_PINPOINTCONSTRAINT
py::class_<Plate_PinpointConstraint> cls_Plate_PinpointConstraint(mod, "Plate_PinpointConstraint", "define a constraint on the Plate");

// Constructors
cls_Plate_PinpointConstraint.def(py::init<>());
cls_Plate_PinpointConstraint.def(py::init<const gp_XY &, const gp_XYZ &>(), py::arg("point2d"), py::arg("ImposedValue"));
cls_Plate_PinpointConstraint.def(py::init<const gp_XY &, const gp_XYZ &, const Standard_Integer>(), py::arg("point2d"), py::arg("ImposedValue"), py::arg("iu"));
cls_Plate_PinpointConstraint.def(py::init<const gp_XY &, const gp_XYZ &, const Standard_Integer, const Standard_Integer>(), py::arg("point2d"), py::arg("ImposedValue"), py::arg("iu"), py::arg("iv"));

// Methods
// cls_Plate_PinpointConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_PinpointConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_PinpointConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_PinpointConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_PinpointConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_PinpointConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_PinpointConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_PinpointConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_PinpointConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_PinpointConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_PinpointConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_PinpointConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_PinpointConstraint.def("Pnt2d", (const gp_XY & (Plate_PinpointConstraint::*)() const) &Plate_PinpointConstraint::Pnt2d, "None");
cls_Plate_PinpointConstraint.def("Idu", (const Standard_Integer & (Plate_PinpointConstraint::*)() const) &Plate_PinpointConstraint::Idu, "None");
cls_Plate_PinpointConstraint.def("Idv", (const Standard_Integer & (Plate_PinpointConstraint::*)() const) &Plate_PinpointConstraint::Idv, "None");
cls_Plate_PinpointConstraint.def("Value", (const gp_XYZ & (Plate_PinpointConstraint::*)() const) &Plate_PinpointConstraint::Value, "None");

// TYPEDEF: PLATE_SEQUENCEOFPINPOINTCONSTRAINT
bind_NCollection_Sequence<Plate_PinpointConstraint>(mod, "Plate_SequenceOfPinpointConstraint", py::module_local(false));

// TYPEDEF: PLATE_ARRAY1OFPINPOINTCONSTRAINT
bind_NCollection_Array1<Plate_PinpointConstraint>(mod, "Plate_Array1OfPinpointConstraint", py::module_local(false));

// CLASS: PLATE_HARRAY1OFPINPOINTCONSTRAINT
bind_Define_HArray1<Plate_HArray1OfPinpointConstraint, Plate_Array1OfPinpointConstraint>(mod, "Plate_HArray1OfPinpointConstraint");

// CLASS: PLATE_LINEARXYZCONSTRAINT
py::class_<Plate_LinearXYZConstraint> cls_Plate_LinearXYZConstraint(mod, "Plate_LinearXYZConstraint", "define on or several constraints as linear combination of PinPointConstraint unlike the LinearScalarConstraint, usage of this kind of constraint preserve the X,Y and Z uncoupling.");

// Constructors
cls_Plate_LinearXYZConstraint.def(py::init<>());
cls_Plate_LinearXYZConstraint.def(py::init<const Plate_Array1OfPinpointConstraint &, const TColStd_Array1OfReal &>(), py::arg("thePPC"), py::arg("theCoeff"));
cls_Plate_LinearXYZConstraint.def(py::init<const Plate_Array1OfPinpointConstraint &, const TColStd_Array2OfReal &>(), py::arg("thePPC"), py::arg("theCoeff"));
cls_Plate_LinearXYZConstraint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("ColLen"), py::arg("RowLen"));

// Methods
// cls_Plate_LinearXYZConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_LinearXYZConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_LinearXYZConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_LinearXYZConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_LinearXYZConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_LinearXYZConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_LinearXYZConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_LinearXYZConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_LinearXYZConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_LinearXYZConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_LinearXYZConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_LinearXYZConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_LinearXYZConstraint.def("GetPPC", (const Plate_Array1OfPinpointConstraint & (Plate_LinearXYZConstraint::*)() const) &Plate_LinearXYZConstraint::GetPPC, "None");
cls_Plate_LinearXYZConstraint.def("Coeff", (const TColStd_Array2OfReal & (Plate_LinearXYZConstraint::*)() const) &Plate_LinearXYZConstraint::Coeff, "None");
cls_Plate_LinearXYZConstraint.def("SetPPC", (void (Plate_LinearXYZConstraint::*)(const Standard_Integer, const Plate_PinpointConstraint &)) &Plate_LinearXYZConstraint::SetPPC, "Sets the PinPointConstraint of index Index to Value raise if Index is greater than the length of PPC or the Row length of coeff or lower than 1", py::arg("Index"), py::arg("Value"));
cls_Plate_LinearXYZConstraint.def("SetCoeff", (void (Plate_LinearXYZConstraint::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &Plate_LinearXYZConstraint::SetCoeff, "Sets the coeff of index (Row,Col) to Value raise if Row (respectively Col) is greater than the Row (respectively Column) length of coeff", py::arg("Row"), py::arg("Col"), py::arg("Value"));

// TYPEDEF: PLATE_SEQUENCEOFLINEARXYZCONSTRAINT
bind_NCollection_Sequence<Plate_LinearXYZConstraint>(mod, "Plate_SequenceOfLinearXYZConstraint", py::module_local(false));

// CLASS: PLATE_LINEARSCALARCONSTRAINT
py::class_<Plate_LinearScalarConstraint> cls_Plate_LinearScalarConstraint(mod, "Plate_LinearScalarConstraint", "define on or several constraints as linear combination of the X,Y and Z components of a set of PinPointConstraint");

// Constructors
cls_Plate_LinearScalarConstraint.def(py::init<>());
cls_Plate_LinearScalarConstraint.def(py::init<const Plate_PinpointConstraint &, const gp_XYZ &>(), py::arg("thePPC1"), py::arg("theCoeff"));
cls_Plate_LinearScalarConstraint.def(py::init<const Plate_Array1OfPinpointConstraint &, const TColgp_Array1OfXYZ &>(), py::arg("thePPC"), py::arg("theCoeff"));
cls_Plate_LinearScalarConstraint.def(py::init<const Plate_Array1OfPinpointConstraint &, const TColgp_Array2OfXYZ &>(), py::arg("thePPC"), py::arg("theCoeff"));
cls_Plate_LinearScalarConstraint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("ColLen"), py::arg("RowLen"));

// Methods
// cls_Plate_LinearScalarConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_LinearScalarConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_LinearScalarConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_LinearScalarConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_LinearScalarConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_LinearScalarConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_LinearScalarConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_LinearScalarConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_LinearScalarConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_LinearScalarConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_LinearScalarConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_LinearScalarConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_LinearScalarConstraint.def("GetPPC", (const Plate_Array1OfPinpointConstraint & (Plate_LinearScalarConstraint::*)() const) &Plate_LinearScalarConstraint::GetPPC, "None");
cls_Plate_LinearScalarConstraint.def("Coeff", (const TColgp_Array2OfXYZ & (Plate_LinearScalarConstraint::*)() const) &Plate_LinearScalarConstraint::Coeff, "None");
cls_Plate_LinearScalarConstraint.def("SetPPC", (void (Plate_LinearScalarConstraint::*)(const Standard_Integer, const Plate_PinpointConstraint &)) &Plate_LinearScalarConstraint::SetPPC, "Sets the PinPointConstraint of index Index to Value raise if Index is greater than the length of PPC or the Row length of coeff or lower than 1", py::arg("Index"), py::arg("Value"));
cls_Plate_LinearScalarConstraint.def("SetCoeff", (void (Plate_LinearScalarConstraint::*)(const Standard_Integer, const Standard_Integer, const gp_XYZ &)) &Plate_LinearScalarConstraint::SetCoeff, "Sets the coeff of index (Row,Col) to Value raise if Row (respectively Col) is greater than the Row (respectively Column) length of coeff", py::arg("Row"), py::arg("Col"), py::arg("Value"));

// TYPEDEF: PLATE_SEQUENCEOFLINEARSCALARCONSTRAINT
bind_NCollection_Sequence<Plate_LinearScalarConstraint>(mod, "Plate_SequenceOfLinearScalarConstraint", py::module_local(false));

// CLASS: PLATE_PLATE
py::class_<Plate_Plate> cls_Plate_Plate(mod, "Plate_Plate", "This class implement a variationnal spline algorithm able to define a two variable function satisfying some constraints and minimizing an energy like criterion.");

// Constructors
cls_Plate_Plate.def(py::init<>());
cls_Plate_Plate.def(py::init<const Plate_Plate &>(), py::arg("Ref"));

// Methods
// cls_Plate_Plate.def_static("operator new_", (void * (*)(size_t)) &Plate_Plate::operator new, "None", py::arg("theSize"));
// cls_Plate_Plate.def_static("operator delete_", (void (*)(void *)) &Plate_Plate::operator delete, "None", py::arg("theAddress"));
// cls_Plate_Plate.def_static("operator new[]_", (void * (*)(size_t)) &Plate_Plate::operator new[], "None", py::arg("theSize"));
// cls_Plate_Plate.def_static("operator delete[]_", (void (*)(void *)) &Plate_Plate::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_Plate.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_Plate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_Plate.def_static("operator delete_", (void (*)(void *, void *)) &Plate_Plate::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_Plate.def("Copy", (Plate_Plate & (Plate_Plate::*)(const Plate_Plate &)) &Plate_Plate::Copy, "None", py::arg("Ref"));
// cls_Plate_Plate.def("operator=", (Plate_Plate & (Plate_Plate::*)(const Plate_Plate &)) &Plate_Plate::operator=, "None", py::arg("Ref"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_PinpointConstraint &)) &Plate_Plate::Load, "None", py::arg("PConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_LinearXYZConstraint &)) &Plate_Plate::Load, "None", py::arg("LXYZConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_LinearScalarConstraint &)) &Plate_Plate::Load, "None", py::arg("LScalarConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_GlobalTranslationConstraint &)) &Plate_Plate::Load, "None", py::arg("GTConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_LineConstraint &)) &Plate_Plate::Load, "None", py::arg("LConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_PlaneConstraint &)) &Plate_Plate::Load, "None", py::arg("PConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_SampledCurveConstraint &)) &Plate_Plate::Load, "None", py::arg("SCConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_GtoCConstraint &)) &Plate_Plate::Load, "None", py::arg("GtoCConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_FreeGtoCConstraint &)) &Plate_Plate::Load, "None", py::arg("FGtoCConst"));
cls_Plate_Plate.def("SolveTI", [](Plate_Plate &self) -> void { return self.SolveTI(); });
cls_Plate_Plate.def("SolveTI", [](Plate_Plate &self, const Standard_Integer a0) -> void { return self.SolveTI(a0); });
cls_Plate_Plate.def("SolveTI", [](Plate_Plate &self, const Standard_Integer a0, const Standard_Real a1) -> void { return self.SolveTI(a0, a1); });
cls_Plate_Plate.def("SolveTI", (void (Plate_Plate::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<Message_ProgressIndicator> &)) &Plate_Plate::SolveTI, "None", py::arg("ord"), py::arg("anisotropie"), py::arg("aProgress"));
cls_Plate_Plate.def("IsDone", (Standard_Boolean (Plate_Plate::*)() const) &Plate_Plate::IsDone, "returns True if all has been correctly done.");
cls_Plate_Plate.def("destroy", (void (Plate_Plate::*)()) &Plate_Plate::destroy, "None");
cls_Plate_Plate.def("Init", (void (Plate_Plate::*)()) &Plate_Plate::Init, "reset the Plate in the initial state ( same as after Create())");
cls_Plate_Plate.def("Evaluate", (gp_XYZ (Plate_Plate::*)(const gp_XY &) const) &Plate_Plate::Evaluate, "None", py::arg("point2d"));
cls_Plate_Plate.def("EvaluateDerivative", (gp_XYZ (Plate_Plate::*)(const gp_XY &, const Standard_Integer, const Standard_Integer) const) &Plate_Plate::EvaluateDerivative, "None", py::arg("point2d"), py::arg("iu"), py::arg("iv"));
cls_Plate_Plate.def("CoefPol", (void (Plate_Plate::*)(opencascade::handle<TColgp_HArray2OfXYZ> &) const) &Plate_Plate::CoefPol, "None", py::arg("Coefs"));
cls_Plate_Plate.def("SetPolynomialPartOnly", [](Plate_Plate &self) -> void { return self.SetPolynomialPartOnly(); });
cls_Plate_Plate.def("SetPolynomialPartOnly", (void (Plate_Plate::*)(const Standard_Boolean)) &Plate_Plate::SetPolynomialPartOnly, "None", py::arg("PPOnly"));
cls_Plate_Plate.def("Continuity", (Standard_Integer (Plate_Plate::*)() const) &Plate_Plate::Continuity, "None");
cls_Plate_Plate.def("UVBox", [](Plate_Plate &self, Standard_Real & UMin, Standard_Real & UMax, Standard_Real & VMin, Standard_Real & VMax){ self.UVBox(UMin, UMax, VMin, VMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UMin, UMax, VMin, VMax); }, "None", py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_Plate_Plate.def("UVConstraints", (void (Plate_Plate::*)(TColgp_SequenceOfXY &) const) &Plate_Plate::UVConstraints, "None", py::arg("Seq"));

// CLASS: PLATE_D1
py::class_<Plate_D1> cls_Plate_D1(mod, "Plate_D1", "define an order 1 derivatives of a 3d valued function of a 2d variable");

// Constructors
cls_Plate_D1.def(py::init<const gp_XYZ &, const gp_XYZ &>(), py::arg("du"), py::arg("dv"));
cls_Plate_D1.def(py::init<const Plate_D1 &>(), py::arg("ref"));

// Methods
// cls_Plate_D1.def_static("operator new_", (void * (*)(size_t)) &Plate_D1::operator new, "None", py::arg("theSize"));
// cls_Plate_D1.def_static("operator delete_", (void (*)(void *)) &Plate_D1::operator delete, "None", py::arg("theAddress"));
// cls_Plate_D1.def_static("operator new[]_", (void * (*)(size_t)) &Plate_D1::operator new[], "None", py::arg("theSize"));
// cls_Plate_D1.def_static("operator delete[]_", (void (*)(void *)) &Plate_D1::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_D1.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_D1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_D1.def_static("operator delete_", (void (*)(void *, void *)) &Plate_D1::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_D1.def("DU", (const gp_XYZ & (Plate_D1::*)() const) &Plate_D1::DU, "None");
cls_Plate_D1.def("DV", (const gp_XYZ & (Plate_D1::*)() const) &Plate_D1::DV, "None");

// CLASS: PLATE_D2
py::class_<Plate_D2> cls_Plate_D2(mod, "Plate_D2", "define an order 2 derivatives of a 3d valued function of a 2d variable");

// Constructors
cls_Plate_D2.def(py::init<const gp_XYZ &, const gp_XYZ &, const gp_XYZ &>(), py::arg("duu"), py::arg("duv"), py::arg("dvv"));
cls_Plate_D2.def(py::init<const Plate_D2 &>(), py::arg("ref"));

// Methods
// cls_Plate_D2.def_static("operator new_", (void * (*)(size_t)) &Plate_D2::operator new, "None", py::arg("theSize"));
// cls_Plate_D2.def_static("operator delete_", (void (*)(void *)) &Plate_D2::operator delete, "None", py::arg("theAddress"));
// cls_Plate_D2.def_static("operator new[]_", (void * (*)(size_t)) &Plate_D2::operator new[], "None", py::arg("theSize"));
// cls_Plate_D2.def_static("operator delete[]_", (void (*)(void *)) &Plate_D2::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_D2.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_D2::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_D2.def_static("operator delete_", (void (*)(void *, void *)) &Plate_D2::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: PLATE_D3
py::class_<Plate_D3> cls_Plate_D3(mod, "Plate_D3", "define an order 3 derivatives of a 3d valued function of a 2d variable");

// Constructors
cls_Plate_D3.def(py::init<const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &>(), py::arg("duuu"), py::arg("duuv"), py::arg("duvv"), py::arg("dvvv"));
cls_Plate_D3.def(py::init<const Plate_D3 &>(), py::arg("ref"));

// Methods
// cls_Plate_D3.def_static("operator new_", (void * (*)(size_t)) &Plate_D3::operator new, "None", py::arg("theSize"));
// cls_Plate_D3.def_static("operator delete_", (void (*)(void *)) &Plate_D3::operator delete, "None", py::arg("theAddress"));
// cls_Plate_D3.def_static("operator new[]_", (void * (*)(size_t)) &Plate_D3::operator new[], "None", py::arg("theSize"));
// cls_Plate_D3.def_static("operator delete[]_", (void (*)(void *)) &Plate_D3::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_D3.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_D3::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_D3.def_static("operator delete_", (void (*)(void *, void *)) &Plate_D3::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: PLATE_FREEGTOCCONSTRAINT
py::class_<Plate_FreeGtoCConstraint> cls_Plate_FreeGtoCConstraint(mod, "Plate_FreeGtoCConstraint", "define a G1, G2 or G3 constraint on the Plate using weaker constraint than GtoCConstraint");

// Constructors
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Standard_Real>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("IncrementalLoad"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Standard_Real, const Standard_Integer>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("IncrementalLoad"), py::arg("orientation"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Standard_Real>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("IncrementalLoad"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Standard_Real, const Standard_Integer>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("IncrementalLoad"), py::arg("orientation"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Plate_D3 &, const Plate_D3 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("D3S"), py::arg("D3T"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Plate_D3 &, const Plate_D3 &, const Standard_Real>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("D3S"), py::arg("D3T"), py::arg("IncrementalLoad"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Plate_D3 &, const Plate_D3 &, const Standard_Real, const Standard_Integer>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("D3S"), py::arg("D3T"), py::arg("IncrementalLoad"), py::arg("orientation"));

// Methods
// cls_Plate_FreeGtoCConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_FreeGtoCConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_FreeGtoCConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_FreeGtoCConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_FreeGtoCConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_FreeGtoCConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_FreeGtoCConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_FreeGtoCConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_FreeGtoCConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_FreeGtoCConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_FreeGtoCConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_FreeGtoCConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_FreeGtoCConstraint.def("nb_PPC", (const Standard_Integer & (Plate_FreeGtoCConstraint::*)() const) &Plate_FreeGtoCConstraint::nb_PPC, "None");
cls_Plate_FreeGtoCConstraint.def("GetPPC", (const Plate_PinpointConstraint & (Plate_FreeGtoCConstraint::*)(const Standard_Integer) const) &Plate_FreeGtoCConstraint::GetPPC, "None", py::arg("Index"));
cls_Plate_FreeGtoCConstraint.def("nb_LSC", (const Standard_Integer & (Plate_FreeGtoCConstraint::*)() const) &Plate_FreeGtoCConstraint::nb_LSC, "None");
cls_Plate_FreeGtoCConstraint.def("LSC", (const Plate_LinearScalarConstraint & (Plate_FreeGtoCConstraint::*)(const Standard_Integer) const) &Plate_FreeGtoCConstraint::LSC, "None", py::arg("Index"));

// CLASS: PLATE_GLOBALTRANSLATIONCONSTRAINT
py::class_<Plate_GlobalTranslationConstraint> cls_Plate_GlobalTranslationConstraint(mod, "Plate_GlobalTranslationConstraint", "force a set of UV points to translate without deformation");

// Constructors
cls_Plate_GlobalTranslationConstraint.def(py::init<const TColgp_SequenceOfXY &>(), py::arg("SOfXY"));

// Methods
// cls_Plate_GlobalTranslationConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_GlobalTranslationConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_GlobalTranslationConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_GlobalTranslationConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_GlobalTranslationConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_GlobalTranslationConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_GlobalTranslationConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_GlobalTranslationConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_GlobalTranslationConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_GlobalTranslationConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_GlobalTranslationConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_GlobalTranslationConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_GlobalTranslationConstraint.def("LXYZC", (const Plate_LinearXYZConstraint & (Plate_GlobalTranslationConstraint::*)() const) &Plate_GlobalTranslationConstraint::LXYZC, "None");

// CLASS: PLATE_GTOCCONSTRAINT
py::class_<Plate_GtoCConstraint> cls_Plate_GtoCConstraint(mod, "Plate_GtoCConstraint", "define a G1, G2 or G3 constraint on the Plate");

// Constructors
cls_Plate_GtoCConstraint.def(py::init<const Plate_GtoCConstraint &>(), py::arg("ref"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const gp_XYZ &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("nP"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const gp_XYZ &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("nP"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Plate_D3 &, const Plate_D3 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("D3S"), py::arg("D3T"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Plate_D3 &, const Plate_D3 &, const gp_XYZ &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("D3S"), py::arg("D3T"), py::arg("nP"));

// Methods
// cls_Plate_GtoCConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_GtoCConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_GtoCConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_GtoCConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_GtoCConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_GtoCConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_GtoCConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_GtoCConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_GtoCConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_GtoCConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_GtoCConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_GtoCConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_GtoCConstraint.def("nb_PPC", (const Standard_Integer & (Plate_GtoCConstraint::*)() const) &Plate_GtoCConstraint::nb_PPC, "None");
cls_Plate_GtoCConstraint.def("GetPPC", (const Plate_PinpointConstraint & (Plate_GtoCConstraint::*)(const Standard_Integer) const) &Plate_GtoCConstraint::GetPPC, "None", py::arg("Index"));
cls_Plate_GtoCConstraint.def("D1SurfInit", (const Plate_D1 & (Plate_GtoCConstraint::*)() const) &Plate_GtoCConstraint::D1SurfInit, "None");

// CLASS: PLATE_LINECONSTRAINT
py::class_<Plate_LineConstraint> cls_Plate_LineConstraint(mod, "Plate_LineConstraint", "constraint a point to belong to a straight line");

// Constructors
cls_Plate_LineConstraint.def(py::init<const gp_XY &, const gp_Lin &>(), py::arg("point2d"), py::arg("lin"));
cls_Plate_LineConstraint.def(py::init<const gp_XY &, const gp_Lin &, const Standard_Integer>(), py::arg("point2d"), py::arg("lin"), py::arg("iu"));
cls_Plate_LineConstraint.def(py::init<const gp_XY &, const gp_Lin &, const Standard_Integer, const Standard_Integer>(), py::arg("point2d"), py::arg("lin"), py::arg("iu"), py::arg("iv"));

// Methods
// cls_Plate_LineConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_LineConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_LineConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_LineConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_LineConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_LineConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_LineConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_LineConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_LineConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_LineConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_LineConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_LineConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_LineConstraint.def("LSC", (const Plate_LinearScalarConstraint & (Plate_LineConstraint::*)() const) &Plate_LineConstraint::LSC, "None");

// CLASS: PLATE_PLANECONSTRAINT
py::class_<Plate_PlaneConstraint> cls_Plate_PlaneConstraint(mod, "Plate_PlaneConstraint", "constraint a point to belong to a Plane");

// Constructors
cls_Plate_PlaneConstraint.def(py::init<const gp_XY &, const gp_Pln &>(), py::arg("point2d"), py::arg("pln"));
cls_Plate_PlaneConstraint.def(py::init<const gp_XY &, const gp_Pln &, const Standard_Integer>(), py::arg("point2d"), py::arg("pln"), py::arg("iu"));
cls_Plate_PlaneConstraint.def(py::init<const gp_XY &, const gp_Pln &, const Standard_Integer, const Standard_Integer>(), py::arg("point2d"), py::arg("pln"), py::arg("iu"), py::arg("iv"));

// Methods
// cls_Plate_PlaneConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_PlaneConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_PlaneConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_PlaneConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_PlaneConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_PlaneConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_PlaneConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_PlaneConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_PlaneConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_PlaneConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_PlaneConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_PlaneConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_PlaneConstraint.def("LSC", (const Plate_LinearScalarConstraint & (Plate_PlaneConstraint::*)() const) &Plate_PlaneConstraint::LSC, "None");

// CLASS: PLATE_SAMPLEDCURVECONSTRAINT
py::class_<Plate_SampledCurveConstraint> cls_Plate_SampledCurveConstraint(mod, "Plate_SampledCurveConstraint", "define m PinPointConstraint driven by m unknown");

// Constructors
cls_Plate_SampledCurveConstraint.def(py::init<const Plate_SequenceOfPinpointConstraint &, const Standard_Integer>(), py::arg("SOPPC"), py::arg("n"));

// Methods
// cls_Plate_SampledCurveConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_SampledCurveConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_SampledCurveConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_SampledCurveConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_SampledCurveConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_SampledCurveConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_SampledCurveConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_SampledCurveConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_SampledCurveConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_SampledCurveConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_SampledCurveConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_SampledCurveConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_SampledCurveConstraint.def("LXYZC", (const Plate_LinearXYZConstraint & (Plate_SampledCurveConstraint::*)() const) &Plate_SampledCurveConstraint::LXYZC, "None");


}
