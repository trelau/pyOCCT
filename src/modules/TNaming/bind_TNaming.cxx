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
#include <TDF_Label.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_NamedShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_HArray1OfShape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Shell.hxx>
#include <TDF_IDList.hxx>
#include <Standard_OStream.hxx>
#include <TNaming_Evolution.hxx>
#include <TNaming_NameType.hxx>
#include <TNaming_CopyShape.hxx>
#include <TNaming_TranslateTool.hxx>
#include <TNaming_Translator.hxx>
#include <TNaming_UsedShapes.hxx>
#include <TNaming_Builder.hxx>
#include <TNaming_Tool.hxx>
#include <TNaming_Iterator.hxx>
#include <TNaming_NewShapeIterator.hxx>
#include <TNaming_OldShapeIterator.hxx>
#include <TNaming_SameShapeIterator.hxx>
#include <TNaming_Name.hxx>
#include <TNaming_Naming.hxx>
#include <TNaming_Selector.hxx>
#include <TNaming_DeltaOnRemoval.hxx>
#include <TNaming_DeltaOnModification.hxx>
#include <TNaming_RefShape.hxx>
#include <TNaming_Scope.hxx>
#include <TNaming_Identifier.hxx>
#include <TNaming_Localizer.hxx>
#include <TNaming_ShapesSet.hxx>
#include <TNaming_IteratorOnShapesSet.hxx>
#include <TNaming_NamingTool.hxx>
#include <TNaming.hxx>

