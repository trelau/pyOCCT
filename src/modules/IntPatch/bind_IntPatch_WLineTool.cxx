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
#include <Standard_Handle.hxx>
#include <IntPatch_WLine.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <IntPatch_SequenceOfPoint.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box2d.hxx>
#include <IntPatch_WLineTool.hxx>

void bind_IntPatch_WLineTool(py::module &mod){

py::class_<IntPatch_WLineTool> cls_IntPatch_WLineTool(mod, "IntPatch_WLineTool", "IntPatch_WLineTool provides set of static methods related to walking lines.");

// Constructors

// Fields

// Methods
// cls_IntPatch_WLineTool.def_static("operator new_", (void * (*)(size_t)) &IntPatch_WLineTool::operator new, "None", py::arg("theSize"));
// cls_IntPatch_WLineTool.def_static("operator delete_", (void (*)(void *)) &IntPatch_WLineTool::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_WLineTool.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_WLineTool::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_WLineTool.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_WLineTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_WLineTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_WLineTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_WLineTool.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_WLineTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_WLineTool.def_static("ComputePurgedWLine_", (opencascade::handle<IntPatch_WLine> (*)(const opencascade::handle<IntPatch_WLine> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_TopolTool> &)) &IntPatch_WLineTool::ComputePurgedWLine, "I Removes equal points (leave one of equal points) from theWLine and recompute vertex parameters.", py::arg("theWLine"), py::arg("theS1"), py::arg("theS2"), py::arg("theDom1"), py::arg("theDom2"));
cls_IntPatch_WLineTool.def_static("JoinWLines_", (void (*)(IntPatch_SequenceOfLine &, IntPatch_SequenceOfPoint &, opencascade::handle<Adaptor3d_HSurface>, opencascade::handle<Adaptor3d_HSurface>, const Standard_Real)) &IntPatch_WLineTool::JoinWLines, "Joins all WLines from theSlin to one if it is possible and records the result into theSlin again. Lines will be kept to be splitted if: a) they are separated (has no common points); b) resulted line (after joining) go through seam-edges or surface boundaries.", py::arg("theSlin"), py::arg("theSPnt"), py::arg("theS1"), py::arg("theS2"), py::arg("theTol3D"));
cls_IntPatch_WLineTool.def_static("ExtendTwoWLines_", (void (*)(IntPatch_SequenceOfLine &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real *const, const Bnd_Box2d &, const Bnd_Box2d &)) &IntPatch_WLineTool::ExtendTwoWLines, "Extends every line from theSlin (if it is possible) to be started/finished in strictly determined point (in the place of joint of two lines). As result, some gaps between two lines will vanish. The Walking lines are supposed (algorithm will do nothing for not-Walking line) to be computed as a result of intersection. Both theS1 and theS2 must be quadrics. Other cases are not supported. theArrPeriods must be filled as follows (every value must not be negative; if the surface is not periodic the period must be equal to 0.0 strictly): {<U-period of 1st surface>, <V-period of 1st surface>, <U-period of 2nd surface>, <V-period of 2nd surface>}.", py::arg("theSlin"), py::arg("theS1"), py::arg("theS2"), py::arg("theToler3D"), py::arg("theArrPeriods"), py::arg("theBoxS1"), py::arg("theBoxS2"));

// Enums

}