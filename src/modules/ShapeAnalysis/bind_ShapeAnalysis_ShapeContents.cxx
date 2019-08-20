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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <ShapeAnalysis_ShapeContents.hxx>

void bind_ShapeAnalysis_ShapeContents(py::module &mod){

py::class_<ShapeAnalysis_ShapeContents, std::unique_ptr<ShapeAnalysis_ShapeContents>> cls_ShapeAnalysis_ShapeContents(mod, "ShapeAnalysis_ShapeContents", "Dumps shape contents");

// Constructors
cls_ShapeAnalysis_ShapeContents.def(py::init<>());

// Fields

// Methods
// cls_ShapeAnalysis_ShapeContents.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_ShapeContents::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_ShapeContents.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_ShapeContents::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_ShapeContents.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_ShapeContents::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_ShapeContents.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_ShapeContents::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_ShapeContents.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_ShapeContents::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_ShapeContents.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_ShapeContents::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_ShapeContents.def("Clear", (void (ShapeAnalysis_ShapeContents::*)()) &ShapeAnalysis_ShapeContents::Clear, "Clears all accumulated statictics");
cls_ShapeAnalysis_ShapeContents.def("ClearFlags", (void (ShapeAnalysis_ShapeContents::*)()) &ShapeAnalysis_ShapeContents::ClearFlags, "Clears all flags");
cls_ShapeAnalysis_ShapeContents.def("Perform", (void (ShapeAnalysis_ShapeContents::*)(const TopoDS_Shape &)) &ShapeAnalysis_ShapeContents::Perform, "Counts quantities of sun-shapes in shape and stores sub-shapes according to flags", py::arg("shape"));
cls_ShapeAnalysis_ShapeContents.def("ModifyBigSplineMode", (Standard_Boolean & (ShapeAnalysis_ShapeContents::*)()) &ShapeAnalysis_ShapeContents::ModifyBigSplineMode, "Returns (modifiable) the flag which defines whether to store faces with edges if its 3D curves has more than 8192 poles.");
cls_ShapeAnalysis_ShapeContents.def("ModifyIndirectMode", (Standard_Boolean & (ShapeAnalysis_ShapeContents::*)()) &ShapeAnalysis_ShapeContents::ModifyIndirectMode, "Returns (modifiable) the flag which defines whether to store faces on indirect surfaces");
cls_ShapeAnalysis_ShapeContents.def("ModifyOffestSurfaceMode", (Standard_Boolean & (ShapeAnalysis_ShapeContents::*)()) &ShapeAnalysis_ShapeContents::ModifyOffestSurfaceMode, "Returns (modifiable) the flag which defines whether to store faces on offset surfaces.");
cls_ShapeAnalysis_ShapeContents.def("ModifyTrimmed3dMode", (Standard_Boolean & (ShapeAnalysis_ShapeContents::*)()) &ShapeAnalysis_ShapeContents::ModifyTrimmed3dMode, "Returns (modifiable) the flag which defines whether to store faces with edges if ist 3D curves are trimmed curves");
cls_ShapeAnalysis_ShapeContents.def("ModifyOffsetCurveMode", (Standard_Boolean & (ShapeAnalysis_ShapeContents::*)()) &ShapeAnalysis_ShapeContents::ModifyOffsetCurveMode, "Returns (modifiable) the flag which defines whether to store faces with edges if its 3D curves and pcurves are offest curves");
cls_ShapeAnalysis_ShapeContents.def("ModifyTrimmed2dMode", (Standard_Boolean & (ShapeAnalysis_ShapeContents::*)()) &ShapeAnalysis_ShapeContents::ModifyTrimmed2dMode, "Returns (modifiable) the flag which defines whether to store faces with edges if its pcurves are trimmed curves");
cls_ShapeAnalysis_ShapeContents.def("NbSolids", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbSolids, "None");
cls_ShapeAnalysis_ShapeContents.def("NbShells", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbShells, "None");
cls_ShapeAnalysis_ShapeContents.def("NbFaces", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbFaces, "None");
cls_ShapeAnalysis_ShapeContents.def("NbWires", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbWires, "None");
cls_ShapeAnalysis_ShapeContents.def("NbEdges", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbEdges, "None");
cls_ShapeAnalysis_ShapeContents.def("NbVertices", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbVertices, "None");
cls_ShapeAnalysis_ShapeContents.def("NbSolidsWithVoids", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbSolidsWithVoids, "None");
cls_ShapeAnalysis_ShapeContents.def("NbBigSplines", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbBigSplines, "None");
cls_ShapeAnalysis_ShapeContents.def("NbC0Surfaces", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbC0Surfaces, "None");
cls_ShapeAnalysis_ShapeContents.def("NbC0Curves", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbC0Curves, "None");
cls_ShapeAnalysis_ShapeContents.def("NbOffsetSurf", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbOffsetSurf, "None");
cls_ShapeAnalysis_ShapeContents.def("NbIndirectSurf", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbIndirectSurf, "None");
cls_ShapeAnalysis_ShapeContents.def("NbOffsetCurves", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbOffsetCurves, "None");
cls_ShapeAnalysis_ShapeContents.def("NbTrimmedCurve2d", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbTrimmedCurve2d, "None");
cls_ShapeAnalysis_ShapeContents.def("NbTrimmedCurve3d", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbTrimmedCurve3d, "None");
cls_ShapeAnalysis_ShapeContents.def("NbBSplibeSurf", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbBSplibeSurf, "None");
cls_ShapeAnalysis_ShapeContents.def("NbBezierSurf", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbBezierSurf, "None");
cls_ShapeAnalysis_ShapeContents.def("NbTrimSurf", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbTrimSurf, "None");
cls_ShapeAnalysis_ShapeContents.def("NbWireWitnSeam", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbWireWitnSeam, "None");
cls_ShapeAnalysis_ShapeContents.def("NbWireWithSevSeams", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbWireWithSevSeams, "None");
cls_ShapeAnalysis_ShapeContents.def("NbFaceWithSevWires", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbFaceWithSevWires, "None");
cls_ShapeAnalysis_ShapeContents.def("NbNoPCurve", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbNoPCurve, "None");
cls_ShapeAnalysis_ShapeContents.def("NbFreeFaces", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbFreeFaces, "None");
cls_ShapeAnalysis_ShapeContents.def("NbFreeWires", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbFreeWires, "None");
cls_ShapeAnalysis_ShapeContents.def("NbFreeEdges", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbFreeEdges, "None");
cls_ShapeAnalysis_ShapeContents.def("NbSharedSolids", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbSharedSolids, "None");
cls_ShapeAnalysis_ShapeContents.def("NbSharedShells", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbSharedShells, "None");
cls_ShapeAnalysis_ShapeContents.def("NbSharedFaces", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbSharedFaces, "None");
cls_ShapeAnalysis_ShapeContents.def("NbSharedWires", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbSharedWires, "None");
cls_ShapeAnalysis_ShapeContents.def("NbSharedFreeWires", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbSharedFreeWires, "None");
cls_ShapeAnalysis_ShapeContents.def("NbSharedFreeEdges", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbSharedFreeEdges, "None");
cls_ShapeAnalysis_ShapeContents.def("NbSharedEdges", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbSharedEdges, "None");
cls_ShapeAnalysis_ShapeContents.def("NbSharedVertices", (Standard_Integer (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::NbSharedVertices, "None");
cls_ShapeAnalysis_ShapeContents.def("BigSplineSec", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::BigSplineSec, "None");
cls_ShapeAnalysis_ShapeContents.def("IndirectSec", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::IndirectSec, "None");
cls_ShapeAnalysis_ShapeContents.def("OffsetSurfaceSec", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::OffsetSurfaceSec, "None");
cls_ShapeAnalysis_ShapeContents.def("Trimmed3dSec", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::Trimmed3dSec, "None");
cls_ShapeAnalysis_ShapeContents.def("OffsetCurveSec", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::OffsetCurveSec, "None");
cls_ShapeAnalysis_ShapeContents.def("Trimmed2dSec", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeAnalysis_ShapeContents::*)() const) &ShapeAnalysis_ShapeContents::Trimmed2dSec, "None");

// Enums

}