void bind_TNaming(py::module &mod){

py::class_<TNaming, std::unique_ptr<TNaming, Deleter<TNaming>>> cls_TNaming(mod, "TNaming", "A topological attribute can be seen as a hook into the topological structure. To this hook, data can be attached and references defined. It is used for keeping and access to topological objects and their evolution. All topological objects are stored in the one user-protected TNaming_UsedShapes attribute at the root label of the data framework. This attribute contains map with all topological shapes, used in this document. To all other labels TNaming_NamedShape attribute can be added. This attribute contains references (hooks) to shapes from the TNaming_UsedShapes attribute and evolution of these shapes. TNaming_NamedShape attribute contains a set of pairs of hooks: old shape and new shape (see the figure below). It allows not only get the topological shapes by the labels, but also trace evolution of the shapes and correctly resolve dependent shapes by the changed one. If shape is just-created, then the old shape for accorded named shape is an empty shape. If a shape is deleted, then the new shape in this named shape is empty. Different algorithms may dispose sub-shapes of the result shape at the individual label depending on necessity: - If a sub-shape must have some extra attributes (material of each face or color of each edge). In this case a specific sub-shape is placed to the separate label (usually, sub-label of the result shape label) with all attributes of this sub-shape. - If topological naming is needed, a necessary and sufficient (for selected sub-shapes identification) set of sub-shapes is placed to the child labels of the result shape label. As usual, as far as basic solids and closed shells are concerned, all faces of the shape are disposed. Edges and vertices sub-shapes can be identified as intersection of contiguous faces. Modified/generated shapes may be placed to one named shape and identified as this named shape and source named shape that also can be identified with used algorithms. TNaming_NamedShape may contain a few pairs of hooks with the same evolution. In this case topology shape, which belongs to the named shape, is a compound of new shapes. The data model contains both the topology and the hooks, and functions handle both topological entities and hooks. Consider the case of a box function, which creates a solid with six faces and six hooks. Each hook is attached to a face. If you want, you can also have this function create hooks for edges and vertices as well as for faces. For the sake of simplicity though, let's limit the example. Not all functions can define explicit hooks for all topological entities they create, but all topological entities can be turned into hooks when necessary. This is where topological naming is necessary.");

// Constructors

// Fields

// Methods
// cls_TNaming.def_static("operator new_", (void * (*)(size_t)) &TNaming::operator new, "None", py::arg("theSize"));
// cls_TNaming.def_static("operator delete_", (void (*)(void *)) &TNaming::operator delete, "None", py::arg("theAddress"));
// cls_TNaming.def_static("operator new[]_", (void * (*)(size_t)) &TNaming::operator new[], "None", py::arg("theSize"));
// cls_TNaming.def_static("operator delete[]_", (void (*)(void *)) &TNaming::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming.def_static("operator delete_", (void (*)(void *, void *)) &TNaming::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming.def_static("Substitute_", (void (*)(const TDF_Label &, const TDF_Label &, TopTools_DataMapOfShapeShape &)) &TNaming::Substitute, "Subtituter les shapes sur les structures de source vers cible", py::arg("labelsource"), py::arg("labelcible"), py::arg("mapOldNew"));
cls_TNaming.def_static("Update_", (void (*)(const TDF_Label &, TopTools_DataMapOfShapeShape &)) &TNaming::Update, "Mise a jour des shapes du label et de ses fils en tenant compte des substitutions decrite par mapOldNew.", py::arg("label"), py::arg("mapOldNew"));
cls_TNaming.def_static("Displace_", [](const TDF_Label & a0, const TopLoc_Location & a1) -> void { return TNaming::Displace(a0, a1); });
cls_TNaming.def_static("Displace_", (void (*)(const TDF_Label &, const TopLoc_Location &, const Standard_Boolean)) &TNaming::Displace, "Application de la Location sur les shapes du label et de ses sous labels.", py::arg("label"), py::arg("aLocation"), py::arg("WithOld"));
cls_TNaming.def_static("ChangeShapes_", (void (*)(const TDF_Label &, TopTools_DataMapOfShapeShape &)) &TNaming::ChangeShapes, "Remplace les shapes du label et des sous-labels par des copies.", py::arg("label"), py::arg("M"));
cls_TNaming.def_static("Transform_", (void (*)(const TDF_Label &, const gp_Trsf &)) &TNaming::Transform, "Application de la transformation sur les shapes du label et de ses sous labels. Warning: le remplacement du shape est fait dans tous les attributs qui le contiennent meme si ceux ci ne sont pas associees a des sous-labels de <Label>.", py::arg("label"), py::arg("aTransformation"));
cls_TNaming.def_static("Replicate_", (void (*)(const opencascade::handle<TNaming_NamedShape> &, const gp_Trsf &, const TDF_Label &)) &TNaming::Replicate, "Replicates the named shape with the transformation <T> on the label <L> (and sub-labels if necessary) (TNaming_GENERATED is set)", py::arg("NS"), py::arg("T"), py::arg("L"));
cls_TNaming.def_static("Replicate_", (void (*)(const TopoDS_Shape &, const gp_Trsf &, const TDF_Label &)) &TNaming::Replicate, "Replicates the shape with the transformation <T> on the label <L> (and sub-labels if necessary) (TNaming_GENERATED is set)", py::arg("SH"), py::arg("T"), py::arg("L"));
cls_TNaming.def_static("MakeShape_", (TopoDS_Shape (*)(const TopTools_MapOfShape &)) &TNaming::MakeShape, "Builds shape from map content", py::arg("MS"));
cls_TNaming.def_static("FindUniqueContext_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TNaming::FindUniqueContext, "Find unique context of shape <S>", py::arg("S"), py::arg("Context"));
cls_TNaming.def_static("FindUniqueContextSet_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TopoDS_Shape &, opencascade::handle<TopTools_HArray1OfShape> &)) &TNaming::FindUniqueContextSet, "Find unique context of shape <S>,which is pure concatenation of atomic shapes (Compound). The result is concatenation of single contexts", py::arg("S"), py::arg("Context"), py::arg("Arr"));
cls_TNaming.def_static("SubstituteSShape_", (Standard_Boolean (*)(const TDF_Label &, const TopoDS_Shape &, TopoDS_Shape &)) &TNaming::SubstituteSShape, "Subtitutes shape in source structure", py::arg("accesslabel"), py::arg("From"), py::arg("To"));
cls_TNaming.def_static("OuterWire_", (Standard_Boolean (*)(const TopoDS_Face &, TopoDS_Wire &)) &TNaming::OuterWire, "Returns True if outer wire is found and the found wire in <theWire>.", py::arg("theFace"), py::arg("theWire"));
cls_TNaming.def_static("OuterShell_", (Standard_Boolean (*)(const TopoDS_Solid &, TopoDS_Shell &)) &TNaming::OuterShell, "Returns True if outer Shell is found and the found shell in <theShell>. Print of TNaming enumeration =============================", py::arg("theSolid"), py::arg("theShell"));
cls_TNaming.def_static("IDList_", (void (*)(TDF_IDList &)) &TNaming::IDList, "Appends to <anIDList> the list of the attributes IDs of this package. CAUTION: <anIDList> is NOT cleared before use.", py::arg("anIDList"));
cls_TNaming.def_static("Print_", (Standard_OStream & (*)(const TNaming_Evolution, Standard_OStream &)) &TNaming::Print, "Prints the evolution <EVOL> as a String on the Stream <S> and returns <S>.", py::arg("EVOL"), py::arg("S"));
cls_TNaming.def_static("Print_", (Standard_OStream & (*)(const TNaming_NameType, Standard_OStream &)) &TNaming::Print, "Prints the name of name type <NAME> as a String on the Stream <S> and returns <S>.", py::arg("NAME"), py::arg("S"));
cls_TNaming.def_static("Print_", (Standard_OStream & (*)(const TDF_Label &, Standard_OStream &)) &TNaming::Print, "Prints the content of UsedShapes private attribute as a String Table on the Stream <S> and returns <S>.", py::arg("ACCESS"), py::arg("S"));

// Enums

}