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
#include <ShapePersistent_Geom2d.hxx>
#include <StdObjMgt_SharedObject.hxx>
#include <ShapePersistent_Geom2d_Curve.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <ShapePersistent_HArray1.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <ShapePersistent_Geom.hxx>
#include <Geom2d_Line.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Ax22d.hxx>
#include <Geom2d_Circle.hxx>
#include <gp_Circ2d.hxx>
#include <Geom2d_Ellipse.hxx>
#include <gp_Elips2d.hxx>
#include <Geom2d_Hyperbola.hxx>
#include <gp_Hypr2d.hxx>
#include <Geom2d_Parabola.hxx>
#include <gp_Parab2d.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <Geom2d_OffsetCurve.hxx>

void bind_ShapePersistent_Geom2d_Curve(py::module &mod){

/*
py::class_<ShapePersistent_Geom2d_Curve, std::unique_ptr<ShapePersistent_Geom2d_Curve, Deleter<ShapePersistent_Geom2d_Curve>>> cls_ShapePersistent_Geom2d_Curve(mod, "ShapePersistent_Geom2d_Curve", "None");

// Constructors

// Fields

// Methods
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Line> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a line", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Circle> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a circle", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Ellipse> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a ellipse", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Hyperbola> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a hyperbola", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Parabola> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a parabola", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_BezierCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a Bezier curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_BSplineCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a BSpline curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_TrimmedCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a trimmed curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_OffsetCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for an offset curve", py::arg("theCurve"), py::arg("theMap"));

// Enums
*/

}