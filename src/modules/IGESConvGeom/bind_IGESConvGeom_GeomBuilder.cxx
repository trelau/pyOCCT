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
#include <Standard_Handle.hxx>
#include <IGESGeom_CopiousData.hxx>
#include <gp_Trsf.hxx>
#include <gp_Ax3.hxx>
#include <gp_Ax2.hxx>
#include <gp_Ax1.hxx>
#include <IGESGeom_TransformationMatrix.hxx>
#include <TColgp_HSequenceOfXYZ.hxx>
#include <IGESConvGeom_GeomBuilder.hxx>

void bind_IGESConvGeom_GeomBuilder(py::module &mod){

py::class_<IGESConvGeom_GeomBuilder, std::unique_ptr<IGESConvGeom_GeomBuilder, Deleter<IGESConvGeom_GeomBuilder>>> cls_IGESConvGeom_GeomBuilder(mod, "IGESConvGeom_GeomBuilder", "This class provides some useful basic tools to build IGESGeom curves, especially : define a curve in a plane in 3D space (ex. Circular or Conic arc, or Copious Data defined in 2D) make a CopiousData from a list of points/vectors");

// Constructors
cls_IGESConvGeom_GeomBuilder.def(py::init<>());

// Fields

// Methods
// cls_IGESConvGeom_GeomBuilder.def_static("operator new_", (void * (*)(size_t)) &IGESConvGeom_GeomBuilder::operator new, "None", py::arg("theSize"));
// cls_IGESConvGeom_GeomBuilder.def_static("operator delete_", (void (*)(void *)) &IGESConvGeom_GeomBuilder::operator delete, "None", py::arg("theAddress"));
// cls_IGESConvGeom_GeomBuilder.def_static("operator new[]_", (void * (*)(size_t)) &IGESConvGeom_GeomBuilder::operator new[], "None", py::arg("theSize"));
// cls_IGESConvGeom_GeomBuilder.def_static("operator delete[]_", (void (*)(void *)) &IGESConvGeom_GeomBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_IGESConvGeom_GeomBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &IGESConvGeom_GeomBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESConvGeom_GeomBuilder.def_static("operator delete_", (void (*)(void *, void *)) &IGESConvGeom_GeomBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESConvGeom_GeomBuilder.def("Clear", (void (IGESConvGeom_GeomBuilder::*)()) &IGESConvGeom_GeomBuilder::Clear, "Clears list of Points/Vectors and data about Transformation");
cls_IGESConvGeom_GeomBuilder.def("AddXY", (void (IGESConvGeom_GeomBuilder::*)(const gp_XY &)) &IGESConvGeom_GeomBuilder::AddXY, "Adds a XY (Z=0) to the list of points", py::arg("val"));
cls_IGESConvGeom_GeomBuilder.def("AddXYZ", (void (IGESConvGeom_GeomBuilder::*)(const gp_XYZ &)) &IGESConvGeom_GeomBuilder::AddXYZ, "Adds a XYZ to the list of points", py::arg("val"));
cls_IGESConvGeom_GeomBuilder.def("AddVec", (void (IGESConvGeom_GeomBuilder::*)(const gp_XYZ &)) &IGESConvGeom_GeomBuilder::AddVec, "Adds a Vector part to the list of points. It will be used for CopiousData, datatype=3, only. AddXY and AddXYZ consider a null vector part (0,0,0) AddVec adds to the last added XY or XYZ", py::arg("val"));
cls_IGESConvGeom_GeomBuilder.def("NbPoints", (Standard_Integer (IGESConvGeom_GeomBuilder::*)() const) &IGESConvGeom_GeomBuilder::NbPoints, "Returns the count of already recorded points");
cls_IGESConvGeom_GeomBuilder.def("Point", (gp_XYZ (IGESConvGeom_GeomBuilder::*)(const Standard_Integer) const) &IGESConvGeom_GeomBuilder::Point, "Returns a point given its rank (if added as XY, Z will be 0)", py::arg("num"));
cls_IGESConvGeom_GeomBuilder.def("MakeCopiousData", [](IGESConvGeom_GeomBuilder &self, const Standard_Integer a0) -> opencascade::handle<IGESGeom_CopiousData> { return self.MakeCopiousData(a0); });
cls_IGESConvGeom_GeomBuilder.def("MakeCopiousData", (opencascade::handle<IGESGeom_CopiousData> (IGESConvGeom_GeomBuilder::*)(const Standard_Integer, const Standard_Boolean) const) &IGESConvGeom_GeomBuilder::MakeCopiousData, "Makes a CopiousData with the list of recorded Points/Vectors according to <datatype>, which must be 1,2 or 3 If <polyline> is given True, the CopiousData is coded as a Polyline, but <datatype> must not be 3 <datatype> = 1 : Common Z is computed as average of all Z <datatype> = 1 or 2 : Vectors are ignored", py::arg("datatype"), py::arg("polyline"));
cls_IGESConvGeom_GeomBuilder.def("Position", (gp_Trsf (IGESConvGeom_GeomBuilder::*)() const) &IGESConvGeom_GeomBuilder::Position, "Returns the Position in which the method EvalXYZ will evaluate a XYZ. It can be regarded as defining a local system. It is initially set to Identity");
cls_IGESConvGeom_GeomBuilder.def("SetPosition", (void (IGESConvGeom_GeomBuilder::*)(const gp_Trsf &)) &IGESConvGeom_GeomBuilder::SetPosition, "Sets final position from an already defined Trsf", py::arg("pos"));
cls_IGESConvGeom_GeomBuilder.def("SetPosition", (void (IGESConvGeom_GeomBuilder::*)(const gp_Ax3 &)) &IGESConvGeom_GeomBuilder::SetPosition, "Sets final position from an Ax3", py::arg("pos"));
cls_IGESConvGeom_GeomBuilder.def("SetPosition", (void (IGESConvGeom_GeomBuilder::*)(const gp_Ax2 &)) &IGESConvGeom_GeomBuilder::SetPosition, "Sets final position from an Ax2", py::arg("pos"));
cls_IGESConvGeom_GeomBuilder.def("SetPosition", (void (IGESConvGeom_GeomBuilder::*)(const gp_Ax1 &)) &IGESConvGeom_GeomBuilder::SetPosition, "Sets final position from an Ax1 (this means that origin point and Z-axis are defined, the other axes are defined arbitrarily)", py::arg("pos"));
cls_IGESConvGeom_GeomBuilder.def("IsIdentity", (Standard_Boolean (IGESConvGeom_GeomBuilder::*)() const) &IGESConvGeom_GeomBuilder::IsIdentity, "Returns True if the Position is Identity");
cls_IGESConvGeom_GeomBuilder.def("IsTranslation", (Standard_Boolean (IGESConvGeom_GeomBuilder::*)() const) &IGESConvGeom_GeomBuilder::IsTranslation, "Returns True if the Position is a Translation only Remark : Identity and ZOnly will answer True");
cls_IGESConvGeom_GeomBuilder.def("IsZOnly", (Standard_Boolean (IGESConvGeom_GeomBuilder::*)() const) &IGESConvGeom_GeomBuilder::IsZOnly, "Returns True if the Position corresponds to a Z-Displacement, i.e. is a Translation only, and only on Z Remark : Identity will answer True");
cls_IGESConvGeom_GeomBuilder.def("EvalXYZ", [](IGESConvGeom_GeomBuilder &self, const gp_XYZ & val, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.EvalXYZ(val, X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Evaluates a XYZ value in the Position already defined. Returns the transformed coordinates. For a 2D definition, X,Y will then be used to define a XY and Z will be regarded as a Z Displacement (can be ignored)", py::arg("val"), py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_IGESConvGeom_GeomBuilder.def("MakeTransformation", [](IGESConvGeom_GeomBuilder &self) -> opencascade::handle<IGESGeom_TransformationMatrix> { return self.MakeTransformation(); });
cls_IGESConvGeom_GeomBuilder.def("MakeTransformation", (opencascade::handle<IGESGeom_TransformationMatrix> (IGESConvGeom_GeomBuilder::*)(const Standard_Real) const) &IGESConvGeom_GeomBuilder::MakeTransformation, "Returns the IGES Transformation which corresponds to the Position. Even if it is an Identity : IsIdentity should be tested first. <unit> is the unit value in which the model is created : it is used to convert translation part", py::arg("unit"));

// Enums

}