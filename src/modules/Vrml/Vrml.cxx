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

void bind_Vrml_VertexOrdering(py::module &);
void bind_Vrml_ShapeType(py::module &);
void bind_Vrml_FaceType(py::module &);
void bind_Vrml_AsciiTextJustification(py::module &);
void bind_Vrml_ConeParts(py::module &);
void bind_Vrml_CylinderParts(py::module &);
void bind_Vrml_FontStyleFamily(py::module &);
void bind_Vrml_FontStyleStyle(py::module &);
void bind_Vrml_MaterialBindingAndNormalBinding(py::module &);
void bind_Vrml_SeparatorRenderCulling(py::module &);
void bind_Vrml_SFImageNumber(py::module &);
void bind_Vrml_Texture2Wrap(py::module &);
void bind_Vrml_WWWAnchorMap(py::module &);
void bind_Vrml(py::module &);
void bind_Vrml_SFRotation(py::module &);
void bind_Vrml_PerspectiveCamera(py::module &);
void bind_Vrml_OrthographicCamera(py::module &);
void bind_Vrml_DirectionalLight(py::module &);
void bind_Vrml_PointLight(py::module &);
void bind_Vrml_SpotLight(py::module &);
void bind_Vrml_MatrixTransform(py::module &);
void bind_Vrml_ShapeHints(py::module &);
void bind_Vrml_AsciiText(py::module &);
void bind_Vrml_Cone(py::module &);
void bind_Vrml_Coordinate3(py::module &);
void bind_Vrml_Cube(py::module &);
void bind_Vrml_Cylinder(py::module &);
void bind_Vrml_FontStyle(py::module &);
void bind_Vrml_Group(py::module &);
void bind_Vrml_IndexedFaceSet(py::module &);
void bind_Vrml_IndexedLineSet(py::module &);
void bind_Vrml_Info(py::module &);
void bind_Vrml_Instancing(py::module &);
void bind_Vrml_LOD(py::module &);
void bind_Vrml_Material(py::module &);
void bind_Vrml_MaterialBinding(py::module &);
void bind_Vrml_Normal(py::module &);
void bind_Vrml_NormalBinding(py::module &);
void bind_Vrml_PointSet(py::module &);
void bind_Vrml_Rotation(py::module &);
void bind_Vrml_Scale(py::module &);
void bind_Vrml_Separator(py::module &);
void bind_Vrml_SFImage(py::module &);
void bind_Vrml_Sphere(py::module &);
void bind_Vrml_Switch(py::module &);
void bind_Vrml_Texture2(py::module &);
void bind_Vrml_Texture2Transform(py::module &);
void bind_Vrml_TextureCoordinate2(py::module &);
void bind_Vrml_Transform(py::module &);
void bind_Vrml_TransformSeparator(py::module &);
void bind_Vrml_Translation(py::module &);
void bind_Vrml_WWWAnchor(py::module &);
void bind_Vrml_WWWInline(py::module &);

PYBIND11_MODULE(Vrml, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TCollection");

bind_Vrml_VertexOrdering(mod);
bind_Vrml_ShapeType(mod);
bind_Vrml_FaceType(mod);
bind_Vrml_AsciiTextJustification(mod);
bind_Vrml_ConeParts(mod);
bind_Vrml_CylinderParts(mod);
bind_Vrml_FontStyleFamily(mod);
bind_Vrml_FontStyleStyle(mod);
bind_Vrml_MaterialBindingAndNormalBinding(mod);
bind_Vrml_SeparatorRenderCulling(mod);
bind_Vrml_SFImageNumber(mod);
bind_Vrml_Texture2Wrap(mod);
bind_Vrml_WWWAnchorMap(mod);
bind_Vrml(mod);
bind_Vrml_SFRotation(mod);
bind_Vrml_PerspectiveCamera(mod);
bind_Vrml_OrthographicCamera(mod);
bind_Vrml_DirectionalLight(mod);
bind_Vrml_PointLight(mod);
bind_Vrml_SpotLight(mod);
bind_Vrml_MatrixTransform(mod);
bind_Vrml_ShapeHints(mod);
bind_Vrml_AsciiText(mod);
bind_Vrml_Cone(mod);
bind_Vrml_Coordinate3(mod);
bind_Vrml_Cube(mod);
bind_Vrml_Cylinder(mod);
bind_Vrml_FontStyle(mod);
bind_Vrml_Group(mod);
bind_Vrml_IndexedFaceSet(mod);
bind_Vrml_IndexedLineSet(mod);
bind_Vrml_Info(mod);
bind_Vrml_Instancing(mod);
bind_Vrml_LOD(mod);
bind_Vrml_Material(mod);
bind_Vrml_MaterialBinding(mod);
bind_Vrml_Normal(mod);
bind_Vrml_NormalBinding(mod);
bind_Vrml_PointSet(mod);
bind_Vrml_Rotation(mod);
bind_Vrml_Scale(mod);
bind_Vrml_Separator(mod);
bind_Vrml_SFImage(mod);
bind_Vrml_Sphere(mod);
bind_Vrml_Switch(mod);
bind_Vrml_Texture2(mod);
bind_Vrml_Texture2Transform(mod);
bind_Vrml_TextureCoordinate2(mod);
bind_Vrml_Transform(mod);
bind_Vrml_TransformSeparator(mod);
bind_Vrml_Translation(mod);
bind_Vrml_WWWAnchor(mod);
bind_Vrml_WWWInline(mod);

}
