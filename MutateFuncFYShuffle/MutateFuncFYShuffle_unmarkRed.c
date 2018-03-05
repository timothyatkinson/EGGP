#include "MutateFuncFYShuffle_unmarkRed.h"

#include "MutateFuncFYShuffle.h"

static bool match_n0(Morphism *morphism);

bool matchMutateFuncFYShuffle_unmarkRed(Morphism *morphism)
{
   if(1 > MutateFuncFYShuffle_host->number_of_nodes || 0 > MutateFuncFYShuffle_host->number_of_edges) return false;
   if(match_n0(morphism)) return true;
   else
   {
      initialiseMorphism(morphism, MutateFuncFYShuffle_host);
      return false;
   }
}

static bool match_n0(Morphism *morphism)
{
   int host_index;
   for(host_index = 0; host_index < MutateFuncFYShuffle_host->nodes.size; host_index++)
   {
      Node *host_node = getNode(MutateFuncFYShuffle_host, host_index);
      if(host_node == NULL || host_node->index == -1) continue;
      if(host_node->matched) continue;
      if(host_node->label.mark != 1) continue;
      if(host_node->indegree < 0 || host_node->outdegree < 0 ||
         ((host_node->outdegree + host_node->indegree - 0 - 0 - 0) < 0)) continue;

      HostLabel label = host_node->label;
      bool match = false;
      /* Label Matching */
      int new_assignments = 0;
      /* Match list variable 0 against the whole host list. */
      int result = -1;
      if(label.length == 1)
      {
         if(label.list->first->atom.type == 'i')
            result = addIntegerAssignment(morphism, 0, label.list->first->atom.num);
         else result = addStringAssignment(morphism, 0, label.list->first->atom.str);
      }
      else result = addListAssignment(morphism, 0, label.list);
      if(result >= 0)
      {
         new_assignments += result;
         match = true;
      }
      if(match)
      {
         addNodeMap(morphism, 0, host_node->index, new_assignments);
         host_node->matched = true;
         /* All items matched! */
            return true;
      }
      else removeAssignments(morphism, new_assignments);
   }
   return false;
}

void applyMutateFuncFYShuffle_unmarkRed(Morphism *morphism, bool record_changes)
{
   int host_node_index = lookupNode(morphism, 0);
   HostLabel label_n0 = getNodeLabel(MutateFuncFYShuffle_host, host_node_index);
   if(record_changes) pushRemarkedNode(host_node_index, label_n0.mark);
   changeNodeMark(MutateFuncFYShuffle_host, host_node_index, 0);

   /* Reset the morphism. */
   initialiseMorphism(morphism, MutateFuncFYShuffle_host);
}

static bool fillpot_n0(MorphismPot *pot, Morphism *morphism);

bool fillpotMutateFuncFYShuffle_unmarkRed(MorphismPot *pot, Morphism *morphism)
{
   if(1 > MutateFuncFYShuffle_host->number_of_nodes || 0 > MutateFuncFYShuffle_host->number_of_edges) return false;
   int oldPotsize = potSize(pot);
   morphism->weight = 0.000000;
   fillpot_n0(pot, morphism);
   if(potSize(pot) > oldPotsize){
      initialiseMorphism(morphism, MutateFuncFYShuffle_host);
      return true;
   }
   else
   {
      initialiseMorphism(morphism, MutateFuncFYShuffle_host);
      return false;
   }
}

static bool fillpot_n0(MorphismPot *pot, Morphism *morphism)
{
   int host_index;
   for(host_index = 0; host_index < MutateFuncFYShuffle_host->nodes.size; host_index++)
   {
      Node *host_node = getNode(MutateFuncFYShuffle_host, host_index);
      if(host_node == NULL || host_node->index == -1) continue;
      if(host_node->matched) continue;
      if(host_node->label.mark != 1) continue;
      if(host_node->indegree < 0 || host_node->outdegree < 0 ||
         ((host_node->outdegree + host_node->indegree - 0 - 0 - 0) < 0)) continue;

      HostLabel label = host_node->label;
      bool match = false;
      /* Label Matching */
      int new_assignments = 0;
      /* Match list variable 0 against the whole host list. */
      int result = -1;
      if(label.length == 1)
      {
         if(label.list->first->atom.type == 'i')
            result = addIntegerAssignment(morphism, 0, label.list->first->atom.num);
         else result = addStringAssignment(morphism, 0, label.list->first->atom.str);
      }
      else result = addListAssignment(morphism, 0, label.list);
      if(result >= 0)
      {
         new_assignments += result;
         match = true;
      }
      if(match)
      {
         addNodeMap(morphism, 0, host_node->index, new_assignments);
         host_node->matched = true;
         /* All items matched! */
            putMorphism(pot, morphism, "MutateFuncFYShuffle_unmarkRed", MutateFuncFYShuffle_host);
            removeNodeMap(morphism, 0);
            host_node->matched = false;
      }
      else removeAssignments(morphism, new_assignments);
   }
   return false;
}